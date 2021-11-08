/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@42nice.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:46:17 by akotzky           #+#    #+#             */
/*   Updated: 2021/11/08 16:59:55 by akotzky          ###   ########.fr       */
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
		while (info->philo_count > 0)
		{
			pthread_mutex_lock(&info->msg_lock);
			diff = get_time() - p->time_last_meal;
			if (!((t_philo *)philo)->status && diff >= info->time_to_die)
			{
				printf("%i %i %s\n", get_time() - info->st_time, p->pos, "died");
				info->philo_count = 0;
				return (NULL);
			}
			pthread_mutex_unlock(&info->msg_lock);
			usleep(100);
			p = p->next;
		}
	}
	return (NULL);
}

static void	eat_action(t_philo *philo, t_info *info)
{
	pthread_mutex_unlock(&info->init_lock);
	pthread_mutex_lock(&philo->fork);
	print_msg(philo->pos, "has taken a fork", info);
	pthread_mutex_lock(&philo->next->fork);
	print_msg(philo->pos, "has taken a fork", info);
	while (!info->start)
		;
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
	philo->status = 1;
	wait_action(info->time_to_eat);
	philo->status = 0;
	print_msg(((t_philo *)philo)->pos, "is sleeping", info);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

void	*life_cycle(void *philo)
{
	static t_info	*info;

	if (!info)
		info = philo;
	else
	{
		((t_philo *)philo)->time_last_meal = get_time();
		while (info->philo_count > 0)
		{
			eat_action((t_philo *)philo, info);
			wait_action(info->time_to_sleep);
			print_msg(((t_philo *)philo)->pos, "is thinking", info);
		}
	}
	return (NULL);
}

void	lauch_philos(int odd, int count, t_philo *philo, t_info *info)
{
	int	i;

	i = count;
	while (i-- > 0)
	{
		if (!odd)
		{
			if (philo->pos % 2)
			{
				pthread_mutex_lock(&info->init_lock);
				pthread_create(&philo->life, NULL, life_cycle, (void *)philo);
			}
		}
		else
		{
			if (!(philo->pos % 2))
			{
				pthread_mutex_lock(&info->init_lock);
				pthread_create(&philo->life, NULL, life_cycle, (void *)philo);
			}
		}
		philo = philo->next;
	}
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
		lauch_philos(0, info->philo_count, (t_philo *)philo, info);
		lauch_philos(1, info->philo_count, (t_philo *)philo, info);
		info->start = 1;
		pthread_create(&death, NULL, death_cycle, philo);
		pthread_join(death, NULL);
	}
	return (NULL);
}
