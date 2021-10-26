/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:33:48 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/26 17:56:12 by akotzky          ###   ########.fr       */
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
		if (browse)
		{
			browse = (*sv_philo)->next;
			while (browse != *sv_philo)
			{
				to_free = browse;
				browse = browse->next;
				pthread_detach(browse->life);
				free(to_free);
			}
			free(browse);
		}
		if (msg)
			throw_error(msg);
	//	while (1);
		exit(EXIT_SUCCESS);
	}
}

void	print_msg(t_count pos, char *msg, t_info *info)
{
	pthread_mutex_lock(&info->msg_lock);
	printf("%i ms %i %s\n", get_current_time_ms() - info->start_time, pos, msg);
	if (ft_strcmp(msg, "died"))
		pthread_mutex_unlock(&info->msg_lock);
	else
		ph_exit(0, 0);
}

int	main(int ac, char **av)
{
	t_info		info;
	t_philo		*philo;
	pthread_t	spawn;

	init(ac - 1, av + 1, &info, &philo);
	pthread_create(&spawn, NULL, spawn_cycle, (void *)philo);
	pthread_join(spawn, NULL);
	ph_exit((void **)(&philo), NULL);
	return (0);
}
