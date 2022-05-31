# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isunwoo <isunwoo@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 14:39:20 by isunwoo           #+#    #+#              #
#    Updated: 2022/05/04 20:23:06 by isunwoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op
CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar rc

INC = includes

SRCS = main.c ft_atoi.c ft_putnbr.c ft_putstr.c ft_strlen.c calc.c

OBJS = main.o ft_atoi.o ft_putnbr.o ft_putstr.o ft_strlen.o calc.o

all : ${NAME}

%.o : %.c
	${CC} ${CFLAG} -c $< -o $@

${NAME} : ${OBJS}
	${CC} ${OBJS} -o ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
