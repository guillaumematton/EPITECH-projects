/*
** EPITECH PROJECT, 2025
** sudo
** File description:
** main
*/

#include "include/my.h"

int find_use(char **argv)
{
    if (argv[1][0] != '-'){
        setuid(0);
        if (execute_as_root(argv, 1) == 84)
            return 84;
        setuid(1000);
    }
    if (strcmp(argv[1], "-u") == 0)
        if (user_case(argv) == 84)
            return 84;
    if (strcmp(argv[1], "-g") == 0)
        if (group_case(argv) == 84)
            return 84;
    if (strcmp(argv[1], "-s") == 0)
        if (shell_case(getlogin()) == 84)
            return 84;
    return 0;
}

int main(int argc, char **argv)
{
    char *login = getlogin();

    if (login == NULL)
        return 84;
    if (argc == 1 || (argc == 2 && strcmp(argv[1], "-h") == 0)){
        print_help();
        if (argc == 1)
            return 84;
        return 0;
    }
    if (passwd_input(login) == 84)
        return 84;
    if (find_use(argv) == 84)
        return 84;
    return 0;
}
