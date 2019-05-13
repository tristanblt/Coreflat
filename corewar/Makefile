##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for corewar
##

NAME	=	corewar

TEST_NAME	=	unit_tests

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
		src/instructions/add.c			\
		src/instructions/aff.c			\
		src/instructions/and.c			\
		src/instructions/fork.c			\
		src/instructions/ld.c			\
		src/instructions/ldi.c			\
		src/instructions/lfork.c		\
		src/instructions/live.c			\
		src/instructions/lld.c			\
		src/instructions/lldi.c			\
		src/instructions/or.c			\
		src/instructions/st.c			\
		src/instructions/sti.c			\
		src/instructions/sub.c			\
		src/instructions/xor.c			\
		src/instructions/zjmp.c			\
		src/instruction_is_valid.c		\
		src/utils.c						\
		src/dump_memory.c			\

SRC_TEST	=	tests/test_parse_instruction_from_mem.c	\

OBJ	=	$(SRC:%.c=%.o) $(MAIN:%.c=%.o)

CFLAGS	=	-W -Wall -Wextra -Wshadow	\
		-Iinclude -I../include			\

LIB	=	my

LIB_PATH=	../lib/my

LDFLAGS	=	-L$(LIB_PATH) -l$(LIB)

TEST_FLAGS	=	-lcriterion --coverage

CC	=	gcc

RM	=	rm -f

all	:	$(NAME)

lib	:
		make -C $(LIB_PATH)

$(NAME)	:	$(OBJ) lib
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		make clean -C $(LIB_PATH)
		$(RM) $(OBJ) *.gc*

fclean	:	clean
		make fclean -C $(LIB_PATH)
		$(RM) $(NAME)
		$(RM) $(TEST_NAME)

re	:	fclean all

tests_run	:	lib
			$(CC) -o $(TEST_NAME) $(CFLAGS) $(SRC) $(SRC_TEST) $(LDFLAGS) $(TEST_FLAGS)
			./unit_tests
			gcovr --exclude tests

.PHONY	:	lib clean fclean re
