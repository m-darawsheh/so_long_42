NAME = so_long
CC = cc

SRCS = main.c check_wall.c parsing_check.c flood_fill.c put_image.c move_player.c helper.c choose_move_type.c time_to_exit.c for_protiction.c
OBJS = $(SRCS:.c=.o) 

CFLAGS = -Wall -Wextra -Werror
HEADERS = -Iprintf -Ilibft

LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a
LIBS_FLAGS = -Lprintf -lftprintf -Llibft -lft -lmlx -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS)  $(OBJS) $(LIBS_FLAGS) -o $(NAME)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C printf

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -f $(OBJS) && make -C libft clean && make -C printf clean

fclean: clean
	rm -f $(NAME) && make -C libft fclean && make -C printf fclean

re: fclean all

.PHONY: all clean fclean re libft printf