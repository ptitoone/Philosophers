/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:35:03 by akotzky           #+#    #+#             */
/*   Updated: 2021/08/15 17:13:32 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define ERR_NOT_ENOUGH_ARGS	"Error: Not enough arguments."
# define ERR_TOO_MANY_ARGS		"Error: Too many arguments."
# define ERR_INVALID_ARGS		"Error: Invalid arguments."

typedef unsigned int t_count;

typedef struct	s_info {

	t_count	philo_count;
	t_count	time_to_die;
	t_count	time_to_eat;
	t_count	time_to_sleep;
	t_count	opt_time_to_eat;

}				t_info;

int	throw_error(char *err_msg);
int	ft_strlen(char *str);

#endif
