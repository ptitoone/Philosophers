/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@42nice.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:46:17 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/14 16:10:13 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ph_eat(void *time_left)
{
	struct timeval	tv_start;
	struct timeval	tv_current;
	t_time			usec;

	while (*(t_time *)time_left > 0)
	{
		gettimeofday(&tv_start, NULL);
		gettimeofday(&tv_current, NULL);
		usec = tv_current.tv_usec - tv_start.tv_usec;
		while (usec < 1000)
		{
			gettimeofday(&tv_start, NULL);
			gettimeofday(&tv_current, NULL);
			usec += tv_current.tv_usec - tv_start.tv_usec;
		}
		//printf("time = %i\n", *(t_time *)time_left );
		*(t_time *)time_left -= 1;
	}
	printf("Done\n");
	return (NULL);
}

static void	*ph_eat_2(void *time_left)
{
	struct timeval	tv_start;
	struct timeval	tv_current;
	t_time			usec;

	while (*(t_time *)time_left > 0)
	{
		gettimeofday(&tv_start, NULL);
		gettimeofday(&tv_current, NULL);
		usec = tv_current.tv_usec - tv_start.tv_usec;
		while (usec < 1000)
		{
			gettimeofday(&tv_start, NULL);
			gettimeofday(&tv_current, NULL);
			usec += tv_current.tv_usec - tv_start.tv_usec;
		}
		*(t_time *)time_left -= 1;
	}
	printf("Done\n");
	return (NULL);
}

void	ph_spawn(t_philo *philo, t_info *info)
{
	t_philo	*browse;

	browse = philo;
	while (browse)
	{
		printf("%.3f %i is eating\n", get_current_time_ms(info), browse->pos);
		browse->time_left = info->time_to_eat;
		if (browse->pos % 2)
			pthread_create(&browse->thread, NULL,
				ph_eat, (void *)&(browse->time_left));
		pthread_create(&browse->thread, NULL,
			ph_eat_2, (void *)&(browse->time_left));
		pthread_join(browse->thread, NULL);
		browse = browse->next;
	}
}
