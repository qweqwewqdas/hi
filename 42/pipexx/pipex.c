/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:03:23 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/22 00:40:07 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_exec(char *cmd, char **env)
{
	char	**split_cmd;
	char	*path;

	if (cmd && *cmd)
		split_cmd = ft_split(cmd, ' ');
	else
		exit(error_handle("command not found", NULL, 1, 127));
	if (!split_cmd)
		exit(error_handle(NULL, "split_cmd is failed", 1, 0));
	else
		path = get_path(split_cmd[0], env);
	if (!path)
	{
		error_handle("command not found", split_cmd[0], 1, 1);
		ft_free(split_cmd);
		exit(127);
	}
	execve(path, split_cmd, env);
	ft_free(split_cmd);
	free(path);
	exit(error_handle("execve is failed", NULL, 0, 1));
}

void	child2(char **argv, int *p_fd, char **env)
{
	int	fd;

	close(p_fd[1]);
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		exit(error_handle(NULL, "fd open is failed", 1, 1));
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[0]);
	run_exec(argv[3], env);
}

void	child1(char **argv, int *p_fd, char **env)
{
	int	fd;

	close(p_fd[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(error_handle(NULL, "fd open is failed", 1, 1));
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[1]);
	run_exec(argv[2], env);
}

void	fork_child(pid_t *pid, char **argv, int *p_fd, char **env)
{
	int		err;

	pid[0] = fork();
	if (pid[0] < 0)
		exit(error_handle(NULL, "fork is failed", 1, 0));
	if (pid[0] == 0)
		child1(argv, p_fd, env);
	pid[1] = fork();
	if (pid[1] < 0)
	{
		err = errno;
		waitpid(pid[0], NULL, 0);
		exit(error_handle(NULL, "fork is failed", 1, err));
	}
	if (pid[1] == 0)
		child2(argv, p_fd, env);
}

int	main(int argc, char **argv, char **env)
{
	int		status;
	int		p_fd[2];
	pid_t	pid[2];
	(void)argc;
	if (argc != 5)
		return (error_handle("Argument error", NULL, 0, 1));
	if (pipe(p_fd) == -1)
		return (error_handle(NULL, "pipe is failed", 1, 0));
	fork_child(pid, argv, p_fd, env);
	close(p_fd[0]);
	close(p_fd[1]);
	waitpid(pid[0], NULL, 0);
	if (waitpid(pid[1], &status, 0) == -1)
		return (1);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (1);
}
