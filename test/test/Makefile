SRCS	= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
NAME	= libft.a
LIBC	= ar rc
LIBR	= ranlib
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o: 
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

all: ${NAME}

${NAME}:	${OBJS} 
			${LIBC} ${NAME} ${OBJS} 
			${LIBR} ${NAME}

clean: 
			rm -f ${OBJS}

fclean: 	clean 
			rm -f ${NAME}

re: 		fclean all
