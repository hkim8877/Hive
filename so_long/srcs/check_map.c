#include "so_long.h"

void is_map_valid(t_data *map, char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd == -1);
        ft_error("Error: file open error!\n");
    chr_check(map);
    map->collectible = map->jelly;
    init_map(map, fd);
    wall_check(map);
    path_check(map);
}

void init_map(t_data *map, int fd);
{
    int i;

    map->map = ft_calloc(sizeof(char *), map->height + 1);
    if (!map->map)
        map_error(fd, 3);
    i = 0;
    while (i < map->height)
    {
        map->map[i] = get_next_line(fd)
        if (!map->map[i])
        {
            while (--i >= 0)
                free(map->map[i]);
            free(map->map);
            map_error(fd, 4);
        }
        i++;
    }
    close(fd);
}

void chr_check(t_data *map)
{
    if (map->jelly == 0)
        ft_error("Error: missing a collectible!\n");
    else if (map->player != 1)
        ft_error("Error: player is not one!\n");
    else if (map->exit != 1)
        ft_error("Error: exit is not one!\n");
}

void wall_check(t_data *map)
{

}

void path_check(t_data *map)
{
    
}