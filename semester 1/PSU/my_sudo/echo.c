/*
** EPITECH PROJECT, 2025
** sudo
** File description:
** echo
*/

#include "include/my.h"

void double_free(char *line, FILE *file)
{
    free(line);
    fclose(file);
}

void enable_echo(void)
{
    struct termios term;

    tcgetattr(fileno(stdin), &term);
    term.c_lflag |= ECHO;
    tcsetattr(fileno(stdin), 0, &term);
}

void disable_echo(void)
{
    struct termios term;

    tcgetattr(fileno(stdin), &term);
    term.c_lflag &= ~ECHO;
    tcsetattr(fileno(stdin), 0, &term);
}
