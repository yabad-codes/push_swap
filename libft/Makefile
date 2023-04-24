SRCS	=	ft_atoi.c ft_isdigit.c ft_strlen.c \
			ft_strncmp.c ft_strjoin.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_split.c ft_long_atoi.c \
			ft_memcpy.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

AR		= ar rc

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	${AR} ${NAME} $?
	ranlib ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all bonus clean fclean re