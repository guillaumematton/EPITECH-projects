/*
** EPITECH PROJECT, 2024
** architect
** File description:
** miltiplying matrix
*/

#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>

int verify_argument(char **argv, int argc)
{
    if (argv[argc][1] == 't' || argv[argc][1] == 'z' ||
        argv[argc][1] == 'r' || argv[argc][1] == 's')
        if (argv[argc][2] == '\0')
            return 1;
    else
        return 0;
}

void printing_new_values(double *tab, char **argv)
{
    double x;
    double y;

    x = (tab[0] * atof(argv[1])+ tab[1] * atof(argv[2]) + tab[2]);
    y = (tab[3] * atof(argv[1]) + tab[4] * atof(argv[2]) + tab[5]);
    printf("(%.2f, %.2f)\n", x, y);
    return;
}

double *multiply_matrix(double *tab, double *ttab, char **argv, int argc)
{
    double *newtab;
    double oldtab[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    ttab = set_matrix(ttab, argv, argc);
    if (*ttab == *oldtab)
        return tab;
    newtab = malloc(sizeof(double) * 9);
    if (newtab == NULL)
        return NULL;
    newtab[0] = tab[0] * ttab[0] + tab[1] * ttab[3] + tab[2] * ttab[6];
    newtab[1] = tab[0] * ttab[1] + tab[1] * ttab[4] + tab[2] * ttab[7];
    newtab[2] = tab[0] * ttab[2] + tab[1] * ttab[5] + tab[2] * ttab[8];
    newtab[3] = tab[3] * ttab[0] + tab[4] * ttab[3] + tab[5] * ttab[6];
    newtab[4] = tab[3] * ttab[1] + tab[4] * ttab[4] + tab[5] * ttab[7];
    newtab[5] = tab[3] * ttab[2] + tab[4] * ttab[5] + tab[5] * ttab[8];
    newtab[6] = tab[6] * ttab[0] + tab[7] * ttab[3] + tab[8] * ttab[6];
    newtab[7] = tab[6] * ttab[1] + tab[7] * ttab[4] + tab[8] * ttab[7];
    newtab[8] = tab[6] * ttab[2] + tab[7] * ttab[5] + tab[8] * ttab[8];
    tab = newtab;
    return tab;
}
