/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabound <ssabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:38:05 by ssabound          #+#    #+#             */
/*   Updated: 2026/03/24 13:44:32 by ssabound         ###   ########.fr       */
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

void	clean(t_data *data)
{
	int	i;

	i = 0;
	while (i++ < data->number_of_philosopher)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data->mutex_print);
	pthread_mutex_destroy(&data->mutex_die);
	free(data->fork);
	free(data->philo);
	free(data);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	pthread_t	monitor;
	int			i;

	if (!check_args(argc, argv))
		return (1);
	data = init_data(argc, argv);
	if (!data)
		return (1);
	if (!init_forks(data))
		return (1);
	if (!init_philos(data))
		return (1);
	i = 0;
	while (i++ < data->number_of_philosopher)
		pthread_create(&data->philo[i].philo, NULL, routine, &data->philo[i]);
	pthread_create(&monitor, NULL, monitoring, data);
	i = 0;
	while (i++ < data->number_of_philosopher)
		pthread_join(data->philo[i].philo, NULL);
	pthread_join(monitor, NULL);
	free(data);
	return (0);
}
