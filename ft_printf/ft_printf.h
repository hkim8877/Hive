#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define UP_HEX "0123456789ABCDEF"
# define LO_HEX "0123456789abcdef"

int ft_printf(const char *, ...);
int ft_type(const char c, va_list *list);
int ft_printf_putchar(char c);
int ft_printf_putstr(char *str);

#endif