/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:53:53 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/05/26 13:57:18 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

# define UP_HEX "0123456789ABCDEF"
# define LO_HEX "0123456789abcdef"

int	ft_printf(const char *format, ...);
int	ft_type(const char c, va_list *list);
int	printf_putchar(int c);
int	printf_putstr(char *str);
int	printf_putnbr(int nbr);
int	printf_putnbr_usint(unsigned int nbr);
int	printf_lowhex(uintptr_t nbr);
int	printf_uphex(uintptr_t nbr);
int	printf_pointer(void *ptr);

#endif
