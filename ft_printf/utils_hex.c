/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:53:49 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/05/24 14:53:52 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int printf_lowhex(unsigned int nbr)
{
	int i;

	i = 0;
	if (nbr >= 16)
	{
		i += printf_lowhex(nbr / 16);
		i += printf_lowhex(nbr % 16);
	}
	else
		i += write(1, &(LO_HEX[nbr % 16]), 1);
	return (i);
}

int printf_uphex(unsigned int nbr)
{
	int i;
	
	i = 0;
	if (nbr >= 16)
	{
		i += printf_uphex(nbr / 16);
		i += printf_uphex(nbr % 16);
	}
	else
		i += write(1, &(UP_HEX[nbr % 16]), 1);
	return (i);
}

int printf_pointer(unsigned long int ptr)
{
	int i;
	
	i =	write(1, "0x", 2);
	if (i == -1)
		return (-1);
	if (ptr >= 16)
	{
		i += printf_pointer(ptr / 16);
		i += printf_pointer(ptr % 16);
	}
	else
		i += write(1, &LO_HEX[ptr % 16], 1);
	return (i);
}
