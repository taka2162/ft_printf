# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 10:44:56 by sshimura          #+#    #+#              #
#    Updated: 2024/05/07 16:54:08 by sshimura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBFT_DIR	=	./libft
HEADER_DIR	=	./header
SRCS		=	ft_printf.c ft_str_helper.c helper.c ft_unsitoa.c ft_check_cspdi.c ft_check_uxx_per.c
SRCS		+= 	$(wildcard $(LIBFT_DIR)/*.c)

OBJS		=	$(SRCS:%.c=%.o)
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I $(HEADER_DIR)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

all:	$(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:		fclean all

run: $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) -o exe
	./exe
	$(MAKE) fclean

.PHONY: all clean fclean re