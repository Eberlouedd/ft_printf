# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 02:26:26 by kyacini           #+#    #+#              #
#    Updated: 2022/06/15 02:43:04 by kyacini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c \
		utils.c \
		conv.c \

NAME = libftprintf.a

OBJS = ${SRC:.c=.o}

all	:	${NAME}

%.o : %.c
	gcc -o $@ -c $< -Wall -Werror -Wextra

libftprintf.a	:	${OBJS}
	ar rc ${NAME} ${OBJS}

bonus	:	${OBJS}
	ar rc ${NAME} ${OBJS}
clean	:
	rm -rf *.o

fclean	:	clean
	rm -rf ${NAME}
	
re:	fclean all