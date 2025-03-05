/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** cmd_error
*/

#include "../include/my.h"
#include <unistd.h>

void cmd_err(char *oldpath, char **tenv)
{
    my_puterr(oldpath);
    if (oldpath[0] != '/')
        my_puterr(": Command not found.\n");
    else
        my_puterr(": Permission denied.\n");
    double_free(oldpath, tenv);
    _exit(1);
}
