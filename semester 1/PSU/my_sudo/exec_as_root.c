/*
** EPITECH PROJECT, 2025
** sudo
** File description:
** exec_as_root
*/

#include "include/my.h"

void apply_shell(char *shell, char *line, FILE *file)
{
    char *args[2] = {shell, NULL};

    double_free(line, file);
    execvp("bash", args);
}

int execute_as_root(char **argv, int i)
{
    int j = i;
    int k = i;
    char **arguments = NULL;

    for (; argv[j] != NULL; j++);
    arguments = malloc(sizeof(char *) * (j - i + 1));
    if (arguments == NULL)
        return 84;
    for (j = 0; argv[k] != NULL; j++){
        arguments[j] = argv[k];
        k++;
    }
    arguments[j] = NULL;
    execvp(argv[i], arguments);
    free(arguments);
    return 0;
}
