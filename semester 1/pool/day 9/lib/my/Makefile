##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## make executables
##

NAME = libmy.a

SRC = *.c

ERROR = -Werror -Wall -Wextra

all:	cpy		lib

cpy:
		cp my.h ../../include/my.h

lib:
		gcc -c *.c
		ar rc libmy.a *.o
		cp libmy.a ../libmy.a

clean:
		rm *.o

fclean:	clean
		rm -f ../libmy.a
		rm -f ../../include/my.h

re:		fclean all
