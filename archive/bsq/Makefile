# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yham <yham@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/01 17:43:15 by yham              #+#    #+#              #
#    Updated: 2022/05/04 23:55:52 by yham             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

SRC_DIR		= ./srcs/
HEADER		= ./includes/

SRCS		= $(SRC_DIR)memory.c		\
			  $(SRC_DIR)first_line.c	\
			  $(SRC_DIR)map.c			\
			  $(SRC_DIR)solve.c			\
			  $(SRC_DIR)main.c			\

OBJS		= $(SRCS:.c=.o)

NAME		= bsq

all :		$(NAME)

.c.o :
			$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $^
clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY :	all clean fclean re
