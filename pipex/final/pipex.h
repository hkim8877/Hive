/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:51:50 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/20 15:51:52 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <errno.h>

typedef struct s_list
{
	char	**cmd1;
	char	**cmd2;
	char	**path;
}		t_list;

// Child process
int		process(t_list *pipex, char **argv, char **envp);
char	**cmd_array(int argc, char **argv);
char	**find_path(char **envp);
char	*get_cmd_path(char **path, char *cmd);

// Error and free memory
void	ft_perror(char *error, t_list *pipex, int exit_code);
void	free_split(char **splited);
void	free_pipex(t_list *pipex);
void	cleanup(char *error, t_list *pipex, int exit_code);

// Utils - from libft
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
