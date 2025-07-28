/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:51:57 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/20 15:51:59 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_error(t_list *pipex, char *cmd_path, char **cmd, char **envp)
{
	if (!cmd || !cmd[0] || cmd[0][0] == '\0')
		cleanup("command not found\n", pipex, 127);
	if (!cmd_path)
	{
		if (cmd[0][0] == '/' || cmd[0][0] == '.')
		{
			if (access(cmd[0], F_OK) == 0 && access(cmd[0], X_OK) != 0)
				cleanup("Permission denied\n", pipex, 126);
			else if (access(cmd[0], F_OK) != 0)
				cleanup("No such file or directory\n", pipex, 127);
		}
		else
			cleanup("command not found\n", pipex, 127);
	}
	else
	{
		execve(cmd_path, cmd, envp);
		free(cmd_path);
		if (errno == EACCES)
			ft_perror("Permission denied", pipex, 126);
		else if (errno == ENOENT)
			ft_perror("No such file or directory", pipex, 127);
		else
			ft_perror("Command not found", pipex, 127);
	}
}

static void	child_process_1(t_list *pipex, char **argv, char **envp, int *fd)
{
	char	*cmd_path;
	int		infile;

	close(fd[0]);
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		close(fd[1]);
		ft_perror("infile open error", pipex, EXIT_FAILURE);
	}
	if (dup2(infile, STDIN_FILENO) < 0 || dup2(fd[1], STDOUT_FILENO) < 0)
	{
		close(infile);
		close(fd[1]);
		ft_perror("dup2", pipex, EXIT_FAILURE);
	}
	close(infile);
	close(fd[1]);
	cmd_path = get_cmd_path(pipex->path, pipex->cmd1[0]);
	exec_error(pipex, cmd_path, pipex->cmd1, envp);
}

static void	child_process_2(t_list *pipex, char **argv, char **envp, int *fd)
{
	char	*cmd_path;
	int		outfile;

	close(fd[1]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		close(fd[0]);
		ft_perror("outfile open error", pipex, EXIT_FAILURE);
	}
	if (dup2(fd[0], STDIN_FILENO) < 0 || dup2(outfile, STDOUT_FILENO) < 0)
	{
		close(outfile);
		close(fd[0]);
		ft_perror("dup2", pipex, EXIT_FAILURE);
	}
	close(fd[0]);
	close(outfile);
	cmd_path = get_cmd_path(pipex->path, pipex->cmd2[0]);
	exec_error(pipex, cmd_path, pipex->cmd2, envp);
}

int	process(t_list *pipex, char **argv, char **envp)
{
	int		fd[2];
	int		status[2];
	pid_t	pid[2];

	if (pipe(fd) == -1)
		ft_perror("pipe error", pipex, 1);
	pid[0] = fork();
	if (pid[0] < 0)
		ft_perror("fork error", pipex, 1);
	if (pid[0] == 0)
		child_process_1(pipex, argv, envp, fd);
	pid[1] = fork();
	if (pid[1] < 0)
		ft_perror("fork error", pipex, 1);
	if (pid[1] == 0)
		child_process_2(pipex, argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], &status[0], 0);
	waitpid(pid[1], &status[1], 0);
	if (WIFEXITED(status[1]))
		return (WEXITSTATUS(status[1]));
	return (128 + WTERMSIG(status[1]));
}
