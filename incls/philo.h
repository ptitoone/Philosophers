/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:35:03 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/26 13:33:36 by akotzky          ###   ########.fr       */
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
# include <limits.h>
# include "libft.h"

# define ERR_NOT_ENOUGH_ARGS	"Not enough arguments."
# define ERR_TOO_MANY_ARGS		"Too many arguments."
# define ERR_INVALID_ARGS		"Invalid arguments."
# define ERR_GET_TIME			"Getting time of day failed"
# define ERR_INV_COUNT_RANGE	"Invalid count range (min: 1 | max: 4294967295)"
# define ERR_MALLOC				"Memory allocation failed"

typedef unsigned int	t_count;
typedef struct s_philo	t_philo;

struct	s_philo
{
	pthread_t		thread;
	pthread_mutex_t	fork;
	t_count			pos;
	t_count			time_last_meal;
	t_count			number_of_meals;
	t_philo			*next;
};

typedef struct s_info
{
	struct timeval	tv_begin;
	pthread_mutex_t	msg_lock;
	pthread_mutex_t	act_lock;
	pthread_t		death;
	int				philo_count;
	t_count			time_to_die;
	t_count			time_to_eat;
	t_count			time_to_sleep;
	t_count			opt_min_meals;
}				t_info;

void	ph_exit(void **philo, char *msg);
void	init(int ac, char **av, t_info *info, t_philo **philo);
int		get_current_time_ms(t_info *info);
void	*lifecycle(void *philo);
void	*spawn(void *philo);
void	*check_death(void *philo);
void	print_msg(t_count pos, char *msg, t_info *info);

#endif
