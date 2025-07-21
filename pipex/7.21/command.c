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
#include <ctype.h>

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
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (!*envp)
		return (NULL);
	one_line = ft_strdup(*envp + 5);
	if (!one_line)
		return (NULL);
	path = ft_split(one_line, ':');
	if (!path)
	{
		free(one_line);
		return (NULL);
	}
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
// char **cmd_array(int argc, char **argv)
// {
//     char **cmd;
//     char *cmd_str; // The raw string like " " or "ls -l"

// 	cmd_str = argv[argc - 1];
//     if (argc < 1 || !argv || !cmd_str)
//         return (NULL);

//     // Check if the command string is effectively empty (contains only whitespace or is empty)
//     int is_effectively_empty = 1;
//     for (size_t i = 0; cmd_str[i] != '\0'; i++) {
//         if (!isspace((unsigned char)cmd_str[i])) {
//             is_effectively_empty = 0;
//             break;
//         }
//     }

//     if (is_effectively_empty) {
//         // For an effectively empty command, we explicitly create an array
//         // where the first element is NULL. This signals to get_cmd_path
//         // (and then exec_and_error, or your current child_process check)
//         // that it's an empty command.
//         cmd = ft_calloc(2, sizeof(char*)); // One for NULL, one for the array terminator
//         if (!cmd)
//             return (NULL); // Memory allocation failure
//         cmd[0] = NULL; // Indicate empty command
//         cmd[1] = NULL; // Null-terminate the array
//         return (cmd);
//     }

//     // If not effectively empty, proceed with ft_split
//     cmd = ft_split(cmd_str, ' ');

//     // This 'if (!cmd)' handles malloc failures from ft_split
//     // OR if ft_split returns NULL for a string like " " (depending on its impl.)
//     if (!cmd)
//         return (NULL);

//     // Additional check: if ft_split returns an array but the first element
//     // is an empty string (""), this also signifies an empty command.
//     // Convert it to NULL so the check `if (!pipex->cmd1[0])` works.
//     if (cmd[0] && cmd[0][0] == '\0') {
//         free(cmd[0]); // Free the empty string allocated by ft_split
//         cmd[0] = NULL; // Set it to NULL
//     }

//     return (cmd);
// }

char	*get_cmd_path(char **path, char **cmd_array)
{
	char	*full_path;
	char	*cmd;
	char	*current_path;
	size_t	len;

	if (!path || !cmd_array || !cmd_array[0] || cmd_array[0][0] == '\0')
		return (NULL);
	cmd = cmd_array[0];
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	while (*path)
	{
		current_path = *path;
		len = ft_strlen(*path) + ft_strlen(cmd) + 2;
		if (!(full_path = ft_calloc(len, sizeof(char))))
			return (NULL);
		ft_strlcpy(full_path, current_path, len);
		ft_strlcat(full_path, "/", len);
		ft_strlcat(full_path, cmd, len);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		path++;
	}
	return (NULL);
}