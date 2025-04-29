/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:12:28 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/29 20:13:31 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = (char *)malloc(s1_len + s2_len + 1);
	if (dst == 0)
		return (NULL);
	ft_memcpy(dst, s1, s1_len);
	ft_memcpy(dst + s1_len, s2, s2_len + 1);
	dst[s1_len + s2_len] = '\0';
	return (dst);
}
/*
#include <stdio.h>
int main()
{
    char t1[] = "Hello ";
    char t2[] = "World!";
    char t3[] = "";
    void *t4 = NULL;
    char *result;

    result = ft_strjoin(t1, t2);
    printf("1. normal: %s\n", result);
    free(result);

    result = ft_strjoin(t3, t1);
    printf("2. s1 = empty: %s\n", result);
    free(result);

    result = ft_strjoin(t2, t3);
    printf("3. s2 = empty: %s\n", result);
    free(result);

    result = ft_strjoin(t4, t1);
    printf("4. s1 = NULL: %s\n", result);
    free(result);

    result = ft_strjoin(t1, t4);
    printf("5. s2 = NULL: %s\n", result);
    free(result);

    return (0);

}
DESCRIPTION
Allocate (with malloc(3)) and returns a new string resulting i
from the concatenation of s1 and s2.
PARAMETERS
    s1: prefix string
    s2: suffix string
RETURN VALUES
    ft_strjoin() returns the new string; NULL if the memory 
allocation failed    
*/
