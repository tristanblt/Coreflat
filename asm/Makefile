##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for
##

SRCPATH = src

NAME	=	asm

SRC	=	../src/op.c									\
		$(SRCPATH)/main.c							\
		$(SRCPATH)/encode_instructions_to_file.c	\
		$(SRCPATH)/arguments_handling.c				\
		$(SRCPATH)/error_handling_and_parsing.c		\
		$(SRCPATH)/get_file.c						\
		$(SRCPATH)/multiple_split.c					\
		$(SRCPATH)/my_strncpy.c						\
		$(SRCPATH)/free_utils.c		\
		$(SRCPATH)/instruction_is_valid.c	\
		$(SRCPATH)/argument_type.c	\

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-W -Wall -Wextra -Wshadow	\
		-Iinclude			\
		-Iinclude -I../include -g			\

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
