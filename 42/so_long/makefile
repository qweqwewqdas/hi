NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

SOURCES = so_long.c \
		map_parse.c \
		check_maps.c \
		so_long_util1.c \
		player_move.c \
		so_long_util2.c \
		find_way.c \
		  
OBJECTS = $(SOURCES:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX) -lX11 -lXext -lm -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	$(RM) $(OBJECTS)
	make -C $(LIBFT_DIR) fclean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re