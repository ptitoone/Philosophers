/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@42nice.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:31:58 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/26 17:32:26 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_count	get_current_time_ms(void)
{
	struct timeval	tv_current;

	gettimeofday(&tv_current, NULL);
	return (tv_current.tv_sec * 1000 + tv_current.tv_usec / 1000);
}

void	wait_action(t_count msec_wait)
{
	t_count	tv_start;

	tv_start = get_current_time_ms();
	while (msec_wait > get_current_time_ms() - tv_start)
		usleep(msec_wait);
}
