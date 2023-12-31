
NAME = pipex

SRCS =  pipex.c \
		paths.c \
		pipex_utils.c

BONUS = pipex_bonus.c \
		ft_here_doc.c \
		paths.c \
		pipex_utils.c

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS:.c=.o}


CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM	=	rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	make --no-print-directory -C ./libft
	${CC} ${CFLAGS} -o ${NAME} $^ ./libft/libft.a

bonus: ${BONUS_OBJS}
	make --no-print-directory -C ./libft
	${CC} ${CFLAGS} -o ${NAME} $^ ./libft/libft.a

clean: 
	make --no-print-directory -C ./libft fclean
	${RM} ${OBJS} ${BONUS_OBJS}


fclean: clean
	${RM} ${NAME} ${CHECK}

re: fclean all

.PHONY: all bonus clean fclean re