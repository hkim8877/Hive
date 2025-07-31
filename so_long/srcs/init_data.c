/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:58:30 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/30 18:58:31 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *map)
{
	map->mlx = NULL;
	map->win = NULL;
	map->player_img = NULL;
	map->wall_img = NULL;
	map->exit_img = NULL;
	map->collect_img = NULL;
	map->back_img = NULL;
	map->map = NULL;
	map->under_player = '0';
	map->width = 0;
	map->height = 0;
	map->x = 0;
	map->y = 0;
	map->jelly = 0;
	map->exit = 0;
	map->player = 0;
	map->moves = 0;
}

int	check_file(char *file)
{
	char	*ext;
	size_t	file_len;
	size_t	ext_len;

	if (file == NULL)
		return (0);
	ext = ".ber";
	file_len = ft_strlen(file);
	ext_len = ft_strlen(ext);
	if (file_len < ext_len)
		return (0);
	if (ft_strncmp(file + (file_len - ext_len), ext, ext_len) == 0)
		return (1);
	return (0);
}
