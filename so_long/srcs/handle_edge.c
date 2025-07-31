/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_edge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 21:16:12 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/30 21:16:13 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill_e(char **tmp, t_data *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height
		|| tmp[y][x] == '1' || tmp[y][x] == 'E')
		return ;
	tmp[y][x] = '1';
	flood_fill_e(tmp, map, x + 1, y);
	flood_fill_e(tmp, map, x - 1, y);
	flood_fill_e(tmp, map, x, y + 1);
	flood_fill_e(tmp, map, x, y - 1);
}

static void	filling_e(char **tmp, t_data *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'C')
			{
				flood_fill_e(tmp, map, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	check_path_edge(t_data *map, int fd)
{
	char	**tmp;

	tmp = map_copy(map);
	if (!tmp)
	{
		free_map(map);
		map_error(fd, 3, map);
	}
	filling_e(tmp, map);
	if (!is_path_valid(tmp, map))
	{
		free_map(map);
		free_tmp(tmp, map->height);
		map_error(fd, 6, map);
	}
	free_tmp(tmp, map->height);
}