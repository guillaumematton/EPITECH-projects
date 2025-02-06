##
## EPITECH PROJECT, 2024
## count words
## File description:
## Makefile
##

ROOT = main.c \
	stock_word.c \

ROBJ = $(ROOT:.c=.o)

NAME = countwords

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
