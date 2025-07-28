/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:19:58 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/30 14:43:38 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	t;
	size_t	s_len;

	t = (char)c;
	s_len = ft_strlen(s);
	while (s_len > 0)
	{
		if (s[s_len] == t)
			return ((char *)s + s_len);
		s_len--;
	}
	if (*s == t)
		return ((char *)s);
	return (NULL);
}
