/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:21:56 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/22 15:21:58 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*a;
	unsigned char		b;

	a = (const unsigned char *)s;
	b = (unsigned char)c;
	while (n--)
	{
		if (*a == b)
			return ((unsigned char *)a);
		a++;
	}
	return (0);
}
