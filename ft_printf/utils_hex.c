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