/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:34:33 by myli-pen          #+#    #+#             */
/*   Updated: 2025/05/14 16:55:46 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int	main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setbuf(stdout, NULL);
	// c
	ft_printf("\033[33mc c c c c\033[0m\n");
	ft_printf("\t\tReturns: %d\tprintf\n", printf(".%c.%c.%c.%c.%c.", '\0', 0, '\0', '0', '\0'));
	ft_printf("\t\tReturns: %d\tft_printf\n\n", ft_printf(".%c.%c.%c.%c.%c.", '\0', 0, '\0', '0', '\0'));

	// s
	char *str1 = NULL;
	char *str2 = "Hello";
	char *str3 = "";
	printf("\033[33ms\033[0m\n");
	printf("\t\tReturns: %d\n", printf("%s", str1));
	ft_printf("\t\tReturns: %d\n", ft_printf("%s", str1));
	printf("\t\tReturns: %d\n", printf("%s", str2));
	ft_printf("\t\tReturns: %d\n", ft_printf("%s", str2));
	printf("\t\tReturns: %d\n", printf("%s", str3));
	ft_printf("\t\tReturns: %d\n\n", ft_printf("%s", str3));

	// p
	char *ptr1 = calloc(1, sizeof (char *));
	printf("\033[33mp\033[0m\n");
	printf("\t\tReturns: %d\n", printf("%p", (void *)-ULONG_MAX));
	ft_printf("\t\tReturns: %d\n", ft_printf("%p", (void *)-ULONG_MAX));
	printf("\t\tReturns: %d\n", printf("%p", NULL));
	ft_printf("\t\tReturns: %d\n", ft_printf("%p", NULL));
	printf("\tReturns: %d\n", printf("%p", ptr1));
	ft_printf("\tReturns: %d\n\n", ft_printf("%p", ptr1));

	// d
	printf("\033[33md\033[0m\n");
	printf("\t\tReturns: %d\n", printf("%d", 1000));
	ft_printf("\t\tReturns: %d\n", ft_printf("%d", 1000));
	printf("\t\tReturns: %d\n", printf("%d", 0));
	ft_printf("\t\tReturns: %d\n\n", ft_printf("%d", 0));

	// i
	printf("\033[33mi\033[0m\n");
	printf("\t\tReturns: %i\n", printf("%i", -1000));
	ft_printf("\t\tReturns: %i\n\n", ft_printf("%i", -1000));

	// u
	printf("\033[33mu\033[0m\n");
	printf("\t\tReturns: %d\n", printf("%u", UINT_MAX + 1));
	ft_printf("\t\tReturns: %d\n", ft_printf("%u", UINT_MAX + 1));
	printf("\tReturns: %d\n", printf("%u", -1));
	ft_printf("\tReturns: %d\n\n", ft_printf("%u", -1));

	// x
	printf("\033[33mx\033[0m\n");
	printf("\tReturns: %d\n", printf("%x", -1));
	ft_printf("\tReturns: %d\n\n", ft_printf("%x", -1));

	// X
	printf("\033[33mX\033[0m\n");
	printf("\tReturns: %d\n", printf("%X", -1));
	ft_printf("\tReturns: %d\n\n", ft_printf("%X", -1));

	// %
	printf("\033[33m%%\033[0m\n");
	printf("\t\tReturns: %d\n", printf("%%"));
	ft_printf("\t\tReturns: %d\n\n", ft_printf("%%"));

	// all
	char *ptr2 = calloc(1, sizeof (char *));
	printf("\033[33mc s p d i u x X %% (all)\033[0m\n");
	printf("\tReturns: %d\n", printf("%c %s %p %d %i %u %x %X %%", '$', "Hello", ptr2, 3, 7, 12, 15, 15));
	ft_printf("\tReturns: %d\n\n", ft_printf("%c %s %p %d %i %u %x %X %%", '$', "Hello", ptr2, 3, 7, 12, 15, 15));

	// undefined
	ft_printf("\033[33mld (undefined)\033[0m");
	ft_printf("\tReturns: %d\n\n", ft_printf("%ld", (long)1000));

	// null
	// printf("\033[33mnull\033[0m\t");
	// printf("\tReturns: %d\n", printf(NULL));
	ft_printf("\033[33mnull\033[0m\t");
	ft_printf("\tReturns: %d\n\n", ft_printf(NULL));

	free (ptr1);
	free (ptr2);

	// Eve's test, closes stdout and checks whether error value is returned from write().
	// ft_printf("\033[33mstdout closed\033[0m");
	// int ret;
	// int original_stdout = dup(STDOUT_FILENO);
	// fclose(stdout);
	// ret = ft_printf("test\n");
	// stdout = (FILE *)fdopen(original_stdout, "w");
	// printf("\tReturns: %d\n\n", ret);

	return (0);
}
