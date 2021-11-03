/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@42nice.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:46:17 by akotzky           #+#    #+#             */
/*   Updated: 2021/11/03 16:12:09 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_cycle(void *philo)
{
	static t_info	*info;
	t_philo			*p;
	unsigned int	diff;

	if (!info)
		info = philo;
	else
	{
		p = (t_philo *)philo;
		pthread_mutex_lock(&info->msg_lock);
		while (info->philo_count > 0)
		{
			diff = (get_time() - p->time_last_meal);
			if (diff >= info->time_to_die && diff < 50000)
			{
				printf("%i %i %s\n", get_time() - info->st_time, p->pos, "died");
				pthread_mutex_lock(&info->msg_lock);
				info->philo_count = 0;
				break ;
			}
			pthread_mutex_unlock(&info->msg_lock);
			p = p->next;
		}
	}
	return (NULL);
}

static void	eat_action(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&philo->fork);
	print_msg(philo->pos, "has taken a fork", info);
	pthread_mutex_lock(&philo->next->fork);
	print_msg(philo->pos, "has taken a fork", info);
	philo->time_last_meal = get_time();
	print_msg(philo->pos, "is eating", info);
	if (info->opt_min_meals != -1)
		philo->number_of_meals++;
	if (philo->number_of_meals == info->opt_min_meals)
	{
		pthread_mutex_lock(&info->philo_decr_lock);
		info->philo_count--;
		pthread_mutex_unlock(&info->philo_decr_lock);
	}
	wait_action(info->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
	print_msg(((t_philo *)philo)->pos, "is sleeping", info);
}

void	*life_cycle(void *philo)
{
	static t_info	*info;

	if (!info)
		info = philo;
	else
	{
		while (info->philo_count > 0)
		{
			eat_action((t_philo *)philo, info);
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
	int				i;

	if (!info)
		info = philo;
	else
	{
		i = info->philo_count;
		info->st_time = get_time();
		while (i-- > 0)
		{
			((t_philo *)philo)->time_last_meal = get_time();
			pthread_create(&((t_philo *)philo)->life, NULL, life_cycle, philo);
			usleep(200);
			philo = ((t_philo *)philo)->next;
		}
		usleep(1000);
		pthread_create(&death, NULL, death_cycle, philo);
		while (info->philo_count > 0)
			;
	}
	return (NULL);
}
