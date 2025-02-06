/*
** EPITECH PROJECT, 2025
** 105demography
** File description:
** math
*/

#include "include/my.h"

int *set_years(void)
{
    int *years = malloc(sizeof(int) * 59);
    int i = 1960;
    int j = 0;

    if (years == NULL)
        return NULL;
    for (; i < 2018; i++){
        years[j] = i;
        j++;
    }
    years[j] = 0;
    return years;
}

int find_a_and_b(long EX, long EY, long EXY, long EX2)
{
    double a = 0;
    double b = 0;
    int N = 0;
    int *years = set_years();

    for (; years[N] != 0; N++);
    free(years);
    a = (N * EXY - EX * EY) / (N * EX2 - pow(EX, 2));
    b = (EY * EX2 - EX * EXY) / (N * EX2 - pow(EX, 2));
    printf("a : %f  b : %f\n", a / 1000000, b / 1000000);
    return 0;
}

int manipulate_values(int *nbr_array)
{
    long EX = 0;
    long EY = 0;
    long EXY = 0;
    long EX2 = 0;
    int *years = set_years();

    if (years == NULL)
        return 84;
    for (int i = 0; years[i] != 0; i++)
        EY += nbr_array[i];
    for (int i = 0; years[i] != 0; i++)
        EX += years[i];
    for (int i = 0; years[i] != 0; i++)
        EXY += (nbr_array[i] * years[i]);
    for (int i = 0; years[i] != 0; i++)
        EX2 = pow(years[i], 2);
    find_a_and_b(EX, EY, EXY, EX2);
    free(years);
    return 0;
}

int *get_nbrs(char *line, int i)
{
    int nbrs = 0;
    int *nbr_array = NULL;

    for (int j = i; line[j - 1] != '\n'; j++)
        if (line[j] == ';' || line[j] == '\n')
            nbrs++;
    nbr_array = malloc(sizeof(int) * nbrs);
    if (nbr_array == NULL)
        return NULL;
    for (int j = 0; j < nbrs; j++)
        nbr_array[j] = 0;
    for (int k = 0; line[i] != '\n'; i++){
        if (line[i] == ';')
            k++;
        else {
            nbr_array[k] *= 10;
            nbr_array[k] += line[i] - 48;
        }
    }
    return nbr_array;
}
