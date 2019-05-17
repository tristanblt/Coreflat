##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for corewar
##

NAME	=	corewar

NAME_BONUS	=	coreflat

TEST_NAME	=	unit_tests

MAIN	=	src/main.c

SRC_TEST	=	tests/test_parse_instruction_from_mem.c

SRCBONUS	=	bonus/src/main.c						\
				bonus/src/start_graphical_corewar.c		\
				bonus/src/game_loop.c					\
				bonus/src/init_game.c					\
				bonus/src/draw_interface.c				\
				bonus/src/draw_icons.c					\
				bonus/src/manage_events.c				\
				bonus/src/gradients.c					\
				bonus/src/draw_button.c					\
				bonus/src/draw_corewar.c				\
				bonus/src/draw_credits.c				\
				bonus/src/draw_winner.c					\
				bonus/src/draw_main_menu.c				\
				bonus/src/draw_help.c					\
				bonus/src/draw_choose.c					\
				bonus/src/draw_pause.c					\
				bonus/src/views_manager.c				\
				bonus/src/redirections.c				\
				bonus/src/utils.c						\
				bonus/src/load_all_champions.c			\
				bonus/src/auto_pre_game.c				\
				bonus/src/draw_checkbox.c				\
				bonus/src/draw_choose_next_2.c			\
				bonus/src/draw_choose_next.c			\
				bonus/src/draw_selector.c				\
				bonus/src/draw_settings.c				\
				bonus/src/launch_corewar.c				\
				bonus/src/free_utils.c					\
				bonus/src/editor/draw_editor.c			\
				bonus/src/editor/draw_configuration.c	\
				bonus/src/editor/draw_interface.c		\
				bonus/src/editor/draw_input_number.c	\
				bonus/src/editor/instruction_manager.c	\
				bonus/src/editor/label_manager.c		\
				bonus/src/editor/register_manager.c		\
				bonus/src/editor/save_to_file.c			\

SRC	=	src/parse_instructions.c						\
		src/parse_header.c								\
		src/cycle_manager.c								\
		src/champion_manager.c							\
		../src/op.c										\
		src/processes_manager.c							\
		src/list/add_to_list.c							\
		src/list/create_list.c							\
		src/list/destroy_list.c							\
		src/list/move_in_list.c							\
		src/write_in_mem.c								\
		src/parse_instruction_from_mem.c				\
		src/instructions/add.c							\
		src/instructions/aff.c							\
		src/instructions/and.c							\
		src/instructions/fork.c							\
		src/instructions/ld.c							\
		src/instructions/ldi.c							\
		src/instructions/lfork.c						\
		src/instructions/live.c							\
		src/instructions/lld.c							\
		src/instructions/lldi.c							\
		src/instructions/or.c							\
		src/instructions/st.c							\
		src/instructions/sti.c							\
		src/instructions/sub.c							\
		src/instructions/xor.c							\
		src/instructions/zjmp.c							\
		src/instructions/instruction_utils.c			\
		src/instruction_is_valid.c						\
		src/utils.c										\
		src/dump_memory.c								\
		src/get_nb_from_mem.c							\
		src/arguments_handling.c						\
		src/argument_error_handling.c					\
		src/parse_args.c								\
		src/start_corewar.c								\
		src/free_utils.c							\
		src/end_of_file.c							\

OBJ	=	$(SRC:%.c=%.o) $(MAIN:%.c=%.o)

CFLAGS	=	-W -Wall -Wextra -Wshadow	\
			-Iinclude -I../include		\

LIB	=	my

LIB_PATH=	../lib/my

LDFLAGS	=	-L$(LIB_PATH) -l$(LIB)

SFMLFLAGS = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

TEST_FLAGS	=	-lcriterion --coverage

CC	=	gcc

RM	=	rm -f

all:	$(NAME)

lib	:
		make -C $(LIB_PATH)

$(NAME):$(OBJ) lib
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		make clean -C $(LIB_PATH)
		$(RM) $(OBJ) *.gc*

fclean:	clean
		make fclean -C $(LIB_PATH)
		$(RM) $(NAME) $(NAME_BONUS)
		$(RM) $(TEST_NAME)

re:		fclean all

tests_run:	lib
			$(CC) -o $(TEST_NAME) $(CFLAGS) $(SRC) $(SRC_TEST) $(LDFLAGS) $(TEST_FLAGS)
			./unit_tests
			gcovr --exclude tests

bonus:	lib
		$(CC) -o $(NAME_BONUS) $(SRC) $(SRCBONUS) $(CFLAGS) $(LDFLAGS) $(SFMLFLAGS)

.PHONY:	lib clean fclean re bonus
