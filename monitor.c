/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabound <ssabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:37:53 by ssabound          #+#    #+#             */
/*   Updated: 2026/03/21 19:48:56 by ssabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_death(t_data *data, int i)
{
	pthread_mutex_lock(&data->mutex_die);
	if (get_time() - data->philo[i].last_meal >= data->time_to_die)
	{
		data->simulation_run = 0;
		pthread_mutex_unlock(&data->mutex_die);
		print_death(&data->philo[i]);
		return (1);
	}
	pthread_mutex_unlock(&data->mutex_die);
	return (0);
}

int	check_meals(t_data *data)
{
	int	i;

	i = 0;
	if (data->number_of_times_each_philosopher_must_eat == -1)
		return (0);
	while (i < data->number_of_philosopher)
	{
		pthread_mutex_lock(&data->mutex_die);
		if (data->philo[i].meal_count < data->number_of_times_each_philosopher_must_eat)
		{
			pthread_mutex_unlock(&data->mutex_die);
			return (0);
		}
		pthread_mutex_unlock(&data->mutex_die);
		i++;
	}
	pthread_mutex_lock(&data->mutex_die);
	data->simulation_run = 0;
	pthread_mutex_unlock(&data->mutex_die);
	return (1);
}

void	*monitoring(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		for (int i = 0; i < data->number_of_philosopher; i++)
		{
			if (check_death(data, i))
				return (NULL);
		}
		if (check_meals(data) == 1)
			return (NULL);
	}
}
