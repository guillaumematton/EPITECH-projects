/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"

int find_cmd(char **array, env_t **environ)
{
    int err = 0;

    if (my_strcmp(array[0], "env") == 0)
        err = exec_env(array, environ);
    if (my_strcmp(array[0], "setenv") == 0)
        err = exec_setenv(array, environ);
    if (my_strcmp(array[0], "unsetenv") == 0)
        err = exec_unsetenv(array, environ);
    if (my_strcmp(array[0], "cd") == 0)
        err = exec_cd(array, environ);
    if (my_strcmp(array[0], "cd") != 0 && my_strcmp(array[0], "unsetenv") != 0
        && my_strcmp(array[0], "setenv") != 0 &&
        my_strcmp(array[0], "env") != 0)
        err = exec_cmd(array, environ);
    return err;
}

int get_ressources(char *buffer, env_t **environ)
{
    char **array = my_str_to_word_array(buffer);
    int err = 0;

    if (array == NULL)
        return 0;
    err = find_cmd(array, environ);
    free_array(array);
    buffer[0] = '\0';
    return err;
}

int shell_loop(env_t **environ)
{
    char *buffer = NULL;
    size_t len = -1;
    int err = 0;

    while (1){
        buffer = if_not_tty(buffer, len);
        if (buffer == NULL || my_strcmp(buffer, "exit") == 0 ||
            my_strcmp("", buffer) == 0)
            break;
        if (my_strlen(buffer) != 0 && my_strcmp(buffer, "\n") != 0)
            err = get_ressources(buffer, environ);
        if (isatty(1) == 0 && isatty(0) == 0 && err != 0)
            return err;
    }
    if (buffer != NULL && my_strcmp(buffer, "exit") == 0)
        my_putstr("exit\n");
    free(buffer);
    return err;
}

int set_environ(env_t **environ, char *env)
{
    env_t *tempenv = malloc(sizeof(env_t));
    env_t *envlist = *environ;

    if (tempenv == NULL)
        return 1;
    tempenv->var = malloc(sizeof(char) * (my_strlen(env) + 1));
    if (tempenv->var == NULL){
        free(tempenv);
        return 1;
    }
    my_strcpy(tempenv->var, env);
    tempenv->next = NULL;
    if (envlist == NULL)
        *environ = tempenv;
    else {
        tempenv->next = envlist;
        *environ = tempenv;
    }
    return 0;
}

int main(int argc, char **argv, char **env)
{
    int err = 0;
    env_t *environ = NULL;

    for (int i = 0; env[i] != NULL; i++)
        if (set_environ(&environ, env[i]) == 1){
            free_linked_list(&environ);
            return 84;
        }
    (void)argv;
    if (argc != 1){
        my_puterr("Error : mysh does not take any arguments.\n");
        return 84;
    }
    err = shell_loop(&environ);
    free_linked_list(&environ);
    return err;
}
