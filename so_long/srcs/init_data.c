#include "so_long.h"

void init_data(t_data *map)
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

void check_file(char *file)
{
    char *ext;
    size_t file_len;
    size_t ext_len;

    if (file == NULL)
        return (0);
    ext = ".ber";
    file_len = ft_strlen(file);
    ext_len = ft_strlen(ext);
    if (file_len < ext_len)
        return (0);
    if (ft_strncmp(file + (file_len - ext_len), ext, ext_len) == 0)
	{
		return (1);
	}
	return (0);
}