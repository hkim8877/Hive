/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:52:10 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/30 18:52:12 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *map)
{
	int	x;
	int	y;

	find_player(map);
	x = map->x;
	y = map->y;
	if (keycode == KEY_W)
		move_up(map, x, y);
	else if (keycode == KEY_S)
		move_down(map, x, y);
	else if (keycode == KEY_A)
		move_left(map, x, y);
	else if (keycode == KEY_D)
		move_right(map, x, y);
	else if (keycode == KEY_ESC)
		end_game(map);
	mlx_clear_window(map->mlx, map->win);
	render_map(map);
	return (0);
}

void	move_up(t_data *map, int x, int y)
{
	int	i;
	int	j;

	find_player(map);
	i = map->x;
	j = map->y;
	if (map->map[j - 1][i] != '1' && map->map[j - 1][i] != 'E')
	{
		map->map[y][x] = '0';
		map->map[j - 1][i] = 'P';
		map->moves++;
		ft_printf("Moves: %i\n", map->moves);
	}
	else if (map->map[j - 1][i] == 'E')
	{
		if (!find_jelly(map))
		{
			map->moves++;
			ft_printf("Moves: %i\n", map->moves);
			ft_printf("Enjoy your jellys!\n");
			end_game(map);
		}
	}
}

void	move_down(t_data *map, int x, int y)
{
	int	i;
	int	j;

	find_player(map);
	i = map->x;
	j = map->y;
	if (map->map[j + 1][i] != '1' && map->map[j + 1][i] != 'E')
	{
		map->map[y][x] = '0';
		map->map[j + 1][i] = 'P';
		map->moves++;
		ft_printf("Moves: %i\n", map->moves);
	}
	else if (map->map[j + 1][i] == 'E')
	{
		if (!find_jelly(map))
		{
			map->moves++;
			ft_printf("Moves: %i\n", map->moves);
			ft_printf("Enjoy your jellys!\n");
			end_game(map);
		}
	}
}

void	move_left(t_data *map, int x, int y)
{
	int	i;
	int	j;

	find_player(map);
	i = map->x;
	j = map->y;
	if (map->map[j][i - 1] != '1' && map->map[j][i - 1] != 'E')
	{
		map->map[y][x] = '0';
		map->map[j][i - 1] = 'P';
		map->moves++;
		ft_printf("Moves: %i\n", map->moves);
	}
	else if (map->map[j][i - 1] == 'E')
	{
		if (!find_jelly(map))
		{
			map->moves++;
			ft_printf("Moves: %i\n", map->moves);
			ft_printf("Enjoy your jellys!\n");
			end_game(map);
		}
	}
}

void	move_right(t_data *map, int x, int y)
{
	int	i;
	int	j;

	find_player(map);
	i = map->x;
	j = map->y;
	if (map->map[j][i + 1] != '1' && map->map[j][i + 1] != 'E')
	{
		map->map[y][x] = '0';
		map->map[j][i + 1] = 'P';
		map->moves++;
		ft_printf("Moves: %i\n", map->moves);
	}
	else if (map->map[j][i + 1] == 'E')
	{
		if (!find_jelly(map))
		{
			map->moves++;
			ft_printf("Moves: %i\n", map->moves);
			ft_printf("Enjoy your jellys!\n");
			end_game(map);
		}
	}
}
