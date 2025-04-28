/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:57:25 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/25 13:57:27 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//counts how many non-delimiter segments exist in the string
//tracks the number of segments found
//flag indicates if we're currently inside a segment
static size_t	count_segments(char const *s, char c) 
{
	size_t	count;          
	int		in_segment;     

	count = 0;
	in_segment = 0;
	while (*s)
	{
		if (*s != c && !in_segment)
		{
			in_segment = 1;
			count++;
		}
		else if (*s == c)
		{
			in_segment = 0;
		}
		s++;
	}
	return (count);
}
//frees all allocated memory in case of allocation failure
static void		cleanup_memory(char **strs, size_t allocated_count)
{
	size_t	i;

	i = 0;
	while (i < allocated_count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);     //free the array of pointers
}
//extract one segment from the string
static char		*extract_segment(char const **s, char c)
{
	char const	*start;
	char const	*end;
	char		*segment;

	start = *s;
	while (**s && **s != c)
		(*s)++;
	end = *s;
	segment = malloc(end - start + 1);
	if (!segment)
		return (NULL);
	ft_strlcpy(segment, start, end - start + 1);
	return (segment);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	size_t	segment_count;
	size_t	i;

	if (!s)
		return (NULL);
	segment_count = count_segments(s, c);
	result = malloc(sizeof(char *) * (segment_count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			result[i] = extract_segment(&s, c);
			if (!result[i])
			{
				cleanup_memory(result, i);
				return (NULL);
			}
			i++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
/*
#include <stdio.h>
#include <string.h>

void print_and_free_result(char **result) {
    if (!result) {
        printf("Result: (NULL)\n");
        return;
    }

    printf("Result: {");
    for (int i = 0; result[i]; i++) {
        printf("\"%s\"%s", result[i], result[i+1] ? ", " : "");
    }
    printf("}\n");

    // Free memory
    for (int i = 0; result[i]; i++) {
        free(result[i]);
    }
    free(result);
}

int main() {
    printf("--- Basic Tests ---\n");
    // Test 1: Normal case
    printf("Test 1: \"hello world here\" (space delimiter):\n");
    char **result1 = ft_split("hello world here", ' ');
    print_and_free_result(result1);

    // Test 2: Comma delimiter
    printf("\nTest 2: \"apple,orange,banana\" (comma delimiter):\n");
    char **result2 = ft_split("apple,orange,banana", ',');
    print_and_free_result(result2);

    printf("\n--- Edge Cases ---\n");
    // Test 3: Empty string
    printf("Test 3: \"\" (empty string):\n");
    char **result3 = ft_split("", ',');
    print_and_free_result(result3);

    // Test 4: No delimiters
    printf("\nTest 4: \"nodelimiters\" (space delimiter):\n");
    char **result4 = ft_split("nodelimiters", ' ');
    print_and_free_result(result4);

    // Test 5: Only delimiters
    printf("\nTest 5: \",,,\" (comma delimiter):\n");
    char **result5 = ft_split(",,,", ',');
    print_and_free_result(result5);

    printf("\n--- Special Cases ---\n");
    // Test 6: Leading/trailing delimiters
    printf("Test 6: \"___hello___world___\" (underscore delimiter):\n");
    char **result6 = ft_split("___hello___world___", '_');
    print_and_free_result(result6);

    // Test 7: Delimiter = null terminator
    printf("\nTest 7: \"test\" (null delimiter):\n");
    char **result7 = ft_split("test", '\0');
    print_and_free_result(result7);

    // Test 8: Repeated delimiters
    printf("\nTest 8: \"a  b   c\" (space delimiter):\n");
    char **result8 = ft_split("a  b   c", ' ');
    print_and_free_result(result8);

    printf("\n--- Error Handling ---\n");
    // Test 9: NULL input
    printf("Test 9: NULL input:\n");
    char **result9 = ft_split(NULL, ' ');
    print_and_free_result(result9);

    return 0;
}
*/
/*
DESCRIPTION
    Allocate (with malloc(3)) and returns an array of strings obtained by 
    splitting s with the character c, used as delimiter.
    The returned array must be NUL-terminated.
PARAMETERS
    s: string to split
    c: delimiter character
RETURN VALUES
    ft_split() returns an array of strings resulting from the splitting of s; 
    NULL if the memory allocation failed.
*/
