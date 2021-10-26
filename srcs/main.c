/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:33:48 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/26 21:48:22 by akotzky          ###   ########.fr       */
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
	printf("%i ms %i %s\n", get_current_time_ms() - info->start_time, pos, msg);
	if (ft_strcmp(msg, "died"))
		pthread_mutex_unlock(&info->msg_lock);
	else
		info->philo_count = 0;
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
