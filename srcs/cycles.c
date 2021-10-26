/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@42nice.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:46:17 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/26 17:49:24 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	launch_philos(t_philo *philo, t_count count)
{
	t_count	i;

	i = 0;
	while (++i <= count)
	{
		if (!(philo->pos % 2))
			pthread_create(&philo->life, NULL, life_cycle, (void *)philo);
		usleep(100);
		philo = philo->next;
	}
	i = 0;
	while (++i <= count)
	{
		if (philo->pos % 2)
			pthread_create(&philo->life, NULL, life_cycle, (void *)philo);
		philo = philo->next;
	}
}

static void	eat_action(t_philo *philo, t_info *info)
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
	}
	return (NULL);
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

void	*spawn_cycle(void *philo)
{
	static t_info	*info;
	pthread_t		death;

	if (!info)
		info = philo;
	else
	{
		info->start_time = get_current_time_ms();
		launch_philos((t_philo *)philo, info->philo_count);
		pthread_create(&death, NULL, death_cycle, (void *)philo);
		while (info->philo_count > 0)
			;
	}
	return (NULL);
}