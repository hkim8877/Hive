/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:20:53 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/29 20:06:45 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// nmemb = number of elements to allocate
//size = size (in bytes) of each element 
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*memory;
	size_t			total;

	total = nmemb * size;
	if (nmemb > 0 && size > 0 && total / nmemb != size)
		return (NULL);
	memory = malloc(total);
	if (!memory)
		return (NULL);
	ft_memset(memory, 0, total);
	return (memory);
}
