/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:51:40 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/20 15:51:42 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_error(char *error)
{
	ft_putstr_fd(error, 2);
	exit(1);
}

static int	init_pipex(t_list *pipex, char **argv, char **envp)
{
	pipex->cmd1 = cmd_array(3, argv);
	pipex->cmd2 = cmd_array(4, argv);
	pipex->path = find_path(envp);
	if (!pipex->cmd1 || !pipex->cmd2 || !pipex->path)
		return (1);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_list	pipex;
	int		exit_code;

	if (argc != 5)
		ft_error("arguments error\n");
	if (init_pipex(&pipex, argv, envp))
		cleanup(&pipex, EXIT_FAILURE);
	exit_code = process(&pipex, argv, envp);
	free_pipex(&pipex);
	return (exit_code);
}
