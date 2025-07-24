/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:56:52 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/24 06:16:36 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_image(t_game *game)
{
	void	*images[6];
	int		i;

	images[0] = game->img.coin;
	images[1] = game->img.exit;
	images[2] = game->img.floor;
	images[3] = game->img.open;
	images[4] = game->img.player;
	images[5] = game->img.wall;
	i = 0;
	while (i < 6)
	{
		if (!images[i])
		{
			free_maps(game);
			return (1);
		}
		i++;
	}
	return (0);
}

void	open_exit(t_game *game)
{
	int	y;
	int	x;

	x = game->exit_x;
	y = game->exit_y;
	game->maps.map[y][x] = 'O';
	map_printer(game);
}

void	destroy_images(t_game *game)
{
	if (game->img.coin)
		mlx_destroy_image(game->mlx, game->img.coin);
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
	if (game->img.floor)
		mlx_destroy_image(game->mlx, game->img.floor);
	if (game->img.open)
		mlx_destroy_image(game->mlx, game->img.open);
	if (game->img.player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
}

int	close_game(t_game *game)
{
	mlx_loop_end(game->mlx);
	destroy_images(game);
	mlx_destroy_window(game->mlx, game->wnd);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_maps(game);
	exit(0);
	return (0);
}
