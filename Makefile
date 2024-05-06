# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 10:44:56 by sshimura          #+#    #+#              #
#    Updated: 2024/05/06 15:52:36 by sshimura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBFTDIR	=	../libft
SRCS		=	$*.c $(LIBFTDIR)/*.c

OBJS		=	$(SRCS:%.c=%.o)
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I

all:	$(NAME)

$(OBJS): %.o:%.c

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