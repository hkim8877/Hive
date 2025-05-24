#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define UP_HEX "0123456789ABCDEF"
# define LO_HEX "0123456789abcdef"

int ft_printf(const char *, ...);
int ft_type(const char c, va_list *list);
int printf_putchar(char c);
int printf_putstr(char *str);
int printf_putnbr(int nbr);
int printf_putnbr_usint(unsigned int nbr);
int printf_lowhex(unsigned int nbr);
int printf_uphex(unsigned int nbr);
int printf_pointer(unsigned long int ptr);

#endif