/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** exec_setenv
*/

#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>

int replace_env(env_t *env, char **array)
{
    int size = my_strlen(array[1]) + 2;

    free(env->var);
    if (array[2] != NULL)
        size += my_strlen(array[2]) + 1;
    env->var = malloc(sizeof(char) * size);
    if (env->var == NULL)
        return 1;
    my_strcpy(env->var, array[1]);
    my_strcat(env->var, "=");
    if (array[2] != NULL)
        my_strcat(env->var, array[2]);
    return 0;
}

int add_env(char **array, env_t **envp)
{
    env_t *tempenv = NULL;
    int size = my_strlen(array[1]) + 2;

    tempenv = malloc(sizeof(env_t));
    if (tempenv == NULL)
        return 1;
    if (array[2] != NULL)
        size += my_strlen(array[2]) + 1;
    tempenv->var = malloc(sizeof(char) * (size));
    if (tempenv->var == NULL){
        free(tempenv);
        return 1;
    }
    my_strcpy(tempenv->var, array[1]);
    my_strcat(tempenv->var, "=");
    if (array[2] != NULL)
        my_strcat(tempenv->var, array[2]);
    tempenv->next = *envp;
    *envp = tempenv;
    return 0;
}

int find_err(char **array)
{
    if (array[2] != NULL && array[3] != NULL){
        my_puterr("setenv: Too many arguments.\n");
        return 1;
    }
    if (('A' > array[1][0] || 'Z' < array[1][0] &&
        'a' > array[1][0] || 'z' < array[1][0]) && array[1][0] != '_'){
        my_puterr("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    if (my_str_isalphanum(array[1]) == 0){
        my_puterr("setenv: Variable name must");
        my_puterr(" contain alphanumeric characters.\n");
        return 1;
    }
    return 0;
}

int exec_setenv(char **array, env_t **environ)
{
    env_t *envlist = *environ;
    int err = 0;

    if (array[1] == NULL || my_strcmp(array[1], "") == 0){
        err = exec_env(array, environ);
        return err;
    }
    err = find_err(array);
    if (err != 0)
        return err;
    for (; envlist != NULL &&
        my_strncmp(envlist->var, array[1], my_strlen(array[1]) - 1) != 0;
        envlist = envlist->next);
    if (envlist != NULL &&
        my_strncmp(envlist->var, array[1], my_strlen(array[1]) - 1) == 0)
        err = replace_env(envlist, array);
    else
        err = add_env(array, environ);
    return err;
}
