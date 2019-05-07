##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##


NAME = test

SRC = 	src/main.c				\

CFLAGS = -W -Wall -Wextra -I ./include

OBJ = $(SRC:%.c=%.o)

LIB = -L ./lib/my -lmy

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C ./lib/my

fclean:	clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./lib/my

re:	fclean all
