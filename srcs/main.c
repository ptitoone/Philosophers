/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:33:48 by akotzky           #+#    #+#             */
/*   Updated: 2021/11/08 15:12:33 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ribool	throw_error(char *err_msg)
{
	int	i;

	i = 0;
	while (err_msg[i])
		i++;
	write(2, "Error: ", 7);
	write(2, err_msg, i);
	write(2, "\n", 1);
	return (T_FALSE);
}

void	print_msg(t_count pos, char *msg, t_info *info)
{
	int	time;

	pthread_mutex_lock(&info->msg_lock);
	time = get_time() - info->st_time;
	if (time >= 0 && time < 500000 && info->philo_count > 0)
		printf("%i %i %s\n", time, pos, msg);
	pthread_mutex_unlock(&info->msg_lock);
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
	usleep(500);
	return (EXIT_SUCCESS);
}
