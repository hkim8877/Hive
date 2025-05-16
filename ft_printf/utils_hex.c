#include "ft_printf.h"
#include <stdlib.h>

static void *get_hex(unsigned int nbr)
{
	char num;

	//if (nbr < 0)
	//	return ;
	get_hex(nbr / 16);
	num = nbr % 16 + '0';
	write(1, &num, 1);
}

char *print_hex(unsigned int nbr)
{
	//if (nbr < 0)
	//	return (-1);
	if (nbr == 0)
	{
		write(1, "0x", 2);
	}
	return (get_hex(nbr));
}
	
	/*while (len >= 0)
	{
		if ((write(1, &result[len], 1) == -1))
			return (-1);
		len--;
	}*/


/*void *ft_printf_pointer(unsigned long int ptr)
{
	
}
*/
#include <stdio.h>

int main()
{
	unsigned int test = 22223;
	char *out[100];

	print_hex(test);
	//printf("%x\n", test);
	return (0);
}