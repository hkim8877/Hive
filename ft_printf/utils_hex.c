#include "ft_printf.h"
#include <stdlib.h>

ssize_t *ft_printf_hex(unsigned int nbr)
{
	unsigned int len;
	unsigned int re;

	len = 0;
	result = malloc(sizeof(char)*17 + 1);
	while (nbr > 0)
	{
		result[len++] = hex[nbr % 16];
		nbr = nbr / 16;
	}
	re = len;
	while (len >= 0)
	{
		if ((write(1, &result[len], 1) == -1))
			return (-1);
		len--;
	}
	return (re);
}

void *ft_printf_pointer(unsigned long int ptr)
{
	
}

#include <stdio.h>

int main()
{
	unsigned int test = 22223;
	char *out[100];

	printf("%i\n", ft_printf_hex(test));
	//printf("%x\n", test);
	return (0);
}