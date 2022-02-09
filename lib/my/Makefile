##
## EPITECH PROJECT, 2019
## make
## File description:
## files
##

SRC	=	mem_alloc_2d_array.c	\
		other_func3.c		\
		other_func2.c		\
		other_func1.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mkdir -p ../../include
	cp my.h -p ../../include/

clean:
		rm -rf *.o

fclean:		clean

