/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:05:15 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/30 19:05:17 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	make_map(t_data *map, char *line, int fd, int first_line)
{
	int	check_wid;

	check_line(map, line);
	check_wid = ft_strlen(line);
	if (check_wid > 0 && line[check_wid - 1] == '\n')
		check_wid--;
	if (first_line)
		map->width = check_wid;
	else
	{
		if (check_wid != map->width)
		{
			free(line);
			map_error(fd, 2, map);
		}
	}
	map->height++;
	free(line);
}

void	read_map(t_data *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		map_error(fd, 1, map);
	make_map(map, line, fd, 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		make_map(map, line, fd, 0);
	}
}

void	check_line(t_data *map, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P'
			&& line[i] != 'C' && line[i] != 'E')
			ft_error("Error: invalid character!\n");
		if (line[i] == 'C')
			map->jelly++;
		if (line[i] == 'P')
			map->player++;
		if (line[i] == 'E')
			map->exit++;
		i++;
	}
}
