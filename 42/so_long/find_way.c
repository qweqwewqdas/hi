/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:58:07 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/24 04:04:01 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_temp_map(t_game *temp)
{
	int	y;
	int	x;

	y = 0;
	while (y < temp->maps.height)
	{
		x = 0;
		while (x < temp->maps.width)
		{
			if (temp->maps.map[y][x] == 'C' || temp->maps.map[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	use_dfs(t_game *temp, int y, int x)
{
	char	tile;

	temp->maps.map[y][x] = 'X';
	tile = temp->maps.map[y - 1][x];
	if (tile == 'C' || tile == 'E' || tile == '0')
		use_dfs(temp, y - 1, x);
	tile = temp->maps.map[y + 1][x];
	if (tile == 'C' || tile == 'E' || tile == '0')
		use_dfs(temp, y + 1, x);
	tile = temp->maps.map[y][x - 1];
	if (tile == 'C' || tile == 'E' || tile == '0')
		use_dfs(temp, y, x - 1);
	tile = temp->maps.map[y][x + 1];
	if (tile == 'C' || tile == 'E' || tile == '0')
		use_dfs(temp, y, x + 1);
}

int	find_way(char *file)
{
	t_game	temp;

	make_map(&temp, file);
	load_maps(&temp, file);
	init_player(&temp);
	use_dfs(&temp, temp.player_y, temp.player_x);
	if (check_temp_map(&temp) == 1)
	{
		free_maps(&temp);
		return (1);
	}
	free_maps(&temp);
	return (0);
}
