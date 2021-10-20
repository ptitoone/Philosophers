/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:50:01 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/20 16:55:24 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	throw_error(char *err_msg)
{
	write(2, err_msg, ft_strlen(err_msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	ph_exit(void **philo, char *msg)
{
	static t_philo	**sv_philo;
	t_philo			*browse;
	t_philo			*to_free;

	if (!sv_philo)
		sv_philo = (t_philo **)philo;
	else
	{
		browse = (*sv_philo)->next;
		while (browse != *sv_philo)
		{
			to_free = browse;
			browse = browse->next; 
			pthread_detach(browse->thread);
			pthread_mutex_unlock(&browse->fork);
			free(to_free);
		}
		free(browse);
		if (msg)
			throw_error(msg);
		while (1);
		exit(EXIT_SUCCESS);
	}
}
