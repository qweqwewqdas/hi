# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 22:56:44 by duhkim            #+#    #+#              #
#    Updated: 2025/05/02 05:31:41 by duhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SOURCES = ft_printf.c \
ft_print_char.c \
ft_print_hex.c \
ft_print_int.c \
ft_print_pointer.c \
ft_print_string.c \
ft_print_unsigned_int.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
AR = ar
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -rcs $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

