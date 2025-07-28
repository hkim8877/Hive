/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:22:06 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/22 15:22:08 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	t;

	t = (char)c;
	while (*s != '\0')
	{
		if (*s == t)
			return ((char *)s);
		s++;
	}
	if (*s == t)
		return ((char *)s);
	return (NULL);
}
