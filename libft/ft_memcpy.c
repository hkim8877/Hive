/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:19:36 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/22 15:19:38 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char   *d;
    const unsigned char *s;
    size_t  i;

    d = (unsigned char *)dest;
    s = (const unsigned char *) src;
    i = 0;
    if (dest == NULL || src == NULL || n == 0)
        return (dest);
    while (i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
    char src[14] = "adbcd";
    char dest[20] = "hel";

    ft_memcpy(dest, src, 14);

    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);

    return 0;
}
    DESCRIPTION
    The memcpy() function copies n bytes from memory area src to memory area dest. 
    If dest and src overlap, behavior is undefined. 
    Applications in which dest and src might overlap should use memove(3) instead.
    RETURN VALUES
    The memcpy() function returns the original value of dest
*/