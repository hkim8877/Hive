/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:58:28 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/30 17:58:31 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define KEYPRESS 2
# define KEYPRESS_MASK 1L
# define EXIT 17
# define EXIT_MASK 131072L

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*player_img;
	void	*wall_img;
	void	*exit_img;
	void	*collect_img;
	void	*back_img;
	char	**map;
	char	under_player;
	int		width;
	int		height;
	int		x;
	int		y;
	int		jelly;
	int		exit;
	int		player;
	int		moves;
}	t_data;

// read_map.c && check_map.c && path_utils.c
void	check_line(t_data *map, char *line);
void	read_map(t_data *map, int fd);
void	is_map_valid(t_data *map, char *file);
void	init_map(t_data *map, int fd);
void	check_chr(t_data *map);
void	check_wall(t_data *map, int fd);
void	check_path(t_data *map, int fd);
char	**map_copy(t_data *map);

// init_data.c && errors.c
void	init_data(t_data *map);
int		check_file(char *file);
void	ft_error(const char *message);
void	map_error(int fd, int code, t_data *map);
void	free_map(t_data *map);
void	free_tmp(char **tmp, int height);
void	free_all(t_data *map);

//gmae_images.c && game_keys.c && keys_utils.c
void	init_mlx(t_data *map);
void	get_images(t_data *map);
void	render_map(t_data *map);
int		key_hook(int keycode, t_data *map);
void	move_up(t_data *map, int x, int y);
void	move_down(t_data *map, int x, int y);
void	move_left(t_data *map, int x, int y);
void	move_right(t_data *map, int x, int y);
void	find_player(t_data *map);
int		find_jelly(t_data *map);
int		end_game(t_data *map);

#endif
