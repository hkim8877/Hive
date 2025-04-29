/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:01:27 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/25 14:01:33 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
/* first parameter is the file descriptor
    second parameter is the address to the character*/
/*
DESCRIPTION
    The ft_putchar_fd() function writes the character c on the file 
    descriptor fd.
PARAMETERS
    c: character to write
    fd: file descriptor on which to write
RETURN VALUES
    ft_putchar_fd() does not return anything.
*/
