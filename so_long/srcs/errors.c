#include "so_long.h"

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

void ft_error(const char *message)
{
    write(2, message, ft_strlen(message));
    exit(EXIT_FAILURE);
}

void map_error(int fd, int code)
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
}