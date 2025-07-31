/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:03:52 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/30 19:03:53 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	map;
	int		fd;

	if (argc != 2)
		exit(1);
	if (!check_file(argv[1]))
		ft_error("Error: file format error!\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Error: file open error!\n");
	init_data(&map);
	read_map(&map, fd);
	close(fd);
	is_map_valid(&map, argv[1]);
	init_mlx(&map);
	mlx_hook(map.win, KEYPRESS, KEYPRESS_MASK, &key_hook, &map);
	mlx_hook(map.win, EXIT, EXIT_MASK, &end_game, &map);
	mlx_loop(map.mlx);
	return (0);
}
