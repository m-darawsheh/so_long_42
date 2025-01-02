NAME = so_long

SRCS = main.c check_wall.c parsing_check.c flood_fill.c put_image.c move_player.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBS_FLAGS = -Lprintf -lftprintf -Llibft -lft -lmlx -lX11 -lXext

HEADERS = -Iprintf -Ilibft

OBJS = $(SRCS:.c=.o)

all : libft printf $(NAME)

libft:
	make -C libft

printf:
	make -C printf

$(NAME): $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) $(LIBS_FLAGS) -o $(NAME)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) $(HEADERS) $(SRCS) -c

clean:
	rm -f $(OBJS) && make -C libft clean && make -C printf clean

fclean: clean
	rm -f $(NAME) && make -C libft fclean && make -C printf fclean

re: fclean all

.PHONY: all clean fclean re libft printf