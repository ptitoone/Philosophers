/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@42nice.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:46:17 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/30 11:56:09 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_cycle(void *philo)
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
			if (((get_current_time_ms() - ((t_philo *)philo)->time_last_meal)) + 2 
				> info->time_to_die)
			{
				print_msg(((t_philo *)philo)->pos, "died", info);
				break ;
			}
			browse = browse->next;
		}
		info->status = 0;
	}
	return (NULL);
}

static void	eat_action(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&philo->fork);
	print_msg(philo->pos, "takes a fork", info);
	pthread_mutex_lock(&philo->next->fork);
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
		pthread_mutex_lock(&info->philo_decr_lock);
		info->philo_count--;
		pthread_mutex_unlock(&info->philo_decr_lock);
	}
}

void	*life_cycle(void *philo)
{
	static t_info	*info;

	if (!info)
		info = philo;
	else
	{
		((t_philo *)philo)->time_last_meal = get_current_time_ms();
		while (info->philo_count > 0)
		{
			eat_action((t_philo *)philo, info);
			print_msg(((t_philo *)philo)->pos, "is spleeping", info);
			wait_action(info->time_to_sleep);
			print_msg(((t_philo *)philo)->pos, "is thinking", info);
		}
	}
	return (NULL);
}
