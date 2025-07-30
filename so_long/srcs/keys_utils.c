/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:01:44 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/30 19:01:45 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_data *map)
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
				map->x = x;
				map->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	find_jelly(t_data *map)
{
	int	y;
	int	x;
	int	collectible;

	y = 0;
	collectible = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'C')
				collectible++;
			x++;
		}
		y++;
	}
	return (collectible);
}

int	end_game(t_data *map)
{
	free_all(map);
	exit(1);
}
