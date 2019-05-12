##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for
##

NAME	=	corewar

MAIN	=	src/main.c

SRC	=	src/get_cor_file.c				\
		src/parse_instructions.c		\
		src/parse_header.c				\
		src/cycle_manager.c				\
		src/champion_manager.c			\
		../src/op.c						\
		src/processes_manager.c			\
		src/list/add_to_list.c			\
		src/list/create_list.c			\
		src/list/destroy_list.c			\
		src/list/move_in_list.c			\
		src/write_in_mem.c				\
		src/parse_instruction_from_mem.c\

OBJ	=	$(SRC:%.c=%.o) $(MAIN:%.c=%.o)

CFLAGS	=	-W -Wall -Wextra -Wshadow	\
		-Iinclude -I../include			\

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
