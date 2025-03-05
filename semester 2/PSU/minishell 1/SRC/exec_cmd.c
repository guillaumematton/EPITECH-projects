/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** exec_cmd
*/

#include "../include/my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

char **env(env_t **environ)
{
    char **tenv;
    int size = 0;
    int i = 0;
    env_t *tempenv = *environ;

    for (; tempenv != NULL; size++)
        tempenv = tempenv->next;
    tenv = malloc(sizeof(char *) * (size + 1));
    if (tenv == NULL)
        _exit(1);
    tempenv = *environ;
    for (i = 0; tempenv != NULL; tempenv = tempenv->next){
        tenv[i] = tempenv->var;
        i++;
    }
    tenv[i] = NULL;
    return tenv;
}

void double_free(char *oldpath, char **tenv)
{
    free(oldpath);
    free(tenv);
}

char *new_path(char **array)
{
    char *path = malloc(sizeof(char) *
        (my_strlen(array[0]) + my_strlen("/bin/") + 1));

    if (path == NULL)
        _exit(1);
    my_strcpy(path, "/bin/");
    my_strcat(path, array[0]);
    return path;
}

void execve_cmd(char **array, env_t **environ)
{
    char *path = NULL;
    char *oldpath = array[0];
    char **tenv = NULL;
    struct stat info;

    if (stat(array[0], &info) == -1 || my_strncmp(array[0], "/", 0) &&
        my_strncmp(array[0], ".", 0)){
        path = new_path(array);
        array[0] = path;
    }
    tenv = env(environ);
    if (execve(array[0], array, tenv) < 0)
        cmd_err(oldpath, tenv);
    double_free(oldpath, tenv);
    _exit(0);
}

int exec_cmd(char **array, env_t **environ)
{
    __pid_t child_pid = fork();
    int status = 0;

    if (child_pid == -1)
        return 1;
    if (child_pid == 0)
        execve_cmd(array, environ);
    waitpid(child_pid, &status, 0);
    if (WIFSIGNALED(status) != 0) {
        my_puterr(strsignal(WTERMSIG(status)));
        if (__WCOREDUMP(status))
            my_puterr(" (core dumped)");
        my_puterr("\n");
        return status + 128;
    }
    return WEXITSTATUS(status);
}
