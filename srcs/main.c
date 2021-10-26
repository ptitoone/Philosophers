/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:33:48 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/26 13:39:18 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*spawn(void *philo)
{
	t_philo			*browse;
	static t_info	*info;
	int				i;
	int				count;

	if (!info)
		info = philo;
	else
	{
		i = 0;
		browse = (t_philo *)philo;
		count = info->philo_count;
		gettimeofday(&(info->tv_begin), NULL);
		while (++i <= count)
		{
			if (!(browse->pos % 2))
				pthread_create(&browse->thread, NULL, lifecycle, (void *)browse);
			usleep(100);
			browse = browse->next;
		}
		i = 0;
		while (++i <= count)
		{
			if (browse->pos % 2)
				pthread_create(&browse->thread, NULL, lifecycle, (void *)browse);
			browse = browse->next;
		}
		pthread_create(&info->death, NULL, check_death, (void *)philo);
		while (info->philo_count > 0)
			;
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_info		info;
	t_philo		*philo;
	pthread_t	spn;

	init(ac - 1, av + 1, &info, &philo);
	pthread_create(&spn, NULL, spawn, (void *)philo);
	pthread_join(spn, NULL);
	ph_exit((void **)(&philo), NULL);
	return (0);
}
