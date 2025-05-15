/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:23:57 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/05/14 13:23:58 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_putchar(int c)
{
	return (write(1, &c, 1));
}

int ft_printf_putstr(char *str)
{
	int len;

	len = 0;
	if (!str )
		return (write(1, "(null)", 6));
	while (str[len] != '\0')
	{
		if (write(1, str[len], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}

