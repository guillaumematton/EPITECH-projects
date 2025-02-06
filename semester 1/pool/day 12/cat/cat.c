/*
** EPITECH PROJECT, 2024
** cat
** File description:
** replace cat
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include "../include/my.h"

void error(void)
{
    if (errno == 2)
        my_putstr("no such file or directory");
    if (errno == 13)
        my_putstr("Permission denied");
    return;
}

void cat(int ac, char **av)
{
    int readfile = 0;
    char buffer[30000];
    int var = 0;

    if (ac == 1){
        while (read(0, buffer, 29999) != 0)
            my_putstr(buffer);
    }
    for (int i = 1; i < ac; i++){
        readfile = open(av[i], O_RDONLY);
        error();
        var = read(readfile, buffer, 29999);
        buffer[var] = '\0';
        my_putstr(buffer);
        my_putchar('\n');
        close(readfile);
    }
    return;
}

int main(int argc, char **argv)
{
    cat(argc, argv);
    return 0;
}
