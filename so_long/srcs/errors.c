/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:33:32 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/30 18:33:34 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(const char *message)
{
	write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

void	map_error(int fd, int code, t_data *map)
{
	close(fd);
	if (code == 1)
		ft_error("Error: map file is empty or cannot be read!\n");
	if (code == 2)
		ft_error("Error: map size error or has empty lines!\n");
	if (code == 3)
		ft_error("Error: memory allocation failed!\n");
	if (code == 4)
		ft_error("Error: get_next_line failed while filing map!\n");
	if (code == 5)
	{
		free_map(map);
		ft_error("Error: map is not surrounded by walls!\n");
	}
	if (code == 6)
		ft_error("Error: invliad path!\n");
}

void	free_map(t_data *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	free_tmp(char **tmp, int height)
{
	int	i;

	if (!tmp)
		return ;
	i = 0;
	while (i < height)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	free_all(t_data *map)
{
	if (map->player_img)
		mlx_destroy_image(map->mlx, map->player_img);
	if (map->wall_img)
		mlx_destroy_image(map->mlx, map->wall_img);
	if (map->exit_img)
		mlx_destroy_image(map->mlx, map->exit_img);
	if (map->collect_img)
		mlx_destroy_image(map->mlx, map->collect_img);
	if (map->back_img)
		mlx_destroy_image(map->mlx, map->back_img);
	if (map->mlx && map->win)
		mlx_destroy_window(map->mlx, map->win);
	if (map->mlx)
		mlx_destroy_display(map->mlx);
	free_map(map);
	free(map->mlx);
}