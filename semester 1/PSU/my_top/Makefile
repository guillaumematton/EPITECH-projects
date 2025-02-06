##
## EPITECH PROJECT, 2024
## my_top
## File description:
## compiling my_top
##

NAME = my_top

ROOT = main.c \
	header_first_line.c \
	header_second_line.c \
	header_third_line.c \
	header_fourth_line.c \
	header_fifth_line.c \
	list_files.c \
	help_second_line.c \

all:  top

top:
	gcc -g -o $(NAME) $(ROOT) -I include/ -lncurses

clean:

fclean: clean
	rm -f $(NAME)

re : fclean all
