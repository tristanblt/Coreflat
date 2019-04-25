##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for
##

all	:
		make -C asm
		make -C corewar

clean	:
		make clean -C asm
		make clean -C corewar

fclean	:
		make fclean -C asm
		make fclean -C corewar

re	:	fclean all

.PHONY	:	clean fclean re
