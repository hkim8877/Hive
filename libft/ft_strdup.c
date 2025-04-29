/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:18:28 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/22 15:18:30 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*dest;

	len = 0;
	while (s[len] != '\0')
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int    main()
{
       char t1[] = "Hello";
       char t2[] = "";
       
       printf("strdup1: %s \n", strdup(t1));
       printf("ft_strdup1: %s\n", ft_strdup(t1));
       printf("strdup2: %s\n", (strdup(t2)));
       printf("ft_strdup2: %s\n", ft_strdup(t2));
}*/
/*DESCRIPTION
       The  strdup()  function returns a pointer to a new string which is a 
       duplicate of the string s.  Memory for the new string is obtained with 
       malloc(3), and can be freed with free(3).

       The strndup() function is similar, but copies at most n bytes.  
       If s is longer than n, only n bytes are
       copied, and a terminating null byte ('\0') is added.

       strdupa()  and  strndupa()  are  similar, but use alloca(3) to allocate 
       the buffer.  They are available only when using the GNU GCC suite, and 
       suffer from the same limitations described in alloca(3).

RETURN VALUE
       On success, the strdup() function returns a pointer to the duplicated 
       string.  It returns NULL  if  insufficient memory was available, with 
       errno set to indicate the cause of the error.

ERRORS
       ENOMEM Insufficient memory available to allocate duplicate string.
*/
