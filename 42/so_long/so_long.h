/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:28:45 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/24 05:18:01 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_key
{
	KEY_W = 119,
	KEY_S = 115,
	KEY_A = 97,
	KEY_D = 100,
	KEY_ESC = 65307
}			t_key;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		player;
	int		exit;
	int		collect;
}			t_map;

typedef struct s_img
{
	void	*coin;
	void	*exit;
	void	*floor;
	void	*open;
	void	*player;
	void	*wall;
}			t_img;

typedef struct s_game
{
	void	*mlx;
	void	*wnd;
	int		player_x;
	int		player_y;
	int		move_count;
	int		collect_count;
	int		exit_x;
	int		exit_y;
	t_map	maps;
	t_img	img;
}			t_game;

int			read_map(char *filename);
int			make_map(t_game *game, char *file);
int			malloc_maps(t_game *game, int height, int width);
int			load_maps(t_game *game, char *file);
void		free_maps(t_game *game);
int			is_square(t_game *game);
int			is_wall(t_game *game);
int			check_line_elements(t_game *game, int i, int *pec);
int			check_elements(t_game *game);
int			init_window(t_game *game);
void		map_printer(t_game *game);
void		file_to_image(t_game *game);
void		map_printer(t_game *game);
void		put_tile_image(t_game *game, char tile, int x, int y);
void		move_player(t_game *game, int x, int y);
void		update_position(t_game *game, int new_x, int new_y);
void		update_collect(t_game *game, char tile);
int			can_move(t_game *game, int x, int y);
int			key_press(int key, t_game *game);
void		init_player(t_game *game);
void		open_exit(t_game *game);
void		destroy_images(t_game *game);
int			close_game(t_game *game);
int			find_way(char *file);
void		use_dfs(t_game *temp, int y, int x);
int			temp_check_map(t_game *temp);
void		find_exit(t_game *game);
int			check_image(t_game *game);
#endif
