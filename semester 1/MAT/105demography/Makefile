##
## EPITECH PROJECT, 2025
## 105demography
## File description:
## Makefile
##

NAME	=	105demography

CFLAGS	=	-W -Wall -Wextra -lm

SRC		=	demography.c \
			math.c \

OBJ		=	$(SRC:.c=.o)

all:	$(OBJ)
		gcc $(OBJ) -o $(NAME) -I include/ $(CFLAGS)
		rm -f *.o

run:
		./$(NAME)

clean:
		rm -f *.o

fclean:	clean
		rm -f $(NAME)

debug:	CFLAGS+= -g
debug:	all

run_debug:	debug
			gdb ./$(NAME) EUU

perf:	fclean
perf:	CFLAGS+= -pg
perf:	all

re:		fclean	all
