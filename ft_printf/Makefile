# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 22:04:26 by mgardesh          #+#    #+#              #
#    Updated: 2023/11/21 18:49:34 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= ft_printf.c ft_printf_utils.c

SRCS		= ${addprefix ${PRE}, ${SRC}}

OBJS		= ${SRCS:.c=.o}

PRE			= ./

HEAD		= ./

NAME		= libftprintf.a

LIBC		= ar rcs

RM			= rm -f

GCC			= cc

CFLAGS		= -Wall -Wextra -Werror

all:			
			make ${NAME}

${NAME}:	${OBJS}
			(cd libft; make)
			cp ./libft/libft.a ./${NAME}
			${LIBC} ${NAME} ${OBJS}

.c.o:
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEAD}

clean:
			(cd libft;make clean)
			rm -f ${OBJS}

fclean:		clean
			(cd libft;make fclean)
			rm -f ${NAME}
			rm -f libft.so
			rm -f a.out

re:			fclean all

.PHONY:		all clean fclean re
