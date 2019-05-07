##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## compiles my libmy
##

NAME	=	libmy.a

SRC	=	my_compute_power_rec.c		\
		my_compute_square_root.c	\
		my_find_prime_sup.c			\
		my_getnbr.c					\
		my_isneg.c					\
		my_is_prime.c				\
		my_putchar.c				\
		my_put_nbr.c				\
		my_putstr.c					\
		my_revstr.c					\
		my_showmem.c				\
		my_showstr.c				\
		my_sort_int_array.c			\
		my_strcapitalize.c			\
		my_strcat.c					\
		my_strcmp.c					\
		my_strcpy.c					\
		my_str_isalpha.c			\
		my_str_islower.c			\
		my_str_isnum.c				\
		my_str_isprintable.c		\
		my_str_isupper.c			\
		my_strlen.c					\
		my_strlowcase.c				\
		my_strncat.c				\
		my_strncmp.c				\
		my_strncpy.c				\
		my_strstr.c					\
		my_strupcase.c				\
		my_swap.c					\
		my_strdup.c					\
		my_str_to_word_array.c		\
		my_show_word_array.c		\
		flags.c						\
		flags_modifiers.c			\
		my_printf.c					\
		my_putnbr_base.c			\
		my_unsigned_putnbr.c		\
		strlen_fonction.c			\
		putnbr_unsigned.c			\

CFLAGS	=	-W -Wall -Wextra -I ../../include

CC	=	gcc

OBJ	=	$(SRC:%.c=%.o)

AR	=	ar rc

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
			$(AR) $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(OBJS)
		$(RM) $(NAME)

re:		fclean all
