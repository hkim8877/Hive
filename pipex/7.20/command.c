/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:51:10 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/20 15:51:12 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**cmd_array(int argc, char **argv)
{
	char	**cmd;

	if (argc < 1 || !argv)
		return (NULL);
	cmd = ft_split(argv[argc - 1], ' ');
	if (!cmd)
		return (NULL);
	return (cmd);
}

char	**find_path(char **envp)
{
	char	*one_line;
	char	**path;

	if (!envp)
		return (NULL);
	one_line = NULL;
	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			one_line = ft_strdup(*envp + 5);
			break ;
		}
		envp++;
	}
	if (!one_line)
		return (NULL);
	path = ft_split(one_line, ':');
	if (!path)
		return (NULL);
	free(one_line);
	return (path);
}

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;
	size_t	total;

	total = nmemb * size;
	memory = malloc(total);
	if (!memory)
		return (NULL);
	ft_memset(memory, 0, total);
	return (memory);
}

char	*get_cmd_path(char **path, char **cmd_array)
{
	int		i;
	char	*full_path;
	char	*cmd;
	size_t	path_len;
	size_t	total_len;

	if (!path || !cmd_array || !cmd_array[0])
		return (NULL);
	i = 0;
	cmd = cmd_array[0];
	while (path[i])
	{
		path_len = ft_strlen(path[i]);
		total_len = path_len + ft_strlen(cmd) + 2;
		full_path = ft_calloc(total_len, sizeof(char));
		if (!full_path)
			return (NULL);
		ft_memcpy(full_path, path[i], path_len);
		full_path[path_len] = '/';
		ft_strlcat(full_path, cmd, total_len);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}
