##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for
##

SRCPATH = src

BONUSPATH	=	bonus/src

NAME	=	asm

NAME_BONUS	=	disasm

SRC_BONUS	=	$(BONUSPATH)/main.c				\
			$(BONUSPATH)/parse_header.c			\
			$(BONUSPATH)/parse_instruction_from_file.c	\
			$(BONUSPATH)/parse_instruction_and_header.c	\
			$(BONUSPATH)/compute_instructions_sizes.c	\
			$(BONUSPATH)/destroy_instructions.c		\
			$(BONUSPATH)/label.c				\
			$(BONUSPATH)/utils.c				\
			$(BONUSPATH)/write_file.c			\
			../src/op.c					\

SRC	=	../src/op.c										\
		$(SRCPATH)/main.c								\
		$(SRCPATH)/encode_instructions_to_file.c		\
		$(SRCPATH)/arguments_handling.c					\
		$(SRCPATH)/error_handling_and_parsing.c			\
		$(SRCPATH)/get_file.c							\
		$(SRCPATH)/multiple_split.c						\
		$(SRCPATH)/my_strncpy.c							\
		$(SRCPATH)/free_utils.c							\
		$(SRCPATH)/instruction_get_code.c				\
		$(SRCPATH)/argument_type.c						\
		$(SRCPATH)/parse_instruction.c					\
		$(SRCPATH)/writing_in_file.c					\
		$(SRCPATH)/utils.c								\
		$(SRCPATH)/get_header.c							\
		$(SRCPATH)/get_instruction_size.c				\
		$(SRCPATH)/labels.c								\
		$(SRCPATH)/check_multiple_label_definitions.c	\
		$(SRCPATH)/compute_instruction_size.c			\
		$(SRCPATH)/char_is_in_string.c					\


OBJ	=	$(SRC:%.c=%.o)

OBJ_BONUS	=	$(SRC_BONUS:%.c=%.o)

CFLAGS	=	-W -Wall -Wextra -Wshadow	\
		-Iinclude -I../include -g	\

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
		$(RM) $(OBJ) $(OBJ_BONUS)

fclean	:	clean
		make fclean -C $(LIB_PATH)
		$(RM) $(NAME) $(NAME_BONUS)

re	:	fclean all

bonus	:	$(OBJ_BONUS) lib
		$(CC) -o $(NAME_BONUS) $(OBJ_BONUS) $(LDFLAGS)

.PHONY	:	lib clean fclean re bonus
