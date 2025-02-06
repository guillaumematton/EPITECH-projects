##
## EPITECH PROJECT, 2024
## makefile
## File description:
## make a file
##

NAME 	=	libmy.a

OBJ	=	$(SRC:.c=.o)

SRC	= 		lib/my/my_compute_power_rec.c  \
			lib/my/my_compute_square_root.c        \
			lib/my/my_find_prime_sup.c     \
			lib/my/my_getnbr.c     \
			lib/my/my_isneg.c      \
			lib/my/my_is_prime.c   \
			lib/my/my_putchar.c    \
			lib/my/my_put_nbr.c    \
			lib/my/my_putstr.c     \
			lib/my/my_revstr.c     \
			lib/my/my_showmem.c    \
			lib/my/my_showstr.c    \
			lib/my/my_sort_int_array.c     \
			lib/my/my_strcapitalize.c      \
			lib/my/my_strcat.c     \
			lib/my/my_strcmp.c     \
			lib/my/my_strcpy.c     \
			lib/my/my_str_isalpha.c        \
			lib/my/my_str_islower.c        \
			lib/my/my_str_isnum.c  \
			lib/my/my_str_isprintable.c    \
			lib/my/my_str_isupper.c        \
			lib/my/my_strlen.c     \
			lib/my/my_strlowcase.c \
			lib/my/my_strncat.c    \
			lib/my/my_strncmp.c    \
			lib/my/my_strncpy.c    \
			lib/my/my_strstr.c     \
			lib/my/my_strupcase.c  \
			lib/my/my_swap.c       \
			rush1_1_check.c	\
			rush1_2_check.c	\
			rush1_3_check.c	\
			rush1_4_check.c	\
			rush1_5_check.c	\
			final_stumper.c	\

all: $(NAME) run

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f rush3

re: fclean all

run:
	gcc -o rush3 main.c -L. libmy.a
