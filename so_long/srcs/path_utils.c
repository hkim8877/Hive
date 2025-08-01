/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:05:09 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/30 19:05:10 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **tmp, t_data *map, int x, int y);
static void	filling(char **tmp, t_data *map);
static int	is_path_valid(char **tmp, t_data *map);

void	check_path(t_data *map, int fd)
{
	char	**tmp;

	tmp = map_copy(map);
	if (!tmp)
	{
		free_map(map);
		map_error(fd, 3, map);
	}
	filling(tmp, map);
	if (!is_path_valid(tmp, map))
	{
		free_tmp(tmp, map->height);
		free_map(map);
		map_error(fd, 6, map);
	}
	free_tmp(tmp, map->height);
}

char	**map_copy(t_data *map)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_calloc(sizeof(char *), map->height + 1);
	if (!tmp)
		return (NULL);
	while (i < map->height)
	{
		tmp[i] = ft_strdup(map->map[i]);
		if (!tmp[i])
		{
			free_tmp(tmp, map->height);
			return (NULL);
		}
		i++;
	}
	return (tmp);
}

static void	flood_fill(char **tmp, t_data *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height
		|| tmp[y][x] == '1')
		return ;
	tmp[y][x] = '1';
	flood_fill(tmp, map, x + 1, y);
	flood_fill(tmp, map, x - 1, y);
	flood_fill(tmp, map, x, y + 1);
	flood_fill(tmp, map, x, y - 1);
}

static void	filling(char **tmp, t_data *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				flood_fill(tmp, map, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
}

static int	is_path_valid(char **tmp, t_data *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (tmp[y][x] == 'C' || tmp[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
