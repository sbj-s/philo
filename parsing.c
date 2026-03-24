/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabound <ssabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:58:14 by ssabound          #+#    #+#             */
/*   Updated: 2026/03/24 13:51:59 by ssabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_isdigit(char *c)
{
	int	i;

	i = 0;
	if (c[i] == '+')
		i++;
	if (c[i] == '\0')
		return (0);
	while (c[i] != '\0')
	{
		if (c[i] < '0' || c[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (sign * res);
}

int	check_args(int argc, char **argv)
{
	int		i;
	long	nb;

	i = 1;
	if (argc > 6 || argc < 5)
		return (print_error("error, wrong number arg"));
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (print_error("ERROR, wrong arg"));
		nb = ft_atol(argv[i]);
		if (nb > 2147483647 || nb <= 0)
			return (print_error("error, wrong arg"));
		i++;
	}
	return (1);
}
