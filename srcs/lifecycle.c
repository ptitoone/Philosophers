/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@42nice.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:46:17 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/25 21:56:18 by akotzky          ###   ########.fr       */
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
		((t_philo *)philo)->time_last_meal = get_current_time_ms(info);
		while (1)
		{
			pthread_mutex_lock(&((t_philo *)philo)->next->fork);
			print_msg(((t_philo *)philo)->pos, "takes a fork", info);	
			pthread_mutex_lock(&((t_philo *)philo)->fork);
			print_msg(((t_philo *)philo)->pos, "takes a fork", info);	
			if ((get_current_time_ms(info) - ((t_philo *)philo)->time_last_meal)  >= info->time_to_die)
			{
				pthread_mutex_lock(&info->act_lock);
				print_msg(((t_philo *)philo)->pos, "died", info);
			}
			((t_philo *)philo)->time_last_meal = get_current_time_ms(info) + 2;
			print_msg(((t_philo *)philo)->pos, "is eating", info);
			usleep(info->time_to_eat * 1000);
			print_msg(((t_philo *)philo)->pos, "is spleeping", info);
			pthread_mutex_unlock(&((t_philo *)philo)->next->fork);
			pthread_mutex_unlock(&((t_philo *)philo)->fork);
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
	if (ft_strcmp(msg, "died"))
		pthread_mutex_unlock(&info->msg_lock);
	else
		ph_exit(0, 0);
}

