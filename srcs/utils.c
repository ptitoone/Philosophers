/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:51:35 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/14 15:43:03 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

double	get_current_time_ms(t_info *info)
{
	double	current_time_ms;
	struct	timeval tv_current;

	gettimeofday(&tv_current, NULL);
	current_time_ms =
		(double)tv_current.tv_sec - (double)info->tv_begin.tv_sec;
	current_time_ms = current_time_ms * 1000.0;
	current_time_ms += (double)tv_current.tv_usec / 1000.0;
	return (current_time_ms);
}
