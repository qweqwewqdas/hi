/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 01:09:01 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/24 04:29:27 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_square(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->maps.height)
	{
		if (ft_strlen(game->maps.map[y]) != (size_t)game->maps.width)
			return (free_maps(game), 1);
		y++;
	}
	return (0);
}

int	is_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->maps.height)
	{
		if (i == 0 || i == game->maps.height - 1)
		{
			j = 0;
			while (j < game->maps.width)
			{
				if (game->maps.map[i][j++] != '1')
					return (free_maps(game), 1);
			}
		}
		else if (game->maps.map[i][0] != '1'
				|| game->maps.map[i][game->maps.width - 1] != '1')
			return (free_maps(game), 1);
		i++;
	}
	return (0);
}

int	check_line_elements(t_game *game, int i, int *pec)
{
	int	j;

	j = 0;
	while (j < game->maps.width)
	{
		if (game->maps.map[i][j] == 'P')
			pec[0]++;
		else if (game->maps.map[i][j] == 'E')
			pec[1]++;
		else if (game->maps.map[i][j] == 'C')
			pec[2]++;
		else if (game->maps.map[i][j] != '0' && game->maps.map[i][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	check_elements(t_game *game)
{
	int	i;
	int	pec[3];

	i = 0;
	pec[0] = 0;
	pec[1] = 0;
	pec[2] = 0;
	while (i < game->maps.height)
	{
		if (check_line_elements(game, i, pec))
			return (free(game), 1);
		i++;
	}
	if (pec[0] != 1 || pec[1] != 1 || pec[2] < 1)
		return (free_maps(game), 1);
	return (0);
}
