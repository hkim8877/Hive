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

void	read_map(t_data *map, int fd)
{
	char	*line;
	int		wid_check;

	line = get_next_line(fd);
	if (!line)
		map_error(fd, 1, map);
	map->width = ft_strlen(line);
	if (map->width > 0 && line[map->width - 1] == '\n')
		map->width--;
	map->height = 1;
	check_line(map, line);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		check_line(map, line);
		wid_check = ft_strlen(line);
		if (wid_check > 0 && line[wid_check - 1] == '\n')
			wid_check--;
		if (wid_check != map->width)
		{
			free(line);
			map_error(fd, 2, map);
		}
		map->height++;
		free(line);
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
