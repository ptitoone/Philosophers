/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:33:48 by akotzky           #+#    #+#             */
/*   Updated: 2021/11/01 16:37:04 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_ribool	throw_error(char *err_msg)
{
	write(2, "Error: ", 7);
	write(2, err_msg, ft_strlen(err_msg));
	write(2, "\n", 1);
	return (T_FALSE);
}

void	print_msg(t_count pos, char *msg, t_info *info)
{
	pthread_mutex_lock(&info->msg_lock);
	if (info->philo_count > 0)
	{
		printf("%i %i %s\n",
			(get_current_time_ms() - info->start_time), pos, msg);
	}
	else
		info->philo_count = 0;
	pthread_mutex_unlock(&info->msg_lock);
}

void	*spawn_cycle(void *philo)
{
	static t_info	*info;
	pthread_t		death;
	int				i;

	if (!info)
		info = philo;
	else
	{
		i = info->philo_count;
		info->start_time = get_current_time_ms();
		while (i-- > 0)
		{
			pthread_create(&((t_philo *)philo)->life, NULL, life_cycle, philo);
			usleep(200);
			philo = ((t_philo *)philo)->next;
		}
		pthread_create(&death, NULL, death_cycle, philo);
		while (info->philo_count > 0)
			;
		pthread_mutex_lock(&info->msg_lock);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_info		info;
	t_philo		*philo;
	pthread_t	spawn;

	if (!init(ac - 1, av + 1, &info, &philo))
		return (EXIT_FAILURE);
	pthread_create(&spawn, NULL, spawn_cycle, (void *)philo);
	pthread_join(spawn, NULL);
	return (EXIT_SUCCESS);
}
