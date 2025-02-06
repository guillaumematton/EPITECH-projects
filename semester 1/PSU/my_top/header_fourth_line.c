/*
** EPITECH PROJECT, 2024
** my top
** File description:
** header_fourth_line
*/

#include <stdio.h>
#include <errno.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

void print_mem_info(double *info, char *str)
{
    info[2] = info[0] - info[2];
    mvprintw(3, 0,
        "MiB Mem : %.1f total, %.1f free, %.1f used, %.1f buff/cache",
        info[0], info[1], info[2], info[4] + info[5] + info[6]);
    return;
}

double *get_mem_info(double *info, char *str, int i, int j)
{
    info[j] = 0;
    for (; str[i] != ' '; i++){
        info[j] *= 10;
        info[j] += str[i] - 48;
    }
    info[j] /= 1024;
    return info;
}

double *get_last_info(double *info, char *str, FILE *stream)
{
    int i = 0;

    for (int j = 0; j < 21; j++)
        fgets(str, 100, stream);
    for (; '0' > str[i] || str[i] > '9'; i++);
    info = get_mem_info(info, str, i, 6);
    return info;
}

int read_mem(void)
{
    FILE *stream = fopen("/proc/meminfo", "r");
    double *info;
    int i = 0;
    char *str;

    str = malloc(sizeof(char) * 100);
    info = malloc(sizeof(double) * 7);
    if (stream == NULL || str == NULL)
        return 84;
    for (int j = 0; j < 6; j++){
        fgets(str, 100, stream);
        for (; '0' > str[i] || str[i] > '9'; i++);
        info = get_mem_info(info, str, i, j);
    }
    info = get_last_info(info, str, stream);
    fclose(stream);
    print_mem_info(info, str);
    free(info);
    free(str);
    return 0;
}
