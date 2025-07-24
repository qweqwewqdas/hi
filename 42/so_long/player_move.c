/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:30:09 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/24 05:07:51 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_coin(t_game *game, char tile)
{
	if (tile == 'C')
	{
		game->collect_count--;
		if (game->collect_count == 0)
			open_exit(game);
	}
}

void	update_position(t_game *game, int new_x, int new_y)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (x == game->exit_x && y == game->exit_y)
		game->maps.map[y][x] = 'E';
	else
		game->maps.map[y][x] = '0';
	game->maps.map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->move_count++;
	ft_printf("Move count: %d\n", game->move_count);
	map_printer(game);
}

int	can_move(t_game *game, int x, int y)
{
	char	tile;

	tile = game->maps.map[y][x];
	if (tile == '1')
		return (0);
	if (tile == 'O')
	{
		ft_printf("Clear moves: %d\n", game->move_count + 1);
		close_game(game);
	}
	update_coin(game, tile);
	return (1);
}

void	move_player(t_game *game, int x, int y)
{
	if (can_move(game, x, y))
		update_position(game, x, y);
}

int	key_press(int key, t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (key == KEY_W)
		y--;
	else if (key == KEY_S)
		y++;
	else if (key == KEY_A)
		x--;
	else if (key == KEY_D)
		x++;
	else if (key == KEY_ESC)
		close_game(game);
	else
		return (0);
	move_player(game, x, y);
	return (0);
}
