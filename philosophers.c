/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabound <ssabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:38:05 by ssabound          #+#    #+#             */
/*   Updated: 2026/04/15 15:13:56 by ssabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	is_running(t_data *data)
{
	int	status;

	pthread_mutex_lock(&data->mutex_die);
	status = data->simulation_run;
	pthread_mutex_unlock(&data->mutex_die);
	return (status);
}

static int	create_threads(t_data *data, pthread_t *monitor)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosopher)
	{
		if (pthread_create(&data->philo[i].philo, NULL, routine,
				&data->philo[i]))
			return (0);
		i++;
	}
	if (pthread_create(monitor, NULL, monitoring, data))
		return (0);
	return (1);
}

void	joind_thread(t_data *data, pthread_t *monitor)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosopher)
	{
		pthread_join(data->philo[i].philo, NULL);
		i++;
	}
	pthread_join(*monitor, NULL);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	pthread_t	monitor;

	if (!check_args(argc, argv))
		return (1);
	data = init_data(argc, argv);
	if (!data)
		return (1);
	if (!init_forks(data))
		return (1);
	if (!init_philos(data))
		return (1);
	if (!create_threads(data, &monitor))
		return (1);
	joind_thread(data, &monitor);
	free(data->fork);
	free(data->philo);
	free(data);
	return (0);
}
