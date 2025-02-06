/*
** EPITECH PROJECT, 2025
** sudo
** File description:
** user_case
*/

#include "include/my.h"

int user_exec(char **argv, int euid)
{
    if (seteuid(euid) == -1)
        return 84;
    if (execute_as_root(argv, 3) == 84)
        return 84;
    if (seteuid(getuid()) == -1)
        return 84;
    return 0;
}

int check_for_exec(char **argv, char *line, int i)
{
    int err = 0;
    __uid_t euid = 0;

    if (strcmp(argv[3], "-s") == 0)
        err = shell_case(argv[2]);
    if (strcmp(argv[3], "-s") != 0) {
        for (i += 3; line[i] != ':'; i++){
            euid *= 10;
            euid += line[i] - 48;
        }
        err = user_exec(argv, euid);
    }
    return err;
}

int check_user(char *login, char *line, char **argv)
{
    int i = 0;
    int err = 0;

    while (login[i] == line[i] && line[i] != '\0')
        i++;
    if (line[i] == ':' && login[i] == '\0')
        err = check_for_exec(argv, line, i);
    if (err == 84)
        return 0;
    return 5;
}

int user_case(char **argv)
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
        temp_len = check_user(argv[2], line, argv);
    }
    double_free(line, file);
    if (temp_len == -1)
        return 0;
    return 84;
}
