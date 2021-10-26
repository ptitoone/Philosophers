/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@42nice.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:46:17 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/26 16:02:29 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&philo->next->fork);
	print_msg(philo->pos, "takes a fork", info);
	pthread_mutex_lock(&philo->fork);
	print_msg(philo->pos, "takes a fork", info);
	philo->time_last_meal = get_current_time_ms();
	print_msg(philo->pos, "is eating", info);
	wait_action(info->time_to_eat);
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
	if (info->opt_min_meals != -1)
		philo->number_of_meals++;
	if (philo->number_of_meals == info->opt_min_meals)
	{
		pthread_mutex_lock(&info->act_lock);
		info->philo_count--;
		pthread_mutex_unlock(&info->act_lock);
	}
}

void	*check_death(void *philo)
{
	static t_info	*info;
	t_philo			*browse;

	if (!info)
		info = philo;
	else
	{
		browse = (t_philo *)philo;
		while (info->philo_count > 0)
		{
			if ((get_current_time_ms() - ((t_philo *)philo)->time_last_meal) > info->time_to_die)
				print_msg(((t_philo *)philo)->pos, "died", info);
			browse = browse->next;
		}
	}
	return (NULL);
}

void	*lifecycle(void *philo)
{
	static t_info	*info;

	if (!info)
		info = philo;
	else
	{
		((t_philo *)philo)->time_last_meal = get_current_time_ms();
		while (info->philo_count > 0)
		{
			eat((t_philo *)philo, info);
			print_msg(((t_philo *)philo)->pos, "is spleeping", info);
			wait_action(info->time_to_sleep);
			print_msg(((t_philo *)philo)->pos, "is thinking", info);
		}
	}
	return (NULL);
}

void	print_msg(t_count pos, char *msg, t_info *info)
{
	pthread_mutex_lock(&info->msg_lock);
	printf("%i ms %i %s\n", get_current_time_ms() - info->start_time, pos, msg);
	if (ft_strcmp(msg, "died"))
		pthread_mutex_unlock(&info->msg_lock);
	else
		ph_exit(0, 0);
}
