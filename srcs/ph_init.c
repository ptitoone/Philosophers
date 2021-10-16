/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:27:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/16 16:36:40 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_info(int ac, char **av, t_info *info)
{
	int			i;
	long long	num;

	i = -1;
	if (gettimeofday(&(info->tv_begin), NULL))
		ph_exit(NULL, ERR_GET_TIME);
	pthread_mutex_init(&info->print_msg, NULL);
	while (++i < ac && av[i])
	{
		num = ft_atol(av[i]);
		if (ft_long_overflow(av[i]) || (num <= 0 || num > UINT_MAX))
			ph_exit(NULL, ERR_INV_COUNT_RANGE);
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
	info->forks = info->philo_count;
}

static t_philo	*new_philo(int pos)
{
	t_philo	*new;

	new = (t_philo *)malloc(1 * sizeof(t_philo));
	if (new)
	{
		pthread_mutex_init(&new->fork, NULL);
		new->pos = pos;
		new->status = THINK;
		new->next = NULL;
		new->time_left = (t_time *)malloc(1 * sizeof(t_time));
	}
	return (new);
}

static void	init_philos(t_info *info, t_philo **head)
{
	int		i;
	t_philo	*browse;

	i = 0;
	*head = new_philo(i + 1);
	browse = *head;
	while (++i < info->philo_count)
	{
		browse->next = new_philo(i + 1);
		browse = browse->next;
	}
}

void	init(int ac, char **av, t_info *info, t_philo **philo)
{
	ph_exit(philo, NULL);
	if (ac < 4)
		ph_exit(NULL, ERR_NOT_ENOUGH_ARGS);
	else if (ac > 5)
		ph_exit(NULL, ERR_TOO_MANY_ARGS);
	init_info(ac, av, info);
	act_die(&info->time_to_die);
	act_eat(&info->time_to_eat);
	act_sleep(&info->time_to_sleep);
	print_msg(&info->print_msg);
	init_philos(info, philo);
}
