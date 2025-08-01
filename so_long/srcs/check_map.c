/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:30:01 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/30 18:30:03 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_map_valid(t_data *map, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Error: file open error!\n");
	check_chr(map);
	if (map->width > 60 || map->height > 34)
		map_error(fd, 2, map);
	init_map(map, fd);
	check_wall(map, fd);
	check_path(map, fd);
}

void	check_chr(t_data *map)
{
	if (map->jelly == 0)
		ft_error("Error: missing a collectible!\n");
	else if (map->player != 1)
		ft_error("Error: player is not one!\n");
	else if (map->exit != 1)
		ft_error("Error: exit is not one!\n");
}

void	init_map(t_data *map, int fd)
{
	int	i;

	map->map = ft_calloc(sizeof(char *), map->height + 1);
	if (!map->map)
		map_error(fd, 3, map);
	i = 0;
	while (i < map->height)
	{
		map->map[i] = get_next_line(fd);
		if (!map->map[i])
		{
			while (--i >= 0)
				free(map->map[i]);
			free(map->map);
			map_error(fd, 4, map);
		}
		i++;
	}
	close(fd);
}

void	check_wall(t_data *map, int fd)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1')
			map_error(fd, 5, map);
		if (map->map[map->height - 1][i] != '1')
			map_error(fd, 5, map);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1')
			map_error(fd, 5, map);
		if (map->map[i][map->width - 1] != '1')
			map_error(fd, 5, map);
		i++;
	}
}
