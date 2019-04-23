##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for
##

NAME	=	corewar

SRC	=	src/main.c		\

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-W -Wall -Wextra -Wshadow	\
		-Iinclude			\

LIB	=	my

LIB_PATH=	../lib/my

LDFLAGS	=	-L$(LIB_PATH) -l$(LIB)

CC	=	gcc

RM	=	rm -f

all	:	$(NAME)

lib	:
		make -C $(LIB_PATH)

$(NAME)	:	$(OBJ) lib
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		make clean -C $(LIB_PATH)
		$(RM) $(OBJ)

fclean	:	clean
		make fclean -C $(LIB_PATH)
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	lib clean fclean re
