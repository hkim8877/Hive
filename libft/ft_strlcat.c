/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:19:49 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/22 15:19:51 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  d_len;
    size_t  s_len;
    size_t  i;

    d_len = 0;
    s_len = 0;
    i = 0;
    while (dst[d_len] != '\0' && (d_len < size))
        d_len++;
    while (src[s_len] != '\0')
        s_len++;
    if (size <= d_len)
        return (size + s_len);
    while (src[s_len] != '\0' && (d_len + i) < (size - 1))
    {
        dst[d_len + i] = src[i];
        i++;
    }
    dst[d_len + i] = '\0';
    return (d_len + s_len);
}

#include <stdio.h>
#include <bsd/string.h>

int main()
{
    char d[5] = "abcde";
    const char *src = "you";

   size_t re = ft_strlcat(d, src, 3);

    printf("%zu\n", re);
    printf("%s\n", d);
 /*  size_t or = strlcat(d, src, 3);

    printf("%zu\n", or);
    printf("%s\n", d);
    */
    return 0;
}


/*DESCRIPTION
     The strlcpy() and strlcat() functions copy and concatenate strings respectively.
     They are designed to be safer, more consistent, and less error prone replacements
     for strncpy(3) and strncat(3).  Unlike those functions, strlcpy() and strlcat() 
     take the full size of the buffer (not just the length) and guarantee to 
     NUL-terminate the result (as long as size is larger than 0 or, 
     in the case of strlcat(), as long as there is at least one byte free in dst).  
     Note that a byte for the NUL should be included in size.  
     Also note that strlcpy() and strlcat() only operate on true “C” strings.  
     This means that for strlcpy() src must be NUL-terminated and
     for strlcat() both src and dst must be NUL-terminated.

     The strlcpy() function copies up to size - 1 characters from the NUL-terminated 
     string src to dst, NUL-terminating the result.

     The strlcat() function appends the NUL-terminated string src to the end of dst.  
     It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.

RETURN VALUES
     The strlcpy() and strlcat() functions return the total length of the string they tried to create.
     For strlcpy() that means the length of src.     
     For strlcat() that means the initial length of dst plus the length of src.  
     While this may seem somewhat confusing, it was done to make truncation detection simple.

     Note, however, that if strlcat() traverses size characters without finding a NUL, 
     the length of the string is considered to be size and the destination string 
     will not be NUL-terminated (since there was no space for the NUL).  
     This keeps strlcat() from running off the end of a string.  
     In practice this should not happen (as it means that either size is incorrect or 
     that dst is not a proper “C” string).  The check exists to prevent potential security problems in incorrect code.
*/
