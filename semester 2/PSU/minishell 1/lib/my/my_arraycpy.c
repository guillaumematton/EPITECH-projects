/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my_arraycpy
*/

#include "../../include/lib.h"
#include <stdlib.h>
#include <stdio.h>

int my_arraycpy(char **env, char **tempenv)
{
    int i = 0;

    for (; env[i] != NULL; i++);
    tempenv = malloc(sizeof(char *) * (i + 1));
    if (tempenv == NULL)
        return 84;
    for (i = 0; env[i] != NULL; i++) {
        tempenv[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        if (tempenv[i] == NULL)
            return 84;
        my_strcpy(tempenv[i], env[i]);
    }
    tempenv[i] = NULL;
    return 0;
}
