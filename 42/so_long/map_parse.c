/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 21:03:50 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/24 06:08:36 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_maps(t_game *game, char *file)
{
	int		fd;
	int		i;
	char	*line;
	int		len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL && i < game->maps.height)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		ft_strlcpy(game->maps.map[i], line, game->maps.width + 1);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}

int	malloc_maps(t_game *game, int height, int width)
{
	int	i;

	i = 0;
	game->maps.map = malloc(sizeof(char *) * (height + 1));
	if (!game->maps.map)
		return (1);
	while (i < height)
	{
		game->maps.map[i] = malloc(sizeof(char) * (width + 1));
		if (!game->maps.map[i])
		{
			free_maps(game);
			return (1);
		}
		i++;
	}
	game->maps.map[height] = NULL;
	return (0);
}

int	make_map(t_game *game, char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	if (!line)
		return (1);
	game->maps.height = 0;
	game->maps.width = ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		game->maps.height++;
	}
	close(fd);
	if (malloc_maps(game, game->maps.height, game->maps.width))
		return (1);
	return (0);
}

int	read_map(char *file)
{
	char	*temp;

	temp = ft_strnstr(file, ".ber", ft_strlen(file));
	if (temp == NULL)
		return (1);
	else if (ft_strlen(temp) > 4)
		return (1);
	return (0);
}
