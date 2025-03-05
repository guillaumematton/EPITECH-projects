/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** if_tty
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include "../include/my.h"

int find_tty(void)
{
    struct stat info;

    if (fstat(0, &info) == 0)
        if ((S_ISREG(info.st_mode) && info.st_size != 0) ||
            S_ISFIFO(info.st_mode))
            return 1;
    return 0;
}

char *if_not_tty(char *buffer, size_t len)
{
    ssize_t templen = 0;

    if (isatty(0) && isatty(1))
        my_putstr("$> ");
    if (find_tty() || (isatty(0) && isatty(1))){
        templen = getline(&buffer, &len, stdin);
    }
    if (buffer == NULL || templen == -1)
        return NULL;
    if (buffer[0] != '\n' && buffer[my_strlen(buffer) - 1] == '\n')
        buffer[my_strlen(buffer) - 1] = '\0';
    if (isatty(0) && isatty(1))
        my_putstr("\b\b\b");
    return buffer;
}
