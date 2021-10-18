/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@42nice.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:46:17 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/16 16:34:20 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*act_die(void *fork)
{
	static int *time;

	if (!time)
		time = (int *)fork;
	else
		usleep(*(t_time *)time * 1000);
	return (NULL);
}

void	*act_eat(void *fork)
{
	static int *time;

	if (!time)
		time = (int *)fork;
	else
	{
		pthread_mutex_lock(fork);
		usleep(*(t_time *)time * 1000);
		pthread_mutex_unlock(fork);
	}
	return (NULL);
}

void	*act_sleep(void *fork)
{
	static int *time;

	if (!time)
		time = (int *)fork;
	else
		usleep(*(t_time *)time * 1000);
	return (NULL);
}

void	*print_msg(void *philo)
{
	static pthread_mutex_t	*lock;
	static t_info			*info;

	if (!lock)
		lock = philo;
	else if (!info)
		info = philo;
	else
	{
		pthread_mutex_lock(lock);
		if (((t_philo *)philo)->status == EAT)
			printf("%.3f %i is eating\n", get_current_time_ms(info), ((t_philo *)philo)->pos); 
		else if (((t_philo *)philo)->status == SLEEP)
			printf("%.3f %i is sleeping\n", get_current_time_ms(info), ((t_philo *)philo)->pos); 
		else if (((t_philo *)philo)->status == THINK)
			printf("%.3f %i is thinking\n", get_current_time_ms(info), ((t_philo *)philo)->pos); 
		pthread_mutex_unlock(lock);
	}
	return (NULL);
}

void	lifecycle(t_philo *philo, t_info *info)
{
	t_philo			*browse;

	browse = philo;
	while (browse)
	{
		print_msg((void *)browse);
		pthread_create(&browse->thread, NULL,
			act_eat, (void *)(&info->time_to_eat));
		pthread_join(browse->thread, NULL);
		browse = browse->next;
	}
}
