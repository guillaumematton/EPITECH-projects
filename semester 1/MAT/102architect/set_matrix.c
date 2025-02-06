/*
** EPITECH PROJECT, 2024
** architect
** File description:
** initialize a matrix
*/

#include <stdlib.h>
#include <math.h>
#include "include/my.h"

double *set_translation(char **argv, int argc, double *tab)
{
    tab[0] = 1;
    tab[1] = 0;
    tab[2] = atof(argv[argc + 1]);
    tab[3] = 0;
    tab[4] = 1;
    tab[5] = atof(argv[argc + 2]);
    tab[6] = 0;
    tab[7] = 0;
    tab[8] = 1;
    return tab;
}

double *set_scaling(char **argv, int argc, double *tab)
{
    tab[0] = atof(argv[argc + 1]);
    tab[1] = 0;
    tab[2] = 0;
    tab[3] = 0;
    tab[4] = atof(argv[argc + 2]);
    tab[5] = 0;
    tab[6] = 0;
    tab[7] = 0;
    tab[8] = 1;
    return tab;
}

double *set_rotation(char **argv, int argc, double *tab)
{
    tab[0] = cos((atof(argv[argc + 1]) / 360) * 2 * M_PI);
    tab[1] = -sin((atof(argv[argc + 1]) / 360) * 2 * M_PI);
    tab[2] = 0;
    tab[3] = sin((atof(argv[argc + 1]) / 360) * 2 * M_PI);
    tab[4] = cos((atof(argv[argc + 1]) / 360) * 2 * M_PI);
    tab[5] = 0;
    tab[6] = 0;
    tab[7] = 0;
    tab[8] = 1;
    return tab;
}

double *set_reflection(char **argv, int argc, double *tab)
{
    tab[0] = cos((atof(argv[argc + 1]) / 360) * 4 * M_PI);
    tab[1] = sin((atof(argv[argc + 1]) / 360) * 4 * M_PI);
    tab[2] = 0;
    tab[3] = sin((atof(argv[argc + 1]) / 360) * 4 * M_PI);
    tab[4] = -cos((atof(argv[argc + 1]) / 360) * 4 * M_PI);
    tab[5] = 0;
    tab[6] = 0;
    tab[7] = 0;
    tab[8] = 1;
    return tab;
}

double *set_matrix(double *tab, char **argv, int argc)
{
    if (argv[argc][2] != '\0')
        return tab;
    if (argv[argc][1] == 't')
        tab = set_translation(argv, argc, tab);
    if (argv[argc][1] == 'z')
        tab = set_scaling(argv, argc, tab);
    if (argv[argc][1] == 'r')
        tab = set_rotation(argv, argc, tab);
    if (argv[argc][1] == 's')
        tab = set_reflection(argv, argc, tab);
    return tab;
}
