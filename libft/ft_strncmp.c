/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:22:16 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/22 15:22:19 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        if (s1[i] != s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        if (s1[i] == '\0' || s2[i] == '\0')
            break;
        i++;
    }
    return (0);
}
    
#include <stdio.h>
#include <string.h>

int main()
{
    // Test cases
    printf("1. Basic equal strings: %d vs %d\n", 
           strncmp("abc", "abc", 3), ft_strncmp("abc", "abc", 3));
    
    printf("2. First string shorter: %d vs %d\n", 
           strncmp("ab", "abc", 3), ft_strncmp("ab", "abc", 3));
    
    printf("3. Second string shorter: %d vs %d\n", 
           strncmp("abc", "ab", 3), ft_strncmp("abc", "ab", 3));
    
    printf("4. Compare only first 2 chars: %d vs %d\n", 
           strncmp("abc", "abd", 2), ft_strncmp("abc", "abd", 2));
    
    printf("5. Compare beyond null terminator: %d vs %d\n", 
           strncmp("ab\0c", "ab\0d", 4), ft_strncmp("ab\0c", "ab\0d", 4));
    
    printf("6. Extended ASCII (\\200): %d vs %d\n", 
           strncmp("abc\200", "abc\0", 6), ft_strncmp("abc\200", "abc\0", 6));
    
    printf("7. Compare zero bytes: %d vs %d\n", 
           strncmp("abc", "def", 0), ft_strncmp("abc", "def", 0));
    
    printf("8. Empty strings: %d vs %d\n", 
           strncmp("", "", 1), ft_strncmp("", "", 1));
    
    printf("9. One empty string: %d vs %d\n", 
           strncmp("abc", "", 3), ft_strncmp("abc", "", 3));
    
    printf("10. Non-ASCII chars: %d vs %d\n", 
           strncmp("\xff", "\xfe", 1), ft_strncmp("\xff", "\xfe", 1));
    
    return (0);
}

/*DESCRIPTION
       The  strcmp()  function compares the two strings s1 and s2.  The locale is not taken into account (for a locale-aware compari‐
       son, see strcoll(3)).  The comparison is done using unsigned characters.

       strcmp() returns an integer indicating the result of the comparison, as follows:

       • 0, if the s1 and s2 are equal;

       • a negative value if s1 is less than s2;

       • a positive value if s1 is greater than s2.

       The strncmp() function is similar, except it compares only the first (at most) n bytes of s1 and s2.

RETURN VALUE
       The strcmp() and strncmp() functions return an integer less than, equal to, or greater than zero if s1 (or the first  n  bytes
       thereof) is found, respectively, to be less than, to match, or be greater than s2.

*/