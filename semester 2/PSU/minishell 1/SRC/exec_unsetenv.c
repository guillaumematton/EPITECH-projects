/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** exec_unsetenv
*/

#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>

void move_env(env_t *envlist, env_t *oldenv, env_t *next_env, env_t **env)
{
    if (oldenv == NULL){
        free(envlist->var);
        free(envlist);
        *env = next_env;
        return;
    }
    free(envlist->var);
    free(envlist);
    oldenv->next = next_env;
}

int exec_unsetenv(char **array, env_t **env)
{
    env_t *envlist = *env;
    env_t *oldenv = NULL;
    env_t *next_env = envlist->next;

    if (array[1] == NULL){
        my_puterr("unsetenv: Too few arguments.\n");
        return 1;
    }
    while (envlist != NULL && my_strncmp(envlist->var, array[1],
        my_strlen(array[1]) - 1)){
        oldenv = envlist;
        envlist = envlist->next;
        if (envlist == NULL)
            return 0;
        next_env = envlist->next;
    }
    move_env(envlist, oldenv, next_env, env);
    return 0;
}
