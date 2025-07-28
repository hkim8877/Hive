/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:20:28 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/29 20:11:12 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	if (d <= s)
	{
		while (n--)
			*(d++) = *(s++);
	}
	else
	{
		d = d + (n - 1);
		s = s + (n - 1);
		while (n--)
		{
			*(d--) = *(s--);
		}
	}
	return (dest);
}
