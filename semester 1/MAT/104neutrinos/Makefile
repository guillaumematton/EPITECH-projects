##
## EPITECH PROJECT, 2024
## make
## File description:
## makefile
##

ROOT =	main.c
ROOT += help.c
ROOT += mean.c

ROBJ = $(ROOT:.c=.o)

NAME = 104neutrinos

all: 104neutrinos

104neutrinos:	$(ROBJ)
	gcc -o $(NAME) $(ROBJ) -I include/ -lm

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

debug:
	gcc -g -o $(NAME) $(ROOT) -I include/ -lm

re: fclean all
