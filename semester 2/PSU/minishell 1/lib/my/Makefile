##
## EPITECH PROJECT, 2025
## lib
## File description:
## Makefile
##

NAME = libmy.a

ROOT = 	find_alphanum.c				\
		free_array.c				\
		free_linked_list.c			\
		my_arraycpy.c				\
		my_compute_power_rec.c		\
		my_compute_square_root.c	\
		my_find_prime_sup.c			\
		my_getnbr.c					\
		my_isneg.c					\
		my_is_prime.c				\
		my_putchar.c				\
		my_put_nbr.c				\
		my_putstr.c					\
		my_rev_list.c				\
		my_revstr.c					\
		my_show_word_array.c		\
		my_strcapitalize.c			\
		my_strcat.c					\
		my_strcmp.c					\
		my_strcpy.c					\
		my_strcpy_from_n.c			\
		my_str_isalphanum.c			\
		my_str_islower.c			\
		my_str_isnum.c				\
		my_str_isprintable.c		\
		my_str_isupper.c			\
		my_strlen.c					\
		my_strlowcase.c				\
		my_strncat.c				\
		my_strncmp.c				\
		my_strncpy.c 				\
		my_strstr.c 				\
		my_strupcase.c 				\
		my_swap.c 					\
		my_str_to_word_array.c		\

ROBJ = $(ROOT:.c=.o)

all:	$(ROBJ)
	ar rc $(NAME) $(ROBJ)
	mv $(NAME) ../../$(NAME)

clean:
	rm -f $(ROBJ)

fclean:	clean
	rm -f ../../$(NAME)

re:	fclean	all
