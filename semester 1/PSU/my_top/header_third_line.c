/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** header_third_line
*/

#include <stdio.h>
#include <errno.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <math.h>

int print_cpu_info(double *info)
{
    int total = 0;
    double *perc = malloc(sizeof(double) * 10);

    if (perc == NULL)
        return 84;
    for (int i = 0; i < 10; i++)
        total += info[i];
    for (int i = 0; i < 10; i++)
        perc[i] = (info[i] / total) * 100;
    mvprintw(2, 0,
        "%%CPU(s): %.1f us, %.1f sy, %.1f ni, %.1f id,",
        perc[0], perc[2], perc[1], perc[3]);
    printw(" %.1f wa, %.1f hi, %.1f si, %.1f st",
        perc[4], perc[5], perc[6], perc[7]);
    free(perc);
    return 0;
}

double *get_info(double *info, char *str, int i)
{
    for (int j = 0; j < 10; j++){
        info[j] = 0;
        for (; '0' <= str[i] && str[i] <= '9'; i++){
            info[j] *= 10;
            info[j] += str[i] - 48;
        }
        i++;
    }
    return info;
}

int get_cpu_info(void)
{
    FILE *stream = fopen("/proc/stat", "r");
    double *info;
    int i = 0;
    char *str;

    str = malloc(sizeof(char) * 100);
    info = malloc(sizeof(double) * 10);
    if (stream == NULL || str == NULL)
        return 84;
    fgets(str, 100, stream);
    fclose(stream);
    for (; '0' > str[i] || str[i] > '9'; i++);
    info = get_info(info, str, i);
    print_cpu_info(info);
    free(info);
    free(str);
    return 0;
}
