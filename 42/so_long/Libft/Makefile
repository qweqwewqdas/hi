NAME = libft.a

SOURCES = \
./ft_putchar_fd.c \
./ft_print_char.c \
./ft_printf.c \
./ft_print_hex.c \
./ft_print_int.c \
./ft_print_pointer.c \
./ft_print_string.c \
./ft_print_unsigned_int.c \
./ft_strjoin.c \
./ft_strrchr.c \
./ft_strlcpy.c \
./ft_atoi.c \
./ft_bzero.c \
./ft_calloc.c \
./ft_isalnum.c \
./ft_strmapi.c \
./ft_memchr.c \
./ft_memcmp.c \
./ft_memcpy.c \
./ft_memmove.c \
./ft_memset.c \
./ft_putendl_fd.c \
./ft_putnbr_fd.c \
./ft_putstr_fd.c \
./ft_split.c \
./ft_strchr.c \
./ft_strdup.c \
./ft_striteri.c \
./ft_strlcat.c \
./ft_strlen.c \
./ft_strncmp.c \
./ft_strnstr.c \
./ft_strtrim.c \
./ft_substr.c \
./ft_tolower.c \
./ft_toupper.c \
./ft_isalpha.c \
./ft_isascii.c \
./ft_isdigit.c \
./ft_isprint.c \
./ft_itoa.c \
./ft_lstnew.c \
./get_next_line.c \
./get_next_line_utils.c 

OBJECTS = $(SOURCES:.c=.o)

CC = cc
AR = ar
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)


$(NAME): $(OBJECTS)
	$(AR) -rcs $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

