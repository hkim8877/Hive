/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:21:09 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/22 15:21:11 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char *temp;
    size_t i;

    temp = (unsigned char*) s;
    i = 0;
    while (i < n)
    {
        temp[i] = (unsigned char)c;
        i++;
    }
    return (s);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char test[10] = "abcdef";
    printf("%s\n", (char *)ft_memset(test,'-', 30));
   // printf("%s\n", (char*)memset(test, '-', 30));
}*/
