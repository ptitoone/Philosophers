/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:33:48 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/14 21:18:44 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

///// DEBUG FUNCTIONS /////

void	print_info(t_info info)
{
	ft_printf("philo_count = %i\n", info.philo_count);
	ft_printf("time_to_die = %i\n", info.time_to_die);
	ft_printf("time_to_eat = %i\n", info.time_to_eat);
	ft_printf("time_to_sleep = %i\n", info.time_to_sleep);
	ft_printf("opt_diners = %i\n", info.opt_min_meals);
}

///////////////////////////

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	philo;

	ph_init(ac - 1, av + 1, &info, &philo);
	
	print_info(info);
	ft_printf("Microseconds esplaced: %i\n", info.tv_begin.tv_usec);

	ph_exit(&philo, NULL);
	return (0);
}
