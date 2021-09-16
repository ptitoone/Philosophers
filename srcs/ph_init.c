/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:27:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 14:32:32 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_info(int ac, char **av, t_info *info)
{
	int		i;
	int		time;

	i = -1;
	if (gettimeofday(&(info->tv_begin), NULL))
		ph_exit(NULL, ERR_GET_TIME);
	while (++i < ac && av[i])
	{
		time = ft_atoi(av[i]);
		if (time <= 0 || time > 1000000 || ft_int_overflow(av[i]))
			ph_exit(NULL, ERR_INVALID_TIME);
		if (i == 0)
		   info->philo_count = time;
		else if (i == 1)
		   info->time_to_die = time;
		else if (i == 2)
		   info->time_to_eat = time;
		else if (i == 3)
		   info->time_to_sleep = time;
		else if (i == 4)
		   info->opt_min_meals = time;
	}
}

void	ph_init(int ac, char **av, t_info *info, t_philo *philo)
{
	ph_exit(philo, NULL);
	if (ac < 4)
		ph_exit(NULL, ERR_NOT_ENOUGH_ARGS);
	else if (ac > 5)
		ph_exit(NULL, ERR_TOO_MANY_ARGS);
	init_info(ac, av, info);
}

