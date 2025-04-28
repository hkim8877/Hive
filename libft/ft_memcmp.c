/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:18:12 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/22 15:18:20 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *a;
    const unsigned char *b;
    size_t  i;

    a = (const unsigned char *)s1;
    b = (const unsigned char *)s2;
    i = 0;
    while (i < n)
    {
        if (a[i] != b[i])
            return (a[i] - b[i]);
        i++;
    }
    return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
    printf("1. memcmp: %d, ft_memcmp: %d\n", memcmp("abc", "abc", 3), ft_memcmp("abc", "abc", 3));
	printf("2. memcmp: %d, ft_memcmp: %d\n", memcmp("abc", "ABC", 3), ft_memcmp("abc", "ABC", 3));
	printf("3. memcmp: %d, ft_memcmp: %d\n", memcmp("ABC", "abc", 3), ft_memcmp("ABC", "abc", 3));
	printf("4. memcmp: %d, ft_memcmp: %d\n", memcmp("abc", "ab", 2),  ft_memcmp("abc", "ab", 2));
	printf("5. memcmp: %d, ft_memcmp: %d\n", memcmp("", "", 0), ft_memcmp("", "", 0));

}
*/
/*DESCRIPTION
The  memcmp() function compares the first n bytes (each interpreted as unsigned char) of the memory ar‐
eas s1 and s2.

RETURN VALUE
The memcmp() function returns an integer less than, equal to, or greater than zero if the first n bytes
of s1 is found, respectively, to be less than, to match, or be greater than the first n bytes of s2.

For a nonzero return value, the sign is determined by the sign of the difference between the first pair
of bytes (interpreted as unsigned char) that differ in s1 and s2.

If n is zero, the return value is zero.*/
