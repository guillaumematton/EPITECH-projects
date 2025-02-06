/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** header_second_line
*/

#include <stdio.h>
#include <errno.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <math.h>
#include "include/my.h"

int get_nbr_total_proc(void)
{
    DIR *directory = opendir("/proc");
    struct dirent *info;
    int total = 0;

    if (directory == NULL)
        return -5;
    info = readdir(directory);
    if (info == NULL)
        return -5;
    for (; info != NULL; info = readdir(directory))
        if ('0' <= info->d_name[0] && info->d_name[0] <= '9')
            total += 1;
    closedir(directory);
    return total;
}

char my_read_type(char *name)
{
    char *path = malloc(sizeof(char) * (strlen(name) + 15));
    FILE *filename;
    char *proc = "/proc/";
    char *info = malloc(sizeof(char) * 41);

    if (path == NULL || info == NULL)
        return -5;
    path = get_path(path, name, proc);
    filename = fopen(path, "r");
    if (filename == NULL){
        free(info);
        free(path);
        return -5;
    }
    for (int i = 0; i <= 2; i++)
        fgets(info, 40, filename);
    fclose(filename);
    free(info);
    free(path);
    return info[7];
}

int increment_types(int total, DIR *directory, struct dirent *info)
{
    char test;
    int stop = 0;
    int zombie = 0;
    int run = 0;

    for (; info != NULL && test != -5; info = readdir(directory)){
        if ('0' <= info->d_name[0] && info->d_name[0] <= '9')
            test = my_read_type(info->d_name);
        if (test == 't' || test == 'T')
            stop++;
        if (test == 'Z')
            zombie++;
        if (test == 'R')
            run++;
    }
    print_second_line(total, run, stop, zombie);
    return 0;
}

int get_type_procs(int total)
{
    DIR *directory = opendir("/proc");
    struct dirent *info;
    int test = 0;

    if (directory == NULL)
        return -5;
    info = readdir(directory);
    if (info == NULL)
        test = -5;
    if (increment_types(total, directory, info) == -5 && test == 0)
        test = -5;
    closedir(directory);
    return test;
}

int get_nbr_proc(void)
{
    int total = get_nbr_total_proc();

    if (total == -5)
        return -5;
    if (get_type_procs(total) == -5)
        return -5;
    return 0;
}
