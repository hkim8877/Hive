#include "pipex.h"

void ft_perror(char *error, t_list *pipex, int exit_code)
{
    perror(error);
    free_pipex(pipex);
    exit(exit_code);
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

void    free_pipex(t_list *pipex)
{
    if (pipex == NULL)
        return ;
    if (pipex->cmd1)
        free_split(pipex->cmd1);
    if (pipex->cmd2)
        free_split(pipex->cmd2);
    if (pipex->path)
        free_split(pipex->path);
    pipex->cmd1 = NULL; 
    pipex->cmd2 = NULL;  
    pipex->path = NULL;   
}

void cleanup(t_list *pipex, int exit_code)
{
   free_pipex(pipex);
   exit(exit_code);
}