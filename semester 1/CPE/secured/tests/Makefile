##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## makefile test
##

NAME	=	test_of_secured

TEST 	=	../includes/hashtable.h\
			../lib/my_putchar.c\
        	../lib/my_strlen.c\
        	../lib/my_putstr.c\
        	../lib/my_put_nbr.c\
        	../ht_table.c\
        	../secured.c\
        	secured_test.c

unit_tests:
			gcc -o $(NAME) $(TEST) --coverage -lcriterion -I ..includes/

clean:
			rm -f *.o
			rm -f *.gcno
			rm -f *.gcda

fclean: clean
			rm -f test_of_secured

re:
			make unit_tests
			make clean

tests_run:
			./$(NAME) || true
