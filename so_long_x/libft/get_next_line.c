/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:35:05 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/06/09 16:39:49 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	read_file(int fd, char *buffer)
{
	ssize_t	byte;

	byte = read(fd, buffer, BUFFER_SIZE);
	if (byte == -1)
		return (0);
	buffer[byte] = '\0';
	return (byte);
}

static char	*extract_lines(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	return (ft_substr(buffer, 0, i));
}

static void	update_lines(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		i++;
	}
	while (buffer[i])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}

static char	*gnl_from_buffer(int fd, char *buffer)
{
	char	*next_line;
	char	*temp;

	next_line = NULL;
	while (1)
	{
		if (*buffer)
		{
			temp = extract_lines(buffer);
			if (!temp)
				return (free(next_line), NULL);
			next_line = gnl_strjoin(next_line, temp);
			free(temp);
			if (ft_strchr(next_line, '\n'))
			{
				update_lines(buffer);
				break ;
			}
		}
		if ((read_file(fd, buffer)) <= 0)
			break ;
	}
	if (next_line && *next_line)
		return (next_line);
	return (free(next_line), NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (gnl_from_buffer(fd, buffer));
}
