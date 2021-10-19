/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@42nice.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:46:17 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/19 17:34:47 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*lifecycle(void *philo)
{
	static t_info	*info;

	if (!info)
		info = philo;
	else
	{
		while (1)
		{
			print_msg(((t_philo *)philo)->pos, "takes a fork", info);	
			pthread_mutex_lock(&((t_philo *)philo)->fork);
			print_msg(((t_philo *)philo)->pos, "takes a fork", info);	
			pthread_mutex_lock(&((t_philo *)philo)->next->fork);
			print_msg(((t_philo *)philo)->pos, "is eating", info);
			usleep(info->time_to_eat * 1000);
			if ((get_current_time_ms(info) - ((t_philo *)philo)->time_last_meal)  >= info->time_to_die)
			{
				print_msg(((t_philo *)philo)->pos, "died", info);
				ph_exit(0, 0);
			}
			((t_philo *)philo)->time_last_meal = get_current_time_ms(info);
			pthread_mutex_unlock(&((t_philo *)philo)->fork);
			pthread_mutex_unlock(&((t_philo *)philo)->next->fork);
			print_msg(((t_philo *)philo)->pos, "is spleeping", info);
			usleep(info->time_to_sleep * 1000);
			print_msg(((t_philo *)philo)->pos, "is thinking", info);
		}
	}
	return (NULL);
}

void	print_msg(t_pos pos, char *msg, t_info *info)
{
	pthread_mutex_lock(&info->msg_lock);
		printf("%i ms %i %s\n", get_current_time_ms(info), pos, msg); 
	pthread_mutex_unlock(&info->msg_lock);
}

