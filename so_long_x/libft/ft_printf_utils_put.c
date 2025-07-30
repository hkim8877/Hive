/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:23:57 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/05/26 14:01:18 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_putchar(int c)
{
	return (write(1, &c, 1));
}

int	printf_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[len] != '\0')
	{
		if (write(1, &str[len], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	printf_putnbr(int nbr)
{
	int	i;
	int	check;

	i = 0;
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		i += printf_putchar('-');
		nbr *= (-1);
	}
	if (nbr > 9)
	{
		i += printf_putnbr(nbr / 10);
		i += printf_putnbr(nbr % 10);
	}
	else
	{
		check = printf_putchar(nbr + '0');
		if (check == -1)
			return (-1);
		i += check;
	}
	return (i);
}

int	printf_putnbr_usint(unsigned int nbr)
{
	int	i;
	int	check;

	i = 0;
	if (nbr > 9)
	{
		i += printf_putnbr_usint(nbr / 10);
		i += printf_putnbr_usint(nbr % 10);
	}
	else
	{
		check = printf_putchar(nbr + '0');
		if (check == -1)
			return (-1);
		i += check;
	}
	return (i);
}
