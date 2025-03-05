/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** cd_home
*/

#include "../include/my.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int cd_go_to_old(char *newvar, env_t *envlist, env_t **env)
{
    int k = 0;

    my_strcpy_from_n(newvar, envlist->var, 7);
    if (modify_old_pwd(env) == 1){
        free(newvar);
        return 1;
    }
    chdir(newvar);
    k = modify_pwd(env, newvar);
    free(newvar);
    return k;
}

int cd_move_to_other_user(char *path, char *user, char **array, env_t **env)
{
    int k = 0;

    my_strcpy(path, "/home");
    my_strcpy_from_n(user, array[1], 1);
    my_strcat(path, user);
    if (chdir(user) == -1){
        my_puterr("Unknown user: ");
        my_puterr(user);
        my_puterr(".\n");
        free(user);
        free(path);
        return 1;
    }
    free(user);
    k = modify_pwd(env, path);
    free(path);
    return k;
}

int cd_home_other_user(env_t **env, char **array)
{
    char *user = NULL;
    char *path = NULL;
    int k = 0;

    if (modify_old_pwd(env) == 1)
        return 1;
    path = malloc(sizeof(char) * my_strlen(array[1]) + my_strlen("/home"));
    if (path == NULL)
        return 1;
    user = malloc(sizeof(char) * my_strlen(array[1]));
    if (user == NULL){
        free(path);
        return 1;
    }
    k = cd_move_to_other_user(path, user, array, env);
    return k;
}

int get_end_path(char **array, char *newpath, env_t *envlist, env_t **env)
{
    char *endpath = NULL;
    int err = 0;

    my_strcpy_from_n(newpath, envlist->var, my_strlen("USER_ZDOTDIR="));
    if (array[1] != NULL && array[1][1] == '/') {
        endpath = malloc(sizeof(char) * my_strlen(array[1]));
        if (endpath == NULL)
            return 1;
        my_strcpy_from_n(endpath, array[1], 1);
        my_strcat(newpath, endpath);
    }
    err = modify_pwd(env, newpath);
    if (err != 0){
        my_puterr(newpath);
        my_puterr(": No such file or directory.");
    }
    return err;
}

int cd_home(char **array, env_t **env)
{
    env_t *envlist = *env;
    int size = 0;
    char *newpath = NULL;
    int err = 0;

    if (modify_old_pwd(env) == 1)
        return 1;
    for (; envlist != NULL &&
        my_strncmp(envlist->var, "USER_ZDOTDIR=",
            my_strlen("USER_ZDOTDIR=") - 1) != 0;
        envlist = envlist->next);
    size += my_strlen(envlist->var) - my_strlen("USER_ZDOTDIR=");
    if (array[1] != NULL)
        size += my_strlen(array[1]);
    newpath = malloc(sizeof(char) * size);
    if (newpath == NULL)
        return 1;
    err = get_end_path(array, newpath, envlist, env);
    return err;
}
