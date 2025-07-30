/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:53:49 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/05/27 14:09:22 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_lowhex(uintptr_t nbr)
{
	int	i;
	int	check;

	i = 0;
	if (nbr >= 16)
	{
		check = printf_lowhex(nbr / 16);
		if (check == -1)
			return (-1);
		i += check;
	}
	check = write(1, &(LO_HEX[nbr % 16]), 1);
	if (check == -1)
		return (-1);
	i += check;
	return (i);
}

int	printf_uphex(uintptr_t nbr)
{
	int	i;
	int	check;

	i = 0;
	if (nbr >= 16)
	{
		check = printf_uphex(nbr / 16);
		if (check == -1)
			return (-1);
		i += check;
	}
	check = write(1, &(UP_HEX[nbr % 16]), 1);
	if (check == -1)
		return (-1);
	i += check;
	return (i);
}

int	printf_pointer(void *ptr)
{
	int	i;
	int	check;

	i = 0;
	if (!ptr)
		return (printf_putstr("(nil)"));
	i = write(1, "0x", 2);
	if (i == -1)
		return (-1);
	check = printf_lowhex((uintptr_t)ptr);
	if (check == -1)
		return (-1);
	i += check;
	return (i);
}
