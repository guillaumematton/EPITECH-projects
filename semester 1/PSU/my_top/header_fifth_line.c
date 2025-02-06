/*
** EPITECH PROJECT, 2024
** my top
** File description:
** header_fifth_line
*/

#include <stdio.h>
#include <errno.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include "include/my.h"

int print_swap(double *info, char *str)
{
    int i = 0;
    double test;
    FILE *stream = fopen("/proc/meminfo", "r");

    if (stream == NULL)
        return 84;
    for (int j = 0; j < 3; j++)
        fgets(str, 100, stream);
    fclose(stream);
    for (; '0' > str[i] || str[i] > '9'; i++);
    for (; str[i] != ' '; i++){
        test *= 10;
        test += str[i] - 48;
    }
    test /= 1024;
    mvprintw(4, 0,
        "MiB Swap : %.1f total, %.1f free, %.1f used, %.1f avail Mem",
        info[0], info[1], info[1] - info[0], test);
    return 0;
}

double *read_meminfo(char *str, FILE *stream, double *info)
{
    int i = 0;

    for (int j = 0; j < 14; j++)
        fgets(str, 100, stream);
    for (int j = 0; j < 2; j++){
        fgets(str, 100, stream);
        for (; '0' > str[i] || str[i] > '9'; i++);
        info = get_mem_info(info, str, i, j);
    }
    return info;
}

int read_swap(void)
{
    FILE *stream = fopen("/proc/meminfo", "r");
    double *info;
    char *str;

    str = malloc(sizeof(char) * 100);
    info = malloc(sizeof(double) * 3);
    if (stream == NULL || str == NULL)
        return 84;
    info = read_meminfo(str, stream, info);
    if (print_swap(info, str) == 84)
        return 84;
    fclose(stream);
    free(info);
    free(str);
    return 0;
}
