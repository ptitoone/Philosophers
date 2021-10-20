/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:35:03 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/20 15:14:01 by akotzky          ###   ########.fr       */
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

# define ERR_NOT_ENOUGH_ARGS	"Error: Not enough arguments."
# define ERR_TOO_MANY_ARGS		"Error: Too many arguments."
# define ERR_INVALID_ARGS		"Error: Invalid arguments."
# define ERR_GET_TIME			"Error: Getting time of day failed"
# define ERR_INV_COUNT_RANGE	"Error: Invalid count range (min : 1 | max : 4294967295)"
# define ERR_MALLOC				"Error: Memory allocation failed"

typedef unsigned short	t_status;
typedef unsigned int	t_time;
typedef unsigned int	t_pos;
typedef unsigned int	t_count;
typedef struct s_philo	t_philo;

extern int	start;

enum	e_status
{
	EAT,
	FORK,
	SLEEP,
	THINK,
	DEAD
};

struct	s_philo
{
	pthread_t		thread;
	pthread_mutex_t	fork;
	t_status		status;
	t_pos			pos;
	int				time_last_meal;
	t_philo			*next;
};

typedef struct	s_info
{
	struct timeval	tv_begin;
	pthread_mutex_t	msg_lock;
	pthread_mutex_t	act_lock;
	t_count			philo_count;
	t_time			time_to_die;
	t_time			time_to_eat;
	t_time			time_to_sleep;
	t_count			opt_min_meals;
}				t_info;

void	ph_exit(void **philo, char *msg);
void	init(int ac, char **av, t_info *info, t_philo **philo);
void	*lifecycle(void *philo);
void	*spawn(void *philo);

int		get_current_time_ms(t_info *info);

void	print_msg(t_pos pos, char *msg, t_info *info);

#endif
