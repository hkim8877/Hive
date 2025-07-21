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

static void	child_process_1(t_list *pipex, char **argv, char **envp, int *fd)
{
	char	*cmd_path;
	int		infile;

	close(fd[0]);
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		ft_perror("infile open error", pipex, EXIT_FAILURE);
	if (dup2(infile, STDIN_FILENO) < 0 || dup2(fd[1], STDOUT_FILENO) < 0)
		ft_perror("dup2", pipex, EXIT_FAILURE);
	close(infile);
	close(fd[1]);
	cmd_path = get_cmd_path(pipex->path, pipex->cmd1);
	if (!cmd_path)
	{
		ft_putstr_fd("command not found\n", 2);
		cleanup(pipex, 127);
	}
	execve(cmd_path, pipex->cmd1, envp);
	free(cmd_path);
	exit(EXIT_FAILURE);
}

static void	child_process_2(t_list *pipex, char **argv, char **envp, int *fd)
{
	char	*cmd_path;
	int		outfile;

	close(fd[1]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		ft_perror("outfile open error", pipex, EXIT_FAILURE);
	if (dup2(fd[0], STDIN_FILENO) < 0 || dup2(outfile, STDOUT_FILENO) < 0)
		ft_perror("dup2", pipex, EXIT_FAILURE);
	close(fd[0]);
	close(outfile);
	cmd_path = get_cmd_path(pipex->path, pipex->cmd2);
	if (!cmd_path)
	{
		ft_putstr_fd("command not found\n", 2);
		cleanup(pipex, 127);
	}
	execve(cmd_path, pipex->cmd2, envp);
	free(cmd_path);
	exit(EXIT_FAILURE);
}

int	process(t_list *pipex, char **argv, char **envp)
{
	int		fd[2];
	int		status1;
	int		status2;
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
		ft_perror("pipe error", pipex, EXIT_FAILURE);
	pid1 = fork();
	if (pid1 < 0)
		ft_perror("fork error", pipex, EXIT_FAILURE);
	if (pid1 == 0)
		child_process_1(pipex, argv, envp, fd);
	pid2 = fork();
	if (pid2 < 0)
		ft_perror("fork error", pipex, EXIT_FAILURE);
	if (pid2 == 0)
		child_process_2(pipex, argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	else
		return (128 + WTERMSIG(status2));
}
