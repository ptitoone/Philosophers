/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:50:01 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/14 21:00:30 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	throw_error(char *err_msg)
{
	write(2, err_msg, ft_strlen(err_msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	ph_exit(t_philo *philo, char *msg)
{
	static t_philo *sv_philo;

	if (!sv_philo)
		sv_philo = philo;
	else
	{
		if (msg)
			throw_error(msg);	
		exit(EXIT_SUCCESS);
	}
}
