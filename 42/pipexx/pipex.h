/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:05:00 by duhkim            #+#    #+#             */
/*   Updated: 2025/05/28 23:40:20 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./Libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

void	ft_perror(void);
void	child1(char **argv, int *p_fd, char **env);
void	child2(char **argv, int *p_fd, char **env);
void	fork_child(pid_t *pid, char **argv, int *p_fd, char **env);
void	run_exec(char *cmd, char **env);
void	ft_free(char **tab);
char	*get_path(char *cmd, char **env);
char	*real_path(char **split_path, char *cmd);
int		error_handle(char *errormsg, char *str, int mode, int err);

#endif