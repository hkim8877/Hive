/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:06:21 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/07 18:06:23 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long long	ft_atol(char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	if (!*str)
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	check_errors(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (!ft_isdigit(*str))
		return (1);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}
