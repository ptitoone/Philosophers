/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@42nice.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:46:17 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/18 13:21:04 by akotzky          ###   ########.fr       */
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
			pthread_mutex_lock(&((t_philo *)philo)->fork);
			pthread_mutex_lock(&((t_philo *)philo)->next->fork);
			print_msg(((t_philo *)philo)->pos, FORK, info);	
			print_msg(((t_philo *)philo)->pos, EAT, info);
			usleep(info->time_to_eat * 1000);
			pthread_mutex_unlock(&((t_philo *)philo)->fork);
			pthread_mutex_unlock(&((t_philo *)philo)->next->fork);
			print_msg(((t_philo *)philo)->pos, SLEEP, info);
			usleep(info->time_to_sleep * 1000);
			print_msg(((t_philo *)philo)->pos, THINK, info);
		}
	}
	return (NULL);
}

void	print_msg(t_pos pos, int msg, t_info *info)
{
	pthread_mutex_lock(&info->msg_lock);
	if (msg == FORK)
		printf("%.0f %i has taken a fork\n", get_current_time_ms(info), pos); 
	else if (msg == EAT)
		printf("%.0f %i is eating\n", get_current_time_ms(info), pos); 
	else if (msg == SLEEP)
		printf("%.0f %i is sleeping\n", get_current_time_ms(info), pos); 
	else if (msg == THINK)
		printf("%.0f %i is thinking\n", get_current_time_ms(info), pos); 
	pthread_mutex_unlock(&info->msg_lock);
}

