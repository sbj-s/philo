/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabound <ssabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:38:01 by ssabound          #+#    #+#             */
/*   Updated: 2026/04/07 18:30:12 by ssabound         ###   ########.fr       */
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
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
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
	pthread_mutex_t	mutex_meal;
	pthread_mutex_t	*fork;
	int				number_of_philosopher;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
}					t_data;

void				ft_usleep(long ms);
int					dead_loop(t_philo *philo);
int					is_running(t_data *data);
long				get_time(void);
int					print_error(char *msg);
long				ft_atol(const char *str);
void				print_state(t_philo *philo, char *msg);
void				ft_usleep(long ms);
int					check_death(t_data *data, int i);
int					check_meals(t_data *data);
void				*monitoring(void *arg);
void				*routine(void *arg);
int					check_args(int argc, char **argv);
t_data				*init_data(int argc, char **argv);
int					init_forks(t_data *data);
int					init_philos(t_data *data);
void				print_death(t_philo *philo);
#endif