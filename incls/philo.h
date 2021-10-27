/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:35:03 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/27 13:01:25 by akotzky          ###   ########.fr       */
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

# define ERR_NOT_ENOUGH_ARGS	"Not enough arguments."
# define ERR_TOO_MANY_ARGS		"Too many arguments."
# define ERR_INVALID_ARGS		"Invalid arguments."
# define ERR_INV_COUNT_RANGE	"Invalid count range (min: 1 | max: 4294967295)"
# define ERR_MALLOC				"Memory allocation failed"

typedef unsigned int	t_count;
typedef struct s_philo	t_philo;

typedef enum e_ribool
{
	T_FALSE,
	T_TRUE,
	T_MAYBE
}				t_ribool;

struct	s_philo
{
	pthread_t		life;
	pthread_mutex_t	fork;
	t_count			pos;
	t_count			time_last_meal;
	int				number_of_meals;
	t_philo			*next;
};

typedef struct s_info
{
	pthread_mutex_t	init_lock;
	pthread_mutex_t	msg_lock;
	pthread_mutex_t	philo_decr_lock;
	t_count			start_time;
	int				philo_count;
	t_count			time_to_die;
	t_count			time_to_eat;
	t_count			time_to_sleep;
	int				opt_min_meals;
}				t_info;

t_ribool	throw_error(char *err_msg);
t_ribool	init(int ac, char **av, t_info *info, t_philo **philo);

int			ft_strcmp(char const *s1, char const *s2);
t_ribool	ft_long_overflow(const char *src);
long int	ft_atol(const char *str);
char		*ft_ltoa(long n);
t_count		get_current_time_ms(void);
void		wait_action(t_count msec_wait);

void		*life_cycle(void *philo);
void		*spawn_cycle(void *philo);
void		*death_cycle(void *philo);
void		print_msg(t_count pos, char *msg, t_info *info);

#endif
