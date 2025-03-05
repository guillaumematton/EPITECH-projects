/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** modify_env
*/

#include "../include/my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int set_newvar(size_t size, char *newpath, env_t *envlist, char *line)
{
    char *newvar = NULL;

    if (envlist == NULL)
        return 1;
    newvar = malloc(sizeof(char) * (size + my_strlen(line)));
    if (newvar == NULL){
        free(newpath);
        return 1;
    }
    my_strcpy(newvar, line);
    my_strcat(newvar, newpath);
    free(envlist->var);
    envlist->var = newvar;
    free(newpath);
    return 0;
}

int modify_pwd(env_t **env, char *path)
{
    env_t *envlist = *env;
    char *newpath = NULL;
    size_t size = my_strlen(path) + 1;

    chdir(path);
    for (; envlist != NULL &&
        my_strncmp(envlist->var, "PWD=", my_strlen("PWD=") - 1) != 0;
        envlist = envlist->next);
    if (envlist == NULL)
        return 1;
    size += my_strlen(envlist->var);
    newpath = malloc(sizeof(char) * size);
    if (newpath == NULL)
        return 1;
    getcwd(newpath, size);
    if (newpath == NULL)
        return 1;
    if (set_newvar(size, newpath, envlist, "PWD=") == 1)
        return 1;
    return 0;
}

env_t *get_oldpwd(env_t **env)
{
    env_t *envlist = *env;

    for (; envlist != NULL &&
        my_strncmp(envlist->var, "OLDPWD=", my_strlen("OLDPWD=") - 1) != 0;
        envlist = envlist->next);
    return envlist;
}

int modify_old_pwd(env_t **env)
{
    env_t *envlist = *env;
    char *newpath = NULL;
    size_t size = 4;

    for (; envlist != NULL &&
        my_strncmp(envlist->var, "PWD=", my_strlen("PWD=") - 1) != 0;
        envlist = envlist->next);
    if (envlist == NULL)
        return 1;
    size += my_strlen(envlist->var);
    newpath = malloc(sizeof(char) * size);
    if (newpath == NULL)
        return 1;
    getcwd(newpath, size);
    if (newpath == NULL)
        return 1;
    envlist = get_oldpwd(env);
    size = set_newvar(size, newpath, envlist, "OLDPWD=");
    return size;
}
