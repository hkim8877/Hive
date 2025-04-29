/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:58:09 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/25 13:58:11 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && in_set(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}
/*
#include <stdio.h>

int main()
{
    char t1[] = "123456123";
    char t2[] = "12";
    char t3[] = "";
    void *t4 = NULL;

    printf("1. normal_result:%s\n", ft_strtrim(t1,t2));
    printf("2. s1 = empty_result:%s\n", ft_strtrim(t3,t2));
    printf("3. set = empty_result:%s\n", ft_strtrim(t1,t3));
    printf("4. s1 = null_result:%s\n", ft_strtrim(t4,t2));
    printf("5. set = null_result:%s\n", ft_strtrim(t1,t4));
    
}
*/
/*
DESCRIPTION
    Allocate (with malloc(3)) and returns a copy of s1, without the 
    characters specified in set at the beginning and the end of s1.
PARAMETERS
    s1: string to trim
    set: characters to trim
RETURN VALUES
    ft_strtrim() returns a trimmed copy of s1; NULL if the memory 
    allocation failed.

Trimming means removing the characters specified in the set string 
from the start AND the end of the string s1, without removing the 
characters from the set that are in the middle of s1.
*/
