/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** exec_cd
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"
#include <unistd.h>
#include <sys/stat.h>

int readchmod(int octal)
{
    int nb1 = 0;
    int nb2 = 0;
    int nb3 = 0;

    nb3 = octal % 2;
    octal -= nb3;
    octal /= 2;
    nb2 = octal % 2;
    octal -= nb2;
    octal /= 2;
    nb1 = octal % 2;
    return nb1;
}

int find_cd_error(char **array)
{
    struct stat info;

    if (stat(array[1], &info) == -1){
        my_puterr(array[1]);
        my_puterr(": No such file or directory.\n");
        return 1;
    }
    if (S_ISDIR(info.st_mode) != 1){
        my_puterr(array[1]);
        my_puterr(": Not a directory.\n");
        return 1;
    }
    if (readchmod(info.st_mode) != 1){
        my_puterr(array[1]);
        my_puterr(": Permission denied.\n");
        return 1;
    }
    return 0;
}

int chdir_old(env_t **env)
{
    env_t *envlist = *env;
    char *newvar = NULL;
    int k = 0;

    for (; envlist != NULL &&
        my_strncmp(envlist->var, "OLDPWD=", my_strlen("OLDPWD=") - 1) != 0;
    envlist = envlist->next);
    if (envlist == NULL){
        my_puterr(": No such file or directory.\n");
        return 1;
    }
    newvar = malloc(sizeof(char) * (my_strlen(envlist->var) - 6));
    if (newvar == NULL)
        return 1;
    k = cd_go_to_old(newvar, envlist, env);
    return k;
}

int find_cd_usage(char **array, env_t **env)
{
    int err = 0;

    if (array[1] == NULL || my_strcmp(array[1], "") == 0 ||
    my_strcmp(array[1], "~") == 0 || my_strncmp(array[1], "~/", 1) == 0){
        err = cd_home(array, env);
        return err;
    }
    if (array[1][0] == '~'){
        err = cd_home_other_user(env, array);
        return err;
    }
    if (my_strcmp(array[1], "-") == 0){
        err = chdir_old(env);
        return err;
    }
    if (find_cd_error(array) == 0 && modify_old_pwd(env) == 0){
        err = modify_pwd(env, array[1]);
        return err;
    }
    return 1;
}

int exec_cd(char **array, env_t **env)
{
    int err = 0;

    if (array[1] != NULL && array[2] != NULL){
        my_puterr("cd: Too many arguments.\n");
        return 1;
    }
    err = find_cd_usage(array, env);
    return err;
}
