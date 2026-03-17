/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabound <ssabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:38:01 by ssabound          #+#    #+#             */
/*   Updated: 2026/03/17 19:20:14 by ssabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <fcntl.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
	int				meal_count;
	pthread_t		philo;
	int				philo_id;
	long			last_meal;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				simulation_run;
	long			start;
	t_philo			*philo;
	pthread_mutex_t	mutex_die;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	*fork;
	int				number_of_philosopher;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
}					t_data;

long				get_time(void);
int					print_error(char *msg);
long				ft_atol(const char *str);

#endif