##
## EPITECH PROJECT, 2025
## Secured
## File description:
## Makefile
##

NAME = libhashtable.a

CFLAGS	=		-W -Wall -Wextra

SRC		=		includes/hashtable.h\
				lib/my_putchar.c\
				lib/my_strlen.c\
				lib/my_putstr.c\
				lib/my_put_nbr.c\
				secured.c\
				ht_table.c

OBJ		=		$(SRC:.c=.o)

all:		$(OBJ)
		ar rc $(NAME) $(OBJ)

run:
		./$(NAME)

unit_tests:
		make fclean
		make unit_tests -C tests/

tests_run:
		make unit_tests
		make tests_run -C tests/
		gcovr --exclude tests/
		gcovr --exclude tests/ --txt-metric branch
		make tests_run -C tests/

clean:
		rm -rf *.o
		rm -f tests/*.gcdo
		rm -f tests/*.gcda
		rm -f lib/*.o

fclean:	clean
		rm -f $(NAME)
		make fclean -C tests/

debug:	CFLAGS+= -g
debug:	all

perf:	fclean
perf:	CFLAGS+= -pg
perf:	all

re:		fclean	all
