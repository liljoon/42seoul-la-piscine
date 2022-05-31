# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isunwoo <isunwoo@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/01 14:00:24 by isunwoo           #+#    #+#              #
#    Updated: 2022/05/03 19:58:17 by isunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar rc

INC = includes

SRCS = srcs/ft_putchar.c srcs/ft_strcmp.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c

OBJS = srcs/ft_putchar.o srcs/ft_strcmp.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o

all : ${NAME}

%.o : %.c
	${CC} ${CFLAG} -c $< -o $@ -I ${INC}

${NAME} : ${OBJS}
	${AR} ${NAME} ${OBJS}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
