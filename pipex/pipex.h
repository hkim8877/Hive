#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h> // check

typedef struct s_list
{
	// int		argc;
    // int     cmd[2];
	// Pit_t   pid; // check
	char	**cmd1;
	char	**cmd2;
	char	**argv;
	char	**path;
}			t_list;

// Parsing - commands
char **cmd_array(int argc, char **argv);
char **find_path(char **envp);
char *get_cmd_path(char **path, char **cmd_array);
char	**ft_split(char const *s, char c);
char    *ft_strdup(const char *s);
int ft_strncmp(const char *s1, const char *s2, size_t n);
void    *ft_memcpy(void *dest, const void *src, size_t n);
size_t  ft_strlen(const char *s);
size_t  ft_strlcat(char *dst, const char *src, size_t size);

// Error
void ft_error(char *error);
void    ft_putstr_fd(char *s, int fd);
void ft_perror(char *error);
void	free_split(char **splited);

#endif