/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabound <ssabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:37:48 by ssabound          #+#    #+#             */
/*   Updated: 2026/03/24 13:50:30 by ssabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->number_of_philosopher = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atol(argv[5]);
	else
		data->number_of_times_each_philosopher_must_eat = -1;
	data->simulation_run = 1;
	data->start = get_time();
	return (data);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->number_of_philosopher);
	if (!data->fork)
		return (0);
	while (i < data->number_of_philosopher)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
			return (print_error("failed init mutext"), 0);
		i++;
	}
	if (pthread_mutex_init(&data->mutex_print, NULL) != 0)
		return (print_error("failed init mutext"), 0);
	if (pthread_mutex_init(&data->mutex_die, NULL) != 0)
		return (print_error("failed init mutext"), 0);
	return (1);
}

int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->number_of_philosopher);
	if (!data->philo)
		return (0);
	while (i < data->number_of_philosopher)
	{
		data->philo[i].philo_id = i + 1;
		data->philo[i].last_meal = data->start;
		data->philo[i].meal_count = 0;
		data->philo[i].data = data;
		data->philo[i].left_fork = &data->fork[i];
		data->philo[i].right_fork = &data->fork[(i + 1)
			% data->number_of_philosopher];
		i++;
	}
	return (1);
}
