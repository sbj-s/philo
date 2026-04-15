/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabound <ssabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:38:08 by ssabound          #+#    #+#             */
/*   Updated: 2026/03/24 16:12:11 by ssabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_eat(t_philo *philo)
{
	if (!is_running(philo->data))
		return ;
	if (philo->philo_id % 2 == 0 || philo->data->number_of_philosopher % 2 != 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_state(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_state(philo, "has taken a fork");
	}
	pthread_mutex_lock(&philo->data->mutex_die);
	philo->last_meal = get_time();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->data->mutex_die);
	print_state(philo, "is eating");
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	ft_sleep(t_philo *philo)
{
	if (!is_running(philo->data))
		return ;
	print_state(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	if (!is_running(philo->data))
		return ;
	print_state(philo, "is thinking");
	ft_usleep(1);
}

void	ft_alone(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_state(philo, "has taken a fork");
	ft_usleep(philo->data->time_to_die);
	pthread_mutex_unlock(philo->right_fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->number_of_philosopher == 1)
	{
		ft_alone(philo);
		return (NULL);
	}
	if (philo->philo_id % 2 == 0)
		ft_usleep(50);
	while (is_running(philo->data))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
