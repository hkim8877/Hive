/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:57:25 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/30 15:44:42 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//counts how many non-delimiter segments exist in the string
//'count' tracks the number of segments found
//'in_segment' flag indicates if we're currently inside a segment
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
static void	*cleanup_memory(char **strs, size_t allocated_count)
{
	size_t	i;

	i = 0;
	while (i < allocated_count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

//extract one segment from the string
static char	*extract_segment(char const **s, char c)
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

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_segments(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			result[i] = extract_segment(&s, c);
			if (!result[i])
				return (cleanup_memory(result, i));
			i++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
