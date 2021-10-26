/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:50:01 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/26 13:42:40 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	throw_error(char *err_msg)
{
	printf("Error: %s\n", err_msg);
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
//			pthread_detach(browse->thread);
			free(to_free);
		}
		free(browse);
		if (msg)
			throw_error(msg);
	//	while (1);
		exit(EXIT_SUCCESS);
	}
}
