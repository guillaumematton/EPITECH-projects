##
## EPITECH PROJECT, 2024
## make
## File description:
## makefile
##

ROOT =	main.c \
		help.c \
		encrypt_2x2.c \
		encrypt_3x3.c \
		print_matrix.c \

NAME = 103cipher

all: 103cipher

103cipher:
	gcc -g -o $(NAME) $(ROOT) -I include/

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
