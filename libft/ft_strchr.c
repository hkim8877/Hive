/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:22:06 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/22 15:22:08 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	t;

	t = (char)c;
	while (*s != '\0')
	{
		if (*s == t)
			return ((char *)s);
		s++;
	}
	if (*s == t)
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char test[]= "Hello";
    int c = '\0';

    printf("%s\n", ft_strchr(test, c));
    printf("%s\n", strchr(test,c));
    // printf("%s\n", test);
}
    DESCRIPTION
    The strchr() function locates the first occurence of c (converted to a char) 
    in the string pointed to by s. The terminating null character is considered 
    to be part of the string; therefor if c is '\0', the function locate the 
    terminating '\0'.
    RETURN VALUES
    The function strchr() return a pointer to the located character, or NULL 
    if the character does not appear in the string.
*/
