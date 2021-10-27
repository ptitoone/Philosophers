/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@42nice.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:46:17 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/27 13:01:00 by akotzky          ###   ########.fr       */
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
			if ((get_current_time_ms() - ((t_philo *)philo)->time_last_meal)
				> info->time_to_die)
				print_msg(((t_philo *)philo)->pos, "died", info);
			browse = browse->next;
		}
		pthread_mutex_unlock(&info->msg_lock);
	}
	return (NULL);
}

static void	eat_action_even(t_philo *philo, t_info *info)
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
		pthread_mutex_lock(&info->philo_decr_lock);
		info->philo_count--;
		pthread_mutex_unlock(&info->philo_decr_lock);
	}
}

static void	eat_action_odd(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&philo->fork);
	print_msg(philo->pos, "takes a fork", info);
	pthread_mutex_lock(&philo->next->fork);
	print_msg(philo->pos, "takes a fork", info);
	philo->time_last_meal = get_current_time_ms();
	print_msg(philo->pos, "is eating", info);
	wait_action(info->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
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
		pthread_mutex_unlock(&info->init_lock);
		while (info->philo_count > 0)
		{
			if (((t_philo *)philo)->pos % 2)
				eat_action_odd((t_philo *)philo, info);
			else
				eat_action_even((t_philo *)philo, info);
			print_msg(((t_philo *)philo)->pos, "is spleeping", info);
			wait_action(info->time_to_sleep);
			print_msg(((t_philo *)philo)->pos, "is thinking", info);
		}
	}
	return (NULL);
}

void	*spawn_cycle(void *philo)
{
	static t_info	*info;
	pthread_t		death;
	t_philo			*browse;
	t_count			i;

	if (!info)
		info = philo;
	else
	{
		browse = (t_philo *)philo;
		i = info->philo_count;
		info->start_time = get_current_time_ms();
		while (i-- > 0)
		{
			pthread_mutex_lock(&info->init_lock);
			pthread_create(&browse->life, NULL, life_cycle, (void *)browse);
			browse = browse->next;
		}
		pthread_create(&death, NULL, death_cycle, philo);
		while (info->philo_count > 0)
			;
	}
	return (NULL);
}
