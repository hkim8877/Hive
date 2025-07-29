#include "so_long.h"

void ft_error(const char *message)
{
    write(2, message, ft_strlen(message));
    exit(EXIT_FAILURE);
}

void map_error(int fd, int code, t_data *map)
{
    close(fd);
    if (code == 1)
        ft_error("Error: map file is empty or cannot be read!\n");
    if (code == 2)
        ft_error("Error: map is not rectangular!\n");
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

void free_map(t_data *map)
{
    int i;

    i = 0;
    while (i < map->height)
    {
        free(map->map[i]);
        i++;
    }
    free(map->map);
}

void free_tmp(char **tmp, int height)
{
    int i;

    if (!tmp)
        return;
    i = 0;
    while (i < height)
    {
        free(tmp[i]);
        i++;
    }
    free(tmp);
}

void free_all(t_data *map)
{
    mlx_destroy_image(map->mlx_ptr, map->player_img);
    mlx_destroy_image(map->mlx_ptr, map->wall_img);
    mlx_destroy_image(map->mlx_ptr, map->exit_img);
    mlx_destroy_image(map->mlx_ptr, map->collect_img);
    mlx_destroy_image(map->mlx_ptr, map->back_img);
    mlx_destroy_window(map->mlx_ptr, map->win_ptr);
    mlx_destroy_display(map->mlx_ptr);
    free_map(map);
    free(map->mlx_ptr);
}