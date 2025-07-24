/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:04:18 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/24 04:50:45 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_exit(t_game *game)
{
	int	y;
	int	x;
	int	find;

	find = 0;
	y = 0;
	while (y < game->maps.height && !find)
	{
		x = 0;
		while (x < game->maps.width)
		{
			if (game->maps.map[y][x] == 'E')
			{
				game->exit_x = x;
				game->exit_y = y;
				find = 1;
				break ;
			}
			x++;
		}
		y++;
	}
}

void	init_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->collect_count = 0;
	while (y < game->maps.height)
	{
		x = 0;
		while (x < game->maps.width)
		{
			if (game->maps.map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			else if (game->maps.map[y][x] == 'C')
				game->collect_count++;
			x++;
		}
		y++;
	}
	find_exit(game);
}

int	map_value(t_game *game, char *file)
{
	if (make_map(game, file))
		return (ft_printf("Error\nMalloc Error\n"), 1);
	if (load_maps(game, file))
		return (ft_printf("Error\nLoad Error\n"), 1);
	if (is_square(game))
	{
		get_next_line(-1);
		return (ft_printf("Error\nNot square Error\n"), 1);
	}
	if (is_wall(game))
		return (ft_printf("Error\nNot wall Error\n"), 1);
	if (check_elements(game))
		return (ft_printf("Error\nNot Elements Error\n"), 1);
	if (find_way(file))
		return (ft_printf("Error\nNo way Error\n"), 1);
	init_player(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.move_count = 0;
	if (argc != 2 || read_map(argv[1]))
		return (ft_printf("Error\nArgmentError\n"), 1);
	if (map_value(&game, argv[1]))
		return (1);
	if (init_window(&game))
		return (1);
	file_to_image(&game);
	map_printer(&game);
	mlx_key_hook(game.wnd, key_press, &game);
	mlx_hook(game.wnd, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
