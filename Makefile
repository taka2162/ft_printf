NAME	=	libftprintf.a
LIBFT	=	libft.a
LIBFT_PATH = ./libft/
SRCS	=	ft_printf.c ft_put_char_str_nbr.c ft_put_hexadecimal.c
OBJS	=	$(SRCS:%.c=%.o)
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

$(NAME):	$(LIBFT) $(OBJS)
					@if [ ! -f $(NAME) ]; then \
						cp $(LIBFT_PATH)$(LIBFT) $(NAME); \
						ar rcs $(NAME) $(OBJS); \
					fi

$(LIBFT):
					make -C $(LIBFT_PATH) all

all: $(NAME)

clean:
				rm -f $(OBJS)
				make -C $(LIBFT_PATH) clean
fclean: clean
				rm -f $(NAME)
				make -C $(LIBFT_PATH) fclean
re:
				fclean all
