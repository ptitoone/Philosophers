/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:27:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/28 11:00:38 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_ribool	init_info(int ac, char **av, t_info *info)
{
	int			i;
	long long	num;

	i = -1;
	pthread_mutex_init(&info->msg_lock, NULL);
	pthread_mutex_init(&info->philo_decr_lock, NULL);
	info->opt_min_meals = -1;
	while (++i < ac && av[i])
	{
		num = ft_atol(av[i]);
		if (ft_long_overflow(av[i]) || (num <= 0 || num > UINT_MAX))
			return (T_FALSE);
		if (i == 0)
			info->philo_count = num;
		else if (i == 1)
			info->time_to_die = num;
		else if (i == 2)
			info->time_to_eat = num;
		else if (i == 3)
			info->time_to_sleep = num;
		else if (i == 4)
			info->opt_min_meals = num;
	}
	return (T_TRUE);
}

static t_philo	*new_philo(int pos)
{
	t_philo	*new;

	new = (t_philo *)malloc(1 * sizeof(t_philo));
	if (new)
	{
		pthread_mutex_init(&new->fork, NULL);
		new->pos = pos;
		new->next = NULL;
		new->time_last_meal = 0;
		new->number_of_meals = 0;
	}
	return (new);
}

static t_ribool	init_philos(t_info *info, t_philo **head)
{
	int		i;
	t_philo	*browse;

	i = 0;
	*head = new_philo(i + 1);
	browse = *head;
	while (++i < info->philo_count)
	{
		browse->next = new_philo(i + 1);
		if (!browse->next)
			return (T_FALSE);
		browse = browse->next;
	}
	browse->next = *head;
	return (T_TRUE);
}

t_ribool	init(int ac, char **av, t_info *info, t_philo **philo)
{
	if (ac < 4)
		return (throw_error(ERR_NOT_ENOUGH_ARGS));
	else if (ac > 5)
		return (throw_error(ERR_TOO_MANY_ARGS));
	else if (!init_info(ac, av, info))
		return (throw_error(ERR_INV_COUNT_RANGE));
	else if (!init_philos(info, philo))
		return (throw_error(ERR_MALLOC));
	life_cycle(info);
	death_cycle(info);
	return (T_TRUE);
}
