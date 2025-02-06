##
## EPITECH PROJECT, 2025
## sudo
## File description:
## Makefile
##

NAME = my_sudo

ROOT =	main.c			\
		echo.c			\
		get_passwd.c	\
		help.c			\
		exec_as_root.c	\
		shell_case.c	\
		user_case.c		\
		group_case.c	\
		my_putchar.c	\
		my_putstr.c		\

ROBJ = $(ROOT:.c=.o)

CFLAGS = -Wall -Wextra -W -fanalyzer

all: compile

compile: $(ROBJ)
	gcc -o $(NAME) $(ROBJ) -I include/ -lcrypt 
	chmod +s $(NAME)

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

debug:	fclean
	gcc -g -o $(NAME) $(ROOT) -I include/ -lcrypt $(CFLAGS)
	chmod +s $(NAME)

re: fclean	all
