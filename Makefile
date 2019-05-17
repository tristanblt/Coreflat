##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for
##

COREFLAT = coreflat

SRC_COREFLAT =	bonus/src/main.c										\
				bonus/src/start_graphical_corewar.c						\
				bonus/src/game_loop.c									\
				bonus/src/init_game.c									\
				bonus/src/draw_interface.c								\
				bonus/src/draw_icons.c									\
				bonus/src/manage_events.c								\
				bonus/src/gradients.c									\
				bonus/src/draw_button.c									\
				bonus/src/draw_corewar.c								\
				bonus/src/draw_credits.c								\
				bonus/src/draw_winner.c									\
				bonus/src/draw_main_menu.c								\
				bonus/src/draw_help.c									\
				bonus/src/draw_choose.c									\
				bonus/src/draw_pause.c									\
				bonus/src/views_manager.c								\
				bonus/src/redirections.c								\
				bonus/src/utils.c										\
				bonus/src/load_all_champions.c							\
				bonus/src/auto_pre_game.c								\
				bonus/src/draw_checkbox.c								\
				bonus/src/draw_choose_next_2.c							\
				bonus/src/draw_choose_next.c							\
				bonus/src/draw_selector.c								\
				bonus/src/draw_settings.c								\
				bonus/src/launch_corewar.c								\
				bonus/src/free_utils.c									\
				bonus/src/editor/draw_editor.c							\
				bonus/src/editor/draw_configuration.c					\
				bonus/src/editor/draw_interface.c						\
				bonus/src/editor/draw_input_number.c					\
				bonus/src/editor/instruction_manager.c					\
				bonus/src/editor/label_manager.c						\
				bonus/src/editor/register_manager.c						\
				bonus/src/editor/save_to_file.c							\
				corewar/src/parse_instructions.c						\
				corewar/src/parse_header.c								\
				corewar/src/cycle_manager.c								\
				corewar/src/champion_manager.c							\
				src/op.c										\
				corewar/src/processes_manager.c							\
				corewar/src/list/add_to_list.c							\
				corewar/src/list/create_list.c							\
				corewar/src/list/destroy_list.c							\
				corewar/src/list/move_in_list.c							\
				corewar/src/write_in_mem.c								\
				corewar/src/parse_instruction_from_mem.c				\
				corewar/src/instructions/add.c							\
				corewar/src/instructions/aff.c							\
				corewar/src/instructions/and.c							\
				corewar/src/instructions/fork.c							\
				corewar/src/instructions/ld.c							\
				corewar/src/instructions/ldi.c							\
				corewar/src/instructions/lfork.c						\
				corewar/src/instructions/live.c							\
				corewar/src/instructions/lld.c							\
				corewar/src/instructions/lldi.c							\
				corewar/src/instructions/or.c							\
				corewar/src/instructions/st.c							\
				corewar/src/instructions/sti.c							\
				corewar/src/instructions/sub.c							\
				corewar/src/instructions/xor.c							\
				corewar/src/instructions/zjmp.c							\
				corewar/src/instructions/instruction_utils.c			\
				corewar/src/instruction_is_valid.c						\
				corewar/src/utils.c										\
				corewar/src/dump_memory.c								\
				corewar/src/get_nb_from_mem.c							\
				corewar/src/arguments_handling.c						\
				corewar/src/argument_error_handling.c					\
				corewar/src/parse_args.c								\
				corewar/src/start_corewar.c								\
				corewar/src/free_utils.c								\
				corewar/src/end_of_file.c								\

OBJ	=	$(SRC_COREFLAT:%.c=%.o)

CFLAGS	=	-W -Wall -Wextra -Wshadow	\
			-Icorewar/include -Iinclude		\

SFMLFLAGS = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

LIB		=	my

LIB_PATH	=	lib/my

LDFLAGS	=	-L$(LIB_PATH) -l$(LIB) $(SFMLFLAGS)

CC = gcc

RM	=	rm -f

all	:
		make -C asm
		make -C corewar

clean	:
		$(RM) $(OBJ) *.gc*
		make clean -C asm
		make clean -C corewar

fclean	: clean
		$(RM) $(COREFLAT)
		make fclean -C asm
		make fclean -C corewar

re	:	fclean all

$(COREFLAT): $(OBJ)
		make lib -C corewar
		$(CC) -o $(COREFLAT) $(OBJ) $(CFLAGS) $(LDFLAGS)

.PHONY	:	clean fclean re
