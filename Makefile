# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 10:44:56 by sshimura          #+#    #+#              #
#    Updated: 2024/05/06 14:04:59 by sshimura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
# SRCDIR		=	../srcs
# SRCS		=	$(wildcard $(SRCDIR)/*.c) main.c
SRCS		=	ft_putnbr.c	ft_strlen.c ft_putchar.c ft_putstr.c ft_printf.c main.c

OBJS		=	$(SRCS:%.c=%.o)
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:		fclean all

exe:	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o exe

.PHONY: all clean fclean re