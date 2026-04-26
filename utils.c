/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabound <ssabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:38:12 by ssabound          #+#    #+#             */
/*   Updated: 2026/04/26 12:51:42 by ssabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	print_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return (0);
}

long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (print_error("Error gettimeofday"), -1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_state(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->mutex_print);
	if (is_running(philo->data))
		printf("%ld %d %s\n", get_time() - philo->data->start, philo->philo_id,
			msg);
	pthread_mutex_unlock(&philo->data->mutex_print);
}

void	print_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_print);
	printf("%ld %d died\n", get_time() - philo->data->start, philo->philo_id);
	pthread_mutex_unlock(&philo->data->mutex_print);
}
