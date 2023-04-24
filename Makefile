CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = 	action_runner.c freemem.c is_args_valid.c \
		is_args_valid2.c join_args.c lis_utils.c \
		lis.c main.c push_back_utils.c \
		push_back_utils2.c push_back.c rules.c \
		sort.c sorting_tools.c sorting_tools2.c \
		stack.c

SRCS_BNS = 	checker_bonus.c libft/get_next_line.c \
			libft/get_next_line_utils.c action_runner.c \
			freemem.c is_args_valid.c \
			is_args_valid2.c join_args.c lis_utils.c \
			lis.c push_back_utils.c \
			push_back_utils2.c push_back.c rules.c \
			sort.c sorting_tools.c sorting_tools2.c \
			stack.c

OBJ = ${SRCS:.c=.o}

OBJ_BNS = ${SRCS_BNS:.c=.o}

NAME = push_swap

NAME_BNS = checker

RM = rm -f

${NAME}: ${OBJ}
		make -C libft
		$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $@

all:	$(NAME)

clean:
	make -C libft clean
	$(RM) $(OBJ) $(OBJ_BNS)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME) checker

${NAME_BNS}: ${OBJ_BNS}
	make -C libft
	$(CC) $(CFLAGS) $(OBJ_BNS) libft/libft.a -o $@

bonus: ${NAME_BNS}

re:	fclean all