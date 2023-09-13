# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 22:04:26 by mgardesh          #+#    #+#              #
#    Updated: 2023/09/13 23:47:30 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_memchr.c ft_strncmp.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strdup.c ft_calloc.c ft_strjoin.c ft_substr.c ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c

SRCS		= ${addprefix ${PRE}, ${SRC}}

OBJS		= ${SRCS:.c=.o}

PRE			= ./

HEAD		= ./

NAME		= libft.a

LIBC		= ar rc

LIBR		= ranlib

RM			= rm -f

GCC			= cc

CFLAGS		= -Wall -Wextra -Werror

all:			${NAME}
.c.o:
			${GCC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${LIBC} ${NAME} ${OBJS}
			${LIBR} ${NAME}


clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}
			rm -f libft.so
			rm -f a.out

re:			fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

.PHONY:		all clean fclean re
