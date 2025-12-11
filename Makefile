NAME		= push_swap
LIBFT		= libft/libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDE		= -I./headers -I./libft

SRCS		= main.c \
			src/parse.c \
			src/sort.c \
			src/sort_small.c \
			src/operations/push.c \
			src/operations/rotate.c \
			src/operations/reverse_rotate.c \
			src/operations/swap.c \
			src/utils/free.c \
			src/utils/normalization.c \
			src/utils/stack.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
