/*
** EPITECH PROJECT, 2025
** sudo
** File description:
** group_case
*/

#include "include/my.h"

int group_exec(char **argv, int egid)
{
    if (setegid(egid) == -1)
        return 84;
    if (execute_as_root(argv, 3) == 84)
        return 84;
    if (seteuid(getgid()) == -1)
        return 84;
    return 0;
}

int check_for_gexec(char **argv, char *line, int i)
{
    int err = 0;
    __gid_t egid = 0;

    if (strcmp(argv[3], "-s") == 0)
        err = shell_case(argv[2]);
    else {
        for (i += 3; line[i] != ':'; i++){
            egid *= 10;
            egid += line[i] - 48;
        }
        err = group_exec(argv, egid);
    }
    return err;
}

int check_group(char *group, char *line, char **argv)
{
    int i = 0;
    int err = 0;

    for (; group[i] == line[i] && line[i] != '\0'; i++);
    if (line[i] == ':' && group[i] == '\0')
        err = check_for_gexec(argv, line, i);
    if (err == 84)
        return 0;
    return 5;
}

int group_case(char **argv)
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
        temp_len = check_group(argv[2], line, argv);
    }
    double_free(line, file);
    if (temp_len == -1)
        return 0;
    return 84;
}
