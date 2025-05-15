/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:23:27 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/05/14 13:23:29 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int ft_type(const char c, va_list *list);

int ft_printf(const char *format, ...)
{
    va_list list;
    int result;
    int i;

    if (!format)
        return (-1);
    va_start(list, format);
    result = 0;
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            result += ft_type(format[i + 1], &list);
            i++;
        }
        else
            result += ft_printf_char(format[i]);
        i++;
    }
    va_end(list);
    return (result);
}

int ft_type(const char c, va_list *list)
{
    if (c == 'c')
        return (ft_printf_putchar(va_arg(*list, char)));
    else if (c == 's')
        return (ft_printf_putstr(va_arg(*list, char *)));
    else if (c == 'd')
        return (ft_printf_putnbr(va_arg(*list, int)));
    else if (c == 'i')
        return (ft_printf_putnbr(va_arg(*list, int)));
    else if (c == 'u')
        return (ft_printf_putnbr_u(va_arg(*list, unsigned int)));
    else if (c == 'p')
        return (ft_printf_pointer(va_arg(*list, unsigned long), c));
    else if (c == 'x')
        return (ft_printf_hex(va_arg(*list, unsigned int)));
    else if (c == 'X')
        return (ft_printf_hex_u(va_arg(*list, unsigned int)));
    else if (c == '%')
        return (ft_printf_putchar('%'));
    return (0);
}
