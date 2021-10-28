/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:33:48 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/28 13:27:08 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ribool	throw_error(char *err_msg)
{
	printf("Error: %s\n", err_msg);
	return (T_FALSE);
}

void	print_msg(t_count pos, char *msg, t_info *info)
{
	pthread_mutex_lock(&info->msg_lock);
	if (info->philo_count > 0 || info->status == 1)
		printf("%i ms %i %s\n",
			get_current_time_ms() - info->start_time, pos, msg);
	if (ft_strcmp(msg, "died"))
		pthread_mutex_unlock(&info->msg_lock);
	else
		info->philo_count = 0;
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
	info.start_time = get_current_time_ms();
	while (i-- > 0)
	{
		pthread_create(&philo->life, NULL, life_cycle, (void *)philo);
		usleep(50);
		pthread_detach(philo->life);
		philo = philo->next;
	}
	pthread_create(&death, NULL, death_cycle, philo);
	pthread_join(death, NULL);
	return (EXIT_SUCCESS);
}
