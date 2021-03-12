# -*- Makefile -*-

SRCS	= src/main.c src/parser.c src/reader.c src/solver.c src/state.c \
		  src/state2.c src/valid.c

OBJS	= ${SRCS:.c=.o}

NAME	= bsq

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -c

RM		= rm -f

.c.o:
			${CC} ${CFLAGS} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re
