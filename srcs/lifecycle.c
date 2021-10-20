/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@42nice.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:46:17 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/20 11:30:15 by akotzky          ###   ########.fr       */
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
			if (!start)
			{
				gettimeofday(&(info->tv_begin), NULL);
				start = 1;
			}
			pthread_mutex_lock(&((t_philo *)philo)->fork);
			print_msg(((t_philo *)philo)->pos, "takes a fork", info);	
			pthread_mutex_lock(&((t_philo *)philo)->next->fork);
			print_msg(((t_philo *)philo)->pos, "takes a fork", info);	
			print_msg(((t_philo *)philo)->pos, "is eating", info);
			if ((get_current_time_ms(info) - ((t_philo *)philo)->time_last_meal)  >= info->time_to_die)
			{
				pthread_mutex_lock(&info->act_lock);
				print_msg(((t_philo *)philo)->pos, "died", info);
				ph_exit(0, 0);
			}
			((t_philo *)philo)->time_last_meal = get_current_time_ms(info);
			usleep(info->time_to_eat * 1000);
			print_msg(((t_philo *)philo)->pos, "is spleeping", info);
			pthread_mutex_unlock(&((t_philo *)philo)->fork);
			pthread_mutex_unlock(&((t_philo *)philo)->next->fork);
			usleep(info->time_to_sleep * 1000);
			print_msg(((t_philo *)philo)->pos, "is thinking", info);
		}
	}
	return (NULL);
}

void	print_msg(t_pos pos, char *msg, t_info *info)
{
	pthread_mutex_lock(&info->msg_lock);
	ft_putnbr_fd(get_current_time_ms(info), 1);
	ft_putstr_fd(" ms ", 1);
	ft_putnbr_fd(pos, 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(msg, 1);
	ft_putchar_fd('\n', 1);
	//	printf("%i ms %i %s\n", get_current_time_ms(info), pos, msg); 
	pthread_mutex_unlock(&info->msg_lock);
}

