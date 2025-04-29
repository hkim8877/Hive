/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:21:56 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/22 15:21:58 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*a;
	unsigned char		b;

	a = (const unsigned char *)s;
	b = (unsigned char)c;
	while (n--)
	{
		if (*a == b)
			return ((unsigned char *)a);
		a++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    unsigned char test[] = "hello";
    unsigned char test2[10];
    char t1 = 'l';
    char t2 = '\0';

    printf("memchr: %s\n", (char *)memchr(test,t1,3));
    printf("ft_memchr: %s\n", (char *)ft_memchr(test,t1,3));
    printf("memchr: %s\n", (char *)memchr(test,t1,0));
    printf("ft_memchr: %s\n", (char *)ft_memchr(test,t1,0));
    printf("memchr: %s\n", (char *)memchr(test2,t1,3));
    printf("ft_memchr: %s\n", (char *)ft_memchr(test2,t1,3));
    printf("memchr: %s\n", (char *)memchr(test,t2,3));
    printf("ft_memchr: %s\n", (char *)ft_memchr(test,t2,3));
}
*/
/*DESCRIPTION
The  memchr()  function  scans the initial n bytes of the memory area pointed
to by s for the first instance of c.  Both c and the bytes of the memory area
pointed to by s are interpreted as unsigned char.

The memrchr() function is like the memchr() function, except that it searches 
backward from the end  of the n bytes pointed to by s instead of forward from 
the beginning.

The  rawmemchr()  function  is similar to memchr(): it assumes (i.e., the 
programmer knows for certain) that an instance of c lies somewhere in the 
memory area starting at the location pointed to by  s,  and so  performs  an  
optimized  search  for  c (i.e., no use of a count argument to limit the range 
of the search).  If an instance of c is not found, the results are 
unpredictable.  
The  following  call  is  a fast means of locating a string's terminating 
null byte:

    char *p = rawmemchr(s, '\0');

RETURN VALUE
The  memchr()  and  memrchr()  functions return a pointer to the matching byte 
or NULL if the character does not occur in the given memory area.
The rawmemchr() function returns a pointer to the matching byte, if one is
found. If no matching  byte is found, the result is unspecified. */
