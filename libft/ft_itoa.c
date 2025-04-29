/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:56:55 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/29 20:21:28 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	long	num;
	char	*result;

	len = ft_len((n));
	num = n;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	if (num == 0)
		result[0] = '0';
	if (num < 0)
	{
		num = -num;
		result[0] = '-';
	}
	while (num > 0)
	{
		result[--len] = (num % 10) + '0';
		num = num / 10;
	}
	return (result);
}
/*
#include <stdio.h>
int main()
{
    int a = 12345;
    long b = 123456789123;
    long c = -1234567890123;

    printf("%s\n", ft_itoa(a));
    printf("%s\n", ft_itoa(b));
    printf("%s\n", ft_itoa(c));
}
    */
/*
DESCRIPTION
    Allocate (with malloc(3)) and returns a string representing n.
    Negative numbers must be handled.
PARAMETERS
    n: int to convert
RETURN VALUES
    ft_itoa() returns the string representing n; 
NULL if the memory allocation failed.
*/
