/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@42nice.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:31:58 by akotzky           #+#    #+#             */
/*   Updated: 2021/11/03 16:01:29 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_count	get_time(void)
{
	struct timeval	tv_current;

	gettimeofday(&tv_current, NULL);
	return (tv_current.tv_sec * 1000 + tv_current.tv_usec / 1000);
}

void	wait_action(t_count msec_wait)
{
	t_count	tv_start;

	tv_start = get_time();
	while (msec_wait > get_time() - tv_start)
		usleep(msec_wait);
}
