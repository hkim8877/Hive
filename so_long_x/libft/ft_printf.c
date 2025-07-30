/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:48:56 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/05/26 18:23:44 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_type(const char c, va_list *list);

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		result;
	int		i;

	if (!format)
		return (-1);
	va_start(list, format);
	result = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			i = ft_type(*format, &list);
		}
		else
			i = printf_putchar(*format);
		if (i == -1)
			return (va_end(list), -1);
		else
			result += i;
		format++;
	}
	va_end(list);
	return (result);
}

int	ft_type(const char c, va_list *list)
{
	if (c == 'c')
		return (printf_putchar(va_arg(*list, int)));
	else if (c == 's')
		return (printf_putstr(va_arg(*list, char *)));
	else if (c == 'd')
		return (printf_putnbr(va_arg(*list, int)));
	else if (c == 'i')
		return (printf_putnbr(va_arg(*list, int)));
	else if (c == 'u')
		return (printf_putnbr_usint(va_arg(*list, unsigned int)));
	else if (c == 'p')
		return (printf_pointer(va_arg(*list, void *)));
	else if (c == 'x')
		return (printf_lowhex(va_arg(*list, unsigned int)));
	else if (c == 'X')
		return (printf_uphex(va_arg(*list, unsigned int)));
	else if (c == '%')
		return (printf_putchar('%'));
	return (-1);
}
