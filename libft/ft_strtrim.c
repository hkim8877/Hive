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
//get the [0] index of trimmed string
static int find_first(char const *ref, char const *find) 
{
    int    i;
    int    j;
         
    i  =  0;
    if (*find == '\0')
         return (0);
    while (ref[i] != '\0')
    {
        j = 0;
        while ((ref[i + j] == find[j]) && (find[j] != '\0'))
              j++;
        if (find[j] == '\0')
            return (i + j);
        i++;
    }
    return (0);
}
//get the last index of trimmed string
static int  find_next(char const *ref, char const *find)
{
    int i;
    int j;

    i = ft_strlen(ref) - 1;
    if (*find == '\0')
        return (0);
    while (i >= 0)
    {
        j = 0;
        while (((ref[i + j]) == find[j]) && (find[j] != '\0'))
            j++;
        if (find[j] == '\0')
            return (i);
    }
    return (0);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    int first;
    int next;
    
    if (s1 == NULL || set == NULL)
        return (NULL);
    first = find_first(s1, set);
    next = find_next(s1, set);
    return (ft_substr(s1, first, next - first));    
}
/*
#include <stdio.h>

int main()
{
    char t1[] = "123456123";
    char t2[] = "12";
    char t3[] = "";
    void *t4 = NULL;

    printf("1. normal_first ending index:%d\n", find_first(t1,t2));
    printf("1. normal_next beg index:%d\n", find_next(t1, t2));
    printf("1. normal_result:%s\n", ft_strtrim(t1,t2));
    printf("2. s1 = empty_first ending index:%d\n", find_first(t3,t2));
    printf("2. s1 = empty_next beg index:%d\n", find_next(t3, t2));
    printf("2. s1 = empty_result:%s\n", ft_strtrim(t3,t2));
    printf("3. set = empty_first ending index:%d\n", find_first(t1,t3));
    printf("3. set = empty_next beg index:%d\n", find_next(t1, t3));
    printf("3. set = empty_result:%s\n", ft_strtrim(t1,t3));
    printf("4. s1 = null_first ending index:%d\n", find_first(t4,t2));
    printf("4. s1 = null_next beg index:%d\n", find_next(t4, t2));
    printf("4. s1 = null_result:%s\n", ft_strtrim(t4,t2));
    printf("5. set = null_first ending index:%d\n", find_first(t1,t4));
    printf("5. set = null_next beg index:%d\n", find_next(t1, t4));
    printf("5. set = null_result:%s\n", ft_strtrim(t1,t4));
    
}
*/
/*
DESCRIPTION
    Allocate (with malloc(3)) and returns a copy of s1, without the characters specified 
    in set at the beginning and the end of s1.
PARAMETERS
    s1: string to trim
    set: characters to trim
RETURN VALUES
    ft_strtrim() returns a trimmed copy of s1; NULL if the memory allocation failed.

Trimming means removing the characters specified in the set string from the start AND 
the end of the string s1, without removing the characters from the set that are in the 
middle of s1.
*/