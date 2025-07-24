NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SOURCES = push_swap.c push_swap_util.c push_command1.c \
		  push_command2.c push_command3.c push_command4.c \
		  push_sort.c push_short_sort.c
		  
OBJECTS = $(SOURCES:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJECTS)
	make -C $(LIBFT_DIR) fclean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re