/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:20:09 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/22 15:20:11 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
    char *temp;
    size_t i;

    temp = (char *)s;
    i = 0;
    while (i < n)
    {
        temp[i] = 0;
        i++;
    }
}
/*
#include <stdio.h>
int main()
{
    char test[] = "abcdef";
    ft_bzero(test, 3);
    printf("%s\n", test+3);
}
DESCRIPTION
The bzero() function writes n zeroed bytes to the string s. 
If n is zero, bzero() does nothing.
This function works the same way as the memset() function, 
except you don't have to specify what character to write, 
it'll always be 0 (NUL character).    
*/
