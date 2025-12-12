NAME		= push_swap
NAME_BONUS	= check

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
INCLUDE		= -I./headers -I./libft

# Push_swap sources
SRCS		= main.c \
			src/parse.c \
			src/sort.c \
			src/sort_small.c \
			src/sort_cost.c \
			src/sort_rotations.c \
			src/operations/push.c \
			src/operations/rotate.c \
			src/operations/reverse_rotate.c \
			src/operations/swap.c \
			src/utils/free.c \
			src/utils/checks.c \
			src/utils/stack.c

# Shared sources (operations and utils used by push_swap and checker)
SHARED_SRCS	= src/parse.c \
			src/operations/push.c \
			src/operations/rotate.c \
			src/operations/reverse_rotate.c \
			src/operations/swap.c \
			src/utils/free.c \
			src/utils/stack.c

# Checker sources
CHECKER_SRCS = checker/checker.c \
			get_next_line/get_next_line.c \
			$(SHARED_SRCS)

OBJS		= $(SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) bonus

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(CHECKER_OBJS) $(LIBFT) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(CHECKER_OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
