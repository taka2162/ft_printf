# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 10:44:56 by sshimura          #+#    #+#              #
#    Updated: 2024/05/08 13:57:38 by sshimura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBFT_DIR	=	./libft
HEADER_DIR	=	./header
LIBFT		=	$(LIBFT_DIR)/libft.a
SRCS		=	ft_printf.c ft_str_helper.c helper.c ft_unsitoa.c ft_check_cspdi.c ft_check_uxx_per.c
OBJS		=	$(SRCS:%.c=%.o)
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I$(HEADER_DIR) -I.

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
		ar -x $(LIBFT)
		ar rcs $@ $(OBJS) *.o

all:	$(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS) *.o
		$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
		rm -f $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean

re:		fclean all

.PHONY: all clean fclean  re