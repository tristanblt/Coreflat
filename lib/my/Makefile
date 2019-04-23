##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makes the lib my
##

NAME	=	libmy.a

SRCS	=	get_next_line.c		\
		my_get_nbr.c		\
		is_num.c		\
		my_printf.c		\
		my_putchar.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_strcmp.c		\
		my_strdup.c		\
		my_strlen.c		\
		my_str_to_array.c	\
		my_str_to_array_opt.c	\

OBJS	=	$(SRCS:%.c=%.o)

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -Wshadow -Werror

AR	=	ar rc

RM	=	rm -f

all	:
		make $(NAME)

$(NAME)	:	$(OBJS)
		$(AR) $(NAME) $(OBJS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	clean fclean re
