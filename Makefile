NAME	=	libftprintf.a
SRCS	=	ft_printf.c ft_put_char_str_nbr.c ft_put_hexadecimal.c
OBJS	=	$(SRCS:%.c=%.o)
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

$(NAME):	$(OBJS)
				ar rcs $@ $(OBJS) *.o

all: $(NAME)

%.o: %.CC
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				rm -f $(OBJS) *.o
fclean: clean
				rm -f $(NAME)
re:
				fclean all