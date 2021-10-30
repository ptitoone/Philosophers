/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:33:48 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/30 17:05:19 by akotzky          ###   ########.fr       */
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
	if (info->status == 1 && info->philo_count > 0)
	{
		printf("%i %i %s\n",
			get_current_time_ms() - info->start_time, pos, msg);
	}
	else
		info->philo_count = 0;
	pthread_mutex_unlock(&info->msg_lock);
}

int	main(int ac, char **av)
{
	t_info		info;
	t_philo		*philo;
	pthread_t	death;
	int			i;

	if (!init(ac - 1, av + 1, &info, &philo))
		return (EXIT_FAILURE);
	i = info.philo_count;
	info.start_time = get_current_time_ms() - 1;
	while (i-- > 0)
	{
		pthread_create(&philo->life, NULL, life_cycle, (void *)philo);
		usleep(5000);
		pthread_detach(philo->life);
		philo = philo->next;
	}
	pthread_create(&death, NULL, death_cycle, philo);
	pthread_join(death, NULL);
	return (EXIT_SUCCESS);
}
