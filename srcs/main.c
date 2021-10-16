/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:33:48 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/16 16:37:40 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

///// DEBUG FUNCTIONS /////

void	print_info(t_info info, t_philo *philo)
{
	int i = -1;

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

int	main(int ac, char **av)
{
	t_info			info;
	t_philo			*philo;
	
	init(ac - 1, av + 1, &info, &philo);

	print_info(info, philo); /*DEBUG*/

	lifecycle(philo, &info);
	ph_exit(&philo, NULL);
	return (0);
}
