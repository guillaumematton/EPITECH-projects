##
## EPITECH PROJECT, 2024
## make
## File description:
## makefile
##


SRC = 	lib/my/my_compute_power_rec.c	\
	lib/my/my_compute_square_root.c	\
	lib/my/my_find_prime_sup.c	\
	lib/my/my_getnbr.c	\
	lib/my/my_isneg.c	\
	lib/my/my_is_prime.c	\
	lib/my/my_putchar.c	\
	lib/my/my_put_nbr.c	\
	lib/my/my_putstr.c	\
	lib/my/my_revstr.c	\
	lib/my/my_showmem.c	\
	lib/my/my_showstr.c	\
	lib/my/my_show_word_array.c	\
	lib/my/my_sort_int_array.c	\
	lib/my/my_strcapitalize.c	\
	lib/my/my_strcat.c	\
	lib/my/my_strcmp.c	\
	lib/my/my_strcpy.c	\
	lib/my/my_str_isalpha.c	\
	lib/my/my_str_islower.c	\
	lib/my/my_str_isnum.c	\
	lib/my/my_str_isprintable.c	\
	lib/my/my_str_isupper.c	\
	lib/my/my_strlen.c	\
	lib/my/my_strlowcase.c	\
	lib/my/my_strncat.c	\
	lib/my/my_strncmp.c	\
	lib/my/my_strncpy.c \
	lib/my/my_strstr.c \
	lib/my/my_strupcase.c \
	lib/my/my_swap.c \
	lib/my/my_printf.c \
	lib/my/switchcaseflag.c \
	lib/my/switchcaseconv.c \
	lib/my/complementaryfunctions.c \
	lib/my/convspecifier.c \
	lib/my/more_functions.c \
	lib/my/specifier_mna.c \
	lib/my/miniprintffoncition.c \

OBJ = $(SRC:.c=.o)

NAME = 101pong

all: libmy.a 101pong

libmy.a: $(OBJ)
	ar rc libmy.a $(OBJ)

101pong: $(OBJ)
	gcc -g -o $(NAME) pong.c -I include/ -L. -lmy -lm

clean:
	rm -f $(OBJ)
	rm -f lib/my/$(OBJ)

fclean: clean
	rm -f $(NAME) 101pong

re: fclean all

val:
	gcc -g -o $(NAME) pong.c -I include/ -L. -lmy -lm
	valgrind -s --leak-check=full --track-origins=yes
    --show-leak-kinds=all ./$(NAME)
