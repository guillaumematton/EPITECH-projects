/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** exec_env
*/

#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>

env_t *reverse_list(env_t *ele, env_t *prevele, env_t *nextele)
{
    while (ele != NULL){
        nextele = ele->next;
        ele->next = prevele;
        prevele = ele;
        ele = nextele;
    }
    return prevele;
}

int exec_env(char **array, env_t **env)
{
    env_t *ele = *env;
    env_t *prevele = NULL;
    env_t *nextele = NULL;

    if (array[1] != NULL)
        return 1;
    prevele = reverse_list(ele, prevele, nextele);
    ele = prevele;
    for (; prevele != NULL; prevele = prevele->next){
        my_putstr(prevele->var);
        my_putchar('\n');
    }
    reverse_list(ele, prevele, nextele);
    return 0;
}
