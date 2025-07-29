#include "so_long.h"

void init_mlx(t_data *map)
{
    int wid;
    int hei;
    
    wid = map->width;
    hei = map->height;
    map->mlx_ptr = mlx_init();
    if (!map->mlx_ptr)
    {   
        free_map(map);
        ft_error("Error: mlx_init function error\n");
    }
    map->win_ptr = mlx_new_window(map->mlx_ptr, wid * 64, hei * 64, "so_long");
    if (!map->win_ptr)
    {
        free_map(map->mlx_ptr);
        ft_error("Error: mlx_new_window function error!\n");
    }
    get_images(map);
}

void get_images(t_data *map)
{
    int wid;
    int hei;

    map->player_img = mlx_xpm_file_to_image(map->mlx_ptr, "assets/player.xpm", &wid, &hei);
    map->wall_img = mlx_xpm_file_to_image(map->mlx_ptr, "assets/wall.xpm", &wid, &hei);
    map->exit_img = mlx_xpm_file_to_image(map->mlx_ptr, "assets/exit.xpm", &wid, &hei);
    map->collect_img = mlx_xpm_file_to_image(map->mlx_ptr, "assets/jelly.xpm", &wid, &hei);
    map->back_img = mlx_xpm_file_to_image(map->mlx_ptr, "assets/background.xpm", &wid, &hei);
    if (!map->player_img || !map->wall_img || !map->exit_img || !map->collect_img || !map->back_img)
    {
        free_all(map->win_ptr);
        ft_error("Error: image file error!\n");
    }
    render_map(map);
}

void render_map(t_data *map)
{
    int y;
    int x;
    char *img;

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
            mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, img, x * 64, y * 64);
            x++;
        }
        y++;
    }
}