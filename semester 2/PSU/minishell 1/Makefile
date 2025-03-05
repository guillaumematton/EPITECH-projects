##
## EPITECH PROJECT, 2025
## sudo
## File description:
## Makefile
##

NAME = mysh

ROOT =	SRC/main.c			\
		SRC/exec_cd.c		\
		SRC/exec_env.c		\
		SRC/exec_setenv.c	\
		SRC/exec_unsetenv.c	\
		SRC/exec_cmd.c		\
		SRC/modify_env.c	\
		SRC/if_not_tty.c	\
		SRC/cd_home.c		\
		SRC/cmd_error.c		\

ROBJ = $(ROOT:.c=.o)

FLAGS = -Wall -Wextra -W -fanalyzer

all: lib	compile

lib:	$(ROBJ)
	cd lib/my ; make -s

compile:
	gcc -o $(NAME) $(ROBJ) -I include/ -L. -lmy

clean:
	rm -f $(ROBJ)
	cd lib/my ; make clean -s

fclean:	clean
	rm -f $(NAME)
	cd lib/my ; make fclean -s

run:	all
	./$(NAME)

debug:	fclean	lib
	gcc -g -o $(NAME) $(ROOT) -I include/ -L. -lmy $(FLAGS)

re: fclean	all
