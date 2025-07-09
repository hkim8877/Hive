/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:18:10 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/07 22:18:11 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	cleanup_memory(char **strs, size_t allocated_count)
{
	size_t	i;

	i = 0;
	while (i < allocated_count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static char	*extract_segment(char const **s, char c)
{
	char const	*start;
	char const	*end;
	char		*segment;
	size_t		len;
	size_t		i;

	start = *s;
	while (**s && **s != c)
		(*s)++;
	end = *s;
	len = end - start;
	segment = malloc(len + 1);
	if (!segment)
		return (NULL);
	i = 0;
	while (i < len)
	{
		segment[i] = start[i];
		i++;
	}
	segment[len] = '\0';
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
				cleanup_memory(result, i);
			i++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
