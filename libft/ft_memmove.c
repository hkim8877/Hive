/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:20:28 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/22 15:20:29 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char   *d;
    const unsigned char *s;
        
    d = (unsigned char *) dest;
    s = (const unsigned char *) src;
    if (d <= s)
    {
        while (n--)
            *(d++) = *(s++);
    }
    else
    {
        d = d + (n - 1);
        s = s + (n - 1);
        while (n--)
        {
            *(d--) =  * (s--);
        }
    }
    return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char a[] = "Hello";
    char *b = "12345678";

    printf("%s\n", (char *)ft_memmove(a, b, 6));
    printf("%s\n", (char *)memmove(a, b, 6));

}
*/
/*
The  memmove()  function copies n bytes from memory area src to memory area dest.  The memory areas may
overlap: copying takes place as though the bytes in src are first copied into a  temporary  array  that
does not overlap src or dest, and the bytes are then copied from the temporary array to dest.
The memmove() function returns a pointer to dest.
*/
