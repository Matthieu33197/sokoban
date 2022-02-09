##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make to file
##

SRC     =	my_sokoban.c			\

OBJ	=	$(SRC:.c=.o)

NAME 	= 	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -g3 -o $(NAME) $(OBJ) -L./lib/my -lmy -lncurses

clean:
	make clean -C lib/my
	rm -rf $(OBJ)

re:	fclean all

fclean: clean
	rm -rf $(NAME)

.PHONY: all clean fclean re
