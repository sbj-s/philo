/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabound <ssabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:10:50 by ssabound          #+#    #+#             */
/*   Updated: 2026/03/24 13:12:07 by ssabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_usleep(long ms)
{
	long	time;

	time = get_time();
	while (ms > get_time() - time)
		usleep(1000);
}
