#include "pipex.h"

void ft_error(char *error)
{
    ft_putstr_fd(error, 2);
    exit(1);
}

void ft_perror(char *error)
{
    perror(error);
    //free 
    exit(EXIT_FAILURE);
}

void    ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

void	free_split(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}