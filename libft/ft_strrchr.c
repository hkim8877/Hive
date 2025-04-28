/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:19:58 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/22 15:20:01 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
       char   t;
       size_t   s_len;

       t = (char)c;
       s_len = ft_strlen(s);
       while (s_len > 0)
       {
              if (s[s_len] == t)
                    return ((char *)s + s_len);
              s_len--;
       }
       if (*s == t)
              return ((char *)s);
       return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

int    main()
{
       char test[] = "hello";
       int a = '\0';

       printf("%s\n", ft_strrchr(test, a));
       printf("%s\n", strrchr(test, a));
}
*/
/*DESCRIPTION
       The strchr() function returns a pointer to the first occurrence of the character c in the string s.

       The strrchr() function returns a pointer to the last occurrence of the character c in the string s.

       The strchrnul() function is like strchr() except that if c is not found in s, then it returns a pointer
       to the null byte at the end of s, rather than NULL.

       Here "character" means "byte"; these functions do not work with wide or multibyte characters.

RETURN VALUE
       The strchr() and strrchr() functions return a pointer to the matched character or NULL if the character
       is not found.  The terminating null byte is considered part of the string, so that if c is specified as
       '\0', these functions return a pointer to the terminator.

       The strchrnul() function returns a pointer to the matched character, or a pointer to the null  byte  at
       the end of s (i.e., s+strlen(s)) if the character is not found.

char *ft_strrchr(const char *s, int c)
{
    char    *last;
    char    t;

    t = (char)c;
    last = NULL;
    
    while (*s)
    {
        if (*s == t)
            last = (char *)s;
        s++;
    }
    
    // Check for null terminator if c was '\0'
    if (t == '\0')
        return ((char *)s);
    
    return (last);
}
*/
