/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:27:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/28 17:18:20 by akotzky          ###   ########.fr       */
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
	while (++i < ac && av[i])
	{
		num = ft_atol(av[i]);
		if ((i >= 1 && i <= 3) && (num > 1000000 || ft_long_overflow(av[i])))
			ph_exit(NULL, ERR_INVALID_TIME);
		if (ft_long_overflow(av[i]) || (num <= 0 || num > 4294967295))
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
		new->pos = pos;
		new->status = THINK;
		new->next = NULL;
	}
	else
		ph_exit(NULL, ERR_MALLOC);
	return (new);
}

static void	init_philos(t_info *info, t_philo **head)
{
	int		i;
	t_philo	*browse;

	i = 0;
	*head = new_philo(i);
	browse = *head;
	while (++i < info->philo_count)
	{
		browse->next = new_philo(i);
		browse = browse->next;
	}
}

void	ph_init(int ac, char **av, t_info *info, t_philo **philo)
{
	ph_exit(philo, NULL);
	if (ac < 4)
		ph_exit(NULL, ERR_NOT_ENOUGH_ARGS);
	else if (ac > 5)
		ph_exit(NULL, ERR_TOO_MANY_ARGS);
	init_info(ac, av, info);
	init_philos(info, philo);
}
