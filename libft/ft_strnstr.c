/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:19:02 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/22 15:19:06 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
     size_t    i;
     size_t    j;
          
     i  =  0;
     if (*little == '\0')
          return ((char *)big);
     while (big[i] != '\0' && i < len)
     {
          j = 0;
	     while ((little[j] != '\0') && ((i + j) < len) && (big[i + j] == little[j]))
               j++;
		if (little[j] == '\0')
               return ((char *)&big[i]);
	     i++;
     }
     return (NULL);
}
/*
#include <stdio.h>
#include <bsd/string.h>

int  main()
{
    char test1[] = "123456789";
    char test2[] = "456";
    char test3[3];
    
    printf("strnstr1: %s\n", (char *)strnstr(test1,test2,8));
    printf("ft_strnstr1: %s\n", (char *)ft_strnstr(test1,test2,8));
    printf("strnstr2: %s\n", (char *)strnstr(test1,test2,0));
    printf("ft_strnstr2: %s\n", (char *)ft_strnstr(test1,test2,0));
    printf("strnstr3: %s\n", (char *)strnstr(test1,test2,5));
    printf("ft_strnstr3: %s\n", (char *)ft_strnstr(test1,test2,5));
    printf("strnstr4: %s\n", (char *)strnstr(test1,test3,15));
    printf("ft_strnstr4: %s\n", (char *)ft_strnstr(test1,test3,15));
    printf("strnstr5: %s\n", (char *)strnstr(test3,test1,3));
    printf("ft_strnstr5: %s\n", (char *)ft_strnstr(test3,test1,3));
}
    */
/*DESCRIPTION
     The strnstr() function locates the first occurrence of the null-terminated string little in the string
     big, where not more than len characters are searched.  Characters that appear after a ‘\0’ character are
     not searched.  Since the strnstr() function is a FreeBSD specific API, it should only be used when porta‐
     bility is not a concern.

RETURN VALUES
     If little is an empty string, big is returned; if little occurs nowhere in big, NULL is returned; other‐
     wise a pointer to the first character of the first occurrence of little is returned.

EXAMPLES
     The following sets the pointer ptr to NULL, because only the first 4 characters of largestring are
     searched:

           const char *largestring = "Foo Bar Baz";
           const char *smallstring = "Bar";
           char *ptr;

           ptr = strnstr(largestring, smallstring, 4);
*/
