/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:08:50 by duhkim            #+#    #+#             */
/*   Updated: 2025/06/09 20:56:05 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(void)
{
	perror(NULL);
	exit(1);
}

int	error_handle(char *errormsg, char *str, int mode, int err)
{
	int	p_err;

	p_err = errno;
	if (!errormsg)
		errormsg = strerror(p_err);
	if (write(2, "pipex: ", 7) == -1)
		ft_perror();
	if (write(2, errormsg, ft_strlen(errormsg)) == -1)
		ft_perror();
	if (mode && write(2, ": ", 2) == -1)
		ft_perror();
	if (mode && str && write(2, str, ft_strlen(str)) == -1)
		ft_perror();
	if (write(2, "\n", 1) == -1)
		ft_perror();
	if (err > 0)
		return (err);
	else
		return (p_err);
}

void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

char	*real_path(char **split_path, char *cmd)
{
	int		i;
	char	*full_path;
	char	*temp;

	i = 0;
	while (split_path[i] != NULL)
	{
		temp = ft_strjoin(split_path[i], "/");
		if (!temp)
			exit(error_handle(NULL, "strjoin is failed", 1, 0));
		full_path = ft_strjoin(temp, cmd);
		if (!full_path)
			exit(error_handle(NULL, "strjoin is failed", 1, 0));
		free(temp);
		if (access(full_path, X_OK) == 0)
		{
			ft_free(split_path);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	ft_free(split_path);
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**split_path;
	char	*path;

	path = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i] + 5;
			break ;
		}
		i++;
	}
	if (!path)
		return (NULL);
	split_path = ft_split(path, ':');
	if (!split_path)
		exit(error_handle(NULL, "malloc is failed", 1, 0));
	return (real_path(split_path, cmd));
}
