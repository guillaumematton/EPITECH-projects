##
## EPITECH PROJECT, 2024
## make
## File description:
## makefile
##

NAME = 102architect

ROOT = architect.c \
	phrases.c \
	set_matrix.c \
	multiply_matrix.c \
	reading_matrix.c \

all: 102architect

102architect:
	gcc -g -o $(NAME) $(ROOT) -I include/ -lm

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
