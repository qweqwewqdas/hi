/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 01:07:24 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/24 03:46:40 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_maps(t_game *game)
{
	int	i;

	i = 0;
	if (!game->maps.map)
		return ;
	while (game->maps.map[i])
	{
		free(game->maps.map[i]);
		i++;
	}
	free(game->maps.map);
	game->maps.map = NULL;
}

int	init_window(t_game *game)
{
	int	width;
	int	height;

	width = game->maps.width * 64;
	height = game->maps.height * 64;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_printf("Error\nMLX Init Error\n"), 1);
	game->wnd = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->wnd)
		return (ft_printf("Error\nWindow Create Error\n"), 1);
	return (0);
}

void	file_to_image(t_game *game)
{
	int	size;

	size = 64;
	game->img.coin = mlx_xpm_file_to_image(game->mlx, "./xpm_file/coin.xpm",
			&size, &size);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "./xpm_file/exit.xpm",
			&size, &size);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "./xpm_file/floor.xpm",
			&size, &size);
	game->img.open = mlx_xpm_file_to_image(game->mlx, "./xpm_file/open.xpm",
			&size, &size);
	game->img.player = mlx_xpm_file_to_image(game->mlx, "./xpm_file/player.xpm",
			&size, &size);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "./xpm_file/wall.xpm",
			&size, &size);
	if (check_image(game))
	{
		ft_printf("Error\nImage load Error\n");
		destroy_images(game);
		mlx_destroy_window(game->mlx, game->wnd);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(1);
	}
}

void	put_tile_image(t_game *game, char tile, int x, int y)
{
	void	*img;

	img = game->img.floor;
	if (tile == '1')
		img = game->img.wall;
	else if (tile == 'C')
		img = game->img.coin;
	else if (tile == 'E')
		img = game->img.exit;
	else if (tile == 'O')
		img = game->img.open;
	else if (tile == 'P')
		img = game->img.player;
	mlx_put_image_to_window(game->mlx, game->wnd, img, x * 64, y * 64);
}

void	map_printer(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->maps.height)
	{
		x = 0;
		while (x < game->maps.width)
		{
			put_tile_image(game, game->maps.map[y][x], x, y);
			x++;
		}
		y++;
	}
}
