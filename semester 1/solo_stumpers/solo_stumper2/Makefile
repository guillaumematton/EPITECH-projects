##
## EPITECH PROJECT, 2024
## anagram
## File description:
## Makefile
##

ROOT = main.c \

ROBJ = $(ROOT:.c=.o)

NAME = anagram

all: compile

compile: $(ROBJ)
	gcc -o $(NAME) $(ROBJ) -I include/

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean	all

debug: fclean
	gcc -g -o $(NAME) $(ROOT) -I include/
