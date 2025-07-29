#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
// # include <X11/X.h>
// # include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
    void *mlx_ptr;
    void *win_ptr;
    void *player_img
    void *wall_img;
    void *exit_img;
    void *collect_img;
    void *back_img;
    char **map;
    int width;
    int height;
    int x;
    int y;
    int collectible;
    int jelly;
    int exit;
    int player;
    int moves;
}   t_data;

// read_map.c
void check_line(t_data *map, char *line);
void read_map(t_data *map, int fd);

// check_map.c
void is_map_valid(t_data *map, char *file);
void init_map(t_data *map, int fd);
void chr_check(t_data *map);
void wall_check(t_data *map);

// path_utils.c

// errors.c
void check_file(char *file);
void ft_error(const char *message);
void map_error(int fd, int code);


#endif 