/*
** EPITECH PROJECT, 2025
** sudo
** File description:
** shell_case
*/

#include "include/my.h"

int comp_str(char *line, char *shell)
{
    for (int i = 1; line[i - 1] != '\0'; i++)
        if (line[i] == '\n')
            line[i] = '\0';
    if (strcmp(line, shell) == 0)
        return -1;
    return 5;
}

int verify_existance(char *shell)
{
    FILE *file = fopen("/etc/shells", "r");
    __ssize_t temp_len = 1;
    size_t len = 0;
    char *line = NULL;

    if (file == NULL)
        return -1;
    while (temp_len != 0 && temp_len != -1) {
        temp_len = getline(&line, &len, file);
        if (temp_len == -1){
            double_free(line, file);
            return -1;
        }
        temp_len = comp_str(line, shell);
    }
    if (temp_len == 0)
        return -1;
    apply_shell(shell, line, file);
    return 0;
}

char *get_shell(const char *line, char *shell, int i, int j)
{
    for (i = 0; line[j] != '\0'; i++){
        shell[i] = line[j];
        j++;
    }
    shell[i - 1] = '\0';
    return shell;
}

int check_shell(const char *login, const char *line)
{
    int j = 0;
    int i = 0;
    char *shell = NULL;
    int err = 0;

    for (; line[i] == login[i] && login[i] != '\0'; i++);
    if (login[i] != '\0' || line[i] != ':')
        return 1;
    for (i = 0; line[i] != '\0'; i++)
        if (line[i] == ':')
            j = i;
    shell = malloc(sizeof(char) * (i - j));
    if (shell == NULL)
        return -1;
    shell = get_shell(line, shell, i, j + 1);
    err = verify_existance(shell);
    free(shell);
    return err;
}

int shell_case(const char *login)
{
    FILE *file = fopen("/etc/passwd", "r");
    __ssize_t temp_len = 1;
    size_t len = 0;
    char *line = NULL;

    if (file == NULL)
        return 84;
    while (temp_len != 0 && temp_len != -1) {
        temp_len = getline(&line, &len, file);
        if (temp_len == -1){
            double_free(line, file);
            return 84;
        }
        temp_len = check_shell(login, line);
    }
    double_free(line, file);
    if (temp_len == -1)
        return 84;
    return 0;
}
