/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:56:41 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/25 13:56:43 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}
/*
#include <fcntl.h>   // for open()
#include <unistd.h>  // for write(), close()
#include <stdio.h>   // for perror()

void ft_putstr_fd(char *s, int fd);

int main(void)
{
    int fd;

    // Test 1: Write to standard output (fd = 1)
    ft_putstr_fd("Test 1: Hello, stdout!\n", 1);

    // Test 2: Write to standard error (fd = 2)
    ft_putstr_fd("Test 2: Hello, stderr!\n", 2);

    // Test 3: Write NULL string (should do nothing)
    ft_putstr_fd(NULL, 1);

    // Test 4: Invalid file descriptor (should do nothing)
    ft_putstr_fd("Test 4: Should not print!\n", -1);

    // Test 5: Write to a file
    fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("open");
        return (1);
    }
    ft_putstr_fd("Test 5: This should be written into a file.\n", fd);
    close(fd);

    // Test 6: Empty string
    ft_putstr_fd("", 1);

    return (0);
}
*/
