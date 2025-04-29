/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:57:05 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/25 13:57:07 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_nbr(unsigned int nbr, int fd)
{
	char c;

	if (nbr <= 0)
		return ;
	get_nbr(nbr / 10, fd);
	c = nbr % 10 + '0';
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (fd < 0)
		return ;
	if (n < 0)
		write(fd, "-", 1);
	else if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n == -2147483648)
		nbr = 2147483648;
	else
	{
		if (n < 0)
			n *= -1;
		nbr = (unsigned int)n;
	}
	get_nbr(nbr, fd);
}
/*
#include <stdio.h>
int main()
{
    int t1 = 2147483647;
    int t2 = -2147483648;
    int t3 = 0;
    int t4 = 2147488;

    ft_putnbr_fd(t1, 1);
    printf("\n");
    ft_putnbr_fd(t2, 1);
    printf("\n");
    ft_putnbr_fd(t3, 1);
    printf("\n");
    ft_putnbr_fd(t4, 1);
}
    */
