SRCS		= ft_printf.c ft_puthex_fd.c ft_putnum_fd.c ft_putnum_fd_un.c ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c ft_putareg.c
OBJS		= $(SRCS:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	${CC} $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean all re

