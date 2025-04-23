/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:19:17 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/22 15:19:19 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *nptr)
{
    int sign;
    int result;

    sign = 1;
    result = 0;
    while (*nptr == ' '  || *nptr >= 9 && *nptr <= 13)
        nptr++;
    if (*nptr == '+' || *nptr == '-')
    {
        if (*nptr == '-')
            sign = -sign;
        nptr++;
    }
    while (*nptr >= '0' && *nptr <= '9')
    {
        result *= 10;
        result = result + *nptr - '0';
        nptr++;
    }
    result *=sign;
    return (result);    
}

#include <stdlib.h>
#include <stdio.h>

int main()
{
    char t1[] = "  -123456adf";
    char t2[] = "   -a123d";
    char t3[] = "   -+-125  ";
    char t4[] = "";
    char t5[] = "2147483647";
    char t6[] = "-2147483648";

    printf("atoi1: %d\n", atoi(t1));
    printf("ft_atoi1: %d\n", ft_atoi(t1));
    printf("atoi2: %d\n", atoi(t2));
    printf("ft_atoi2: %d\n", ft_atoi(t2));
    printf("atoi3: %d\n", atoi(t3));
    printf("ft_atoi3: %d\n", ft_atoi(t3));
    printf("atoi4: %d\n", atoi(t4));
    printf("ft_atoi4: %d\n", ft_atoi(t4));
    printf("atoi4: %d\n", atoi(t5));
    printf("ft_atoi4: %d\n", ft_atoi(t5));
    printf("atoi4: %d\n", atoi(t6));
    printf("ft_atoi4: %d\n", ft_atoi(t6));
}
