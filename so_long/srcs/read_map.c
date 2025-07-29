#include "so_long.h"

void read_map(t_data *map, int fd)
{
    char *line;
    int wid_check;

    line = get_next_line(fd);
    if (!line)
        map_error(fd, 1);
    map->width = ft_strlen(line) - 1;
    map->height = 1;
    check_line(map, line);
    free(line);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        check_line(map, line);
        wid_check = ft_strlen(line) - 1;
        if (wid_check != map->width)
        {
            free(line);
            map_error(fd, 2);
        }
        map->height++;
        free(line);
    }
}

void check_line(t_data *map, char *line)
{
    int i;

    i = 0;
    while (line[i] && line[i] != '\n')
    {
        if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && \
            line[i] != 'C' && line[i] != 'E')
            ft_error("Error: invalid character!\n");
        if (line[i] == 'C')
            map->jelly += 1;
        if (line[i] == 'P')
            map->player += 1;
        if (line[i] == 'E')
            map->exit += 1;
        i++;
    }
}

