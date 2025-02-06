##
## EPITECH PROJECT, 2024
## makefile
## File description:
## for cat
##

NAME = cat

SRC = $(wildcard *.c)

ERROR = -Wall -Wextra

all:	comp

comp:	$(SRC)
		gcc -o cat $(SRC) -I ../include -L ../lib/my -lmy

clean:
		rm -f $(NAME)

fclean: clean

re:		fclean
