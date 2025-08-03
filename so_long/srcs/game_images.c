/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:43:34 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/30 18:43:35 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_data *map)
{
	int	wid;
	int	hei;

	wid = map->width;
	hei = map->height;
	map->mlx = mlx_init();
	if (!map->mlx)
	{
		free_map(map);
		ft_error("Error: mlx_init function error\n");
	}
	map->win = mlx_new_window(map->mlx, wid * 64, hei * 64, "so_long");
	if (!map->win)
	{
		free_map(map->mlx);
		ft_error("Error: mlx_new_window function error!\n");
	}
	get_images(map);
}

void	get_images(t_data *map)
{
	int	wid;
	int	hei;

	map->player_img = mlx_xpm_file_to_image(map->mlx,
			"textures/player.xpm", &wid, &hei);
	map->wall_img = mlx_xpm_file_to_image(map->mlx,
			"textures/wall.xpm", &wid, &hei);
	map->exit_img = mlx_xpm_file_to_image(map->mlx,
			"textures/exit.xpm", &wid, &hei);
	map->collect_img = mlx_xpm_file_to_image(map->mlx,
			"textures/jelly.xpm", &wid, &hei);
	map->back_img = mlx_xpm_file_to_image(map->mlx,
			"textures/background.xpm", &wid, &hei);
	if (!map->player_img || !map->wall_img || !map->exit_img
		|| !map->collect_img || !map->back_img)
	{
		free_all(map);
		ft_error("Error: image file error!\n");
		
	}
	render_map(map);
}

void	render_map(t_data *map)
{
	int		y;
	int		x;
	char	*img;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
				img = map->player_img;
			else if (map->map[y][x] == 'C')
				img = map->collect_img;
			else if (map->map[y][x] == 'E')
				img = map->exit_img;
			else if (map->map[y][x] == '0')
				img = map->back_img;
			else if (map->map[y][x] == '1')
				img = map->wall_img;
			mlx_put_image_to_window(map->mlx, map->win, img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
