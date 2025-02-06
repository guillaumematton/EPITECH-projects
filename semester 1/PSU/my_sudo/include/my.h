/*
** EPITECH PROJECT, 2025
** sudo
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <crypt.h>
    #include <termios.h>
    #include <stddef.h>

void print_help(void);
int passwd_input(char *login);
int shell_case(const char *login);
int my_strlen(char const *str);
int user_case(char **argv);
void double_free(char *line, FILE *file);
int execute_as_root(char **argv, int i);
void enable_echo(void);
void disable_echo(void);
int group_case(char **argv);
void my_putchar(char c);
int my_putstr(char const *str);
void apply_shell(char *shell, char *line, FILE *file);

#endif /* !MY_H_ */
