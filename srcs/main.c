/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:33:48 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/18 13:20:35 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

///// DEBUG FUNCTIONS /////

void	print_info(t_info info, t_philo *philo)
{
	int i = -1;
	t_philo	*browse = philo;

	ft_printf("philo_count = %u\n", info.philo_count);
	ft_printf("time_to_die = %u\n", info.time_to_die);
	ft_printf("time_to_eat = %u\n", info.time_to_eat);
	ft_printf("time_to_sleep = %u\n", info.time_to_sleep);
	ft_printf("opt_diners = %u\n", info.opt_min_meals);
	write(1, "\n", 1);
	while (++i < info.philo_count)
	{
		ft_printf("Philo number = %i\n", philo->pos);
		philo = philo->next;
	}
}

///////////////////////////

void	*spawn(void *philo)
{
	t_philo	*browse;
	int		i;

	i = 0;
	browse = (t_philo *)philo;
	while (++i < 5)
	{
		pthread_create(&browse->thread, NULL, lifecycle, (void *)browse);
		browse = browse->next;
	}
	while (1){}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_info		info;
	t_philo		*philo;
	pthread_t	spn;
	
	init(ac - 1, av + 1, &info, &philo);

	print_info(info, philo); /*DEBUG*/

	pthread_create(&spn, NULL, spawn, (void *)philo);
	pthread_join(spn, NULL);

	ph_exit(&philo, NULL);
	return (0);
}
