#include "so_long.h"

static void init_data(t_data *map);

int main(int argc, char **argv)
{
    t_data map;
    int fd;
    
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
    draw_map(&map);
    
    return(0);    
}

static void init_data(t_data *map)
{
    map->mlx_ptr = NULL;
    map->win_ptr = NULL;
    map->player_img = NULL;
    map->wall_img = NULL;
    map->exit_img = NULL;
    map->collect_img = NULL;
    map->back_img = NULL;
    map->map = NULL;
    map->width = 0;
    map->height = 0;
    map->x = 0;
    map->y = 0;
    map->collectible = 0;
    map->jelly = 0;
    map->exit = 0;
    map->player = 0;
    map->wall = 0;
    map->moves = 0;
}





