/*
** EPITECH PROJECT, 2024
** architect
** File description:
** print the phrases at the start
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/my.h"

int verify_number(char **argv, int i)
{
    int j = 0;

    if (argv[i + 1][j] == '-')
        j++;
    for (; '0' <= argv[i + 1][j] && argv[i + 1][j] <= '9'; j++)
        if (argv[i + 1][j + 1] == '.')
            j++;
    if (argv[i + 1][0] == '-' && j == 1)
        return -1;
    if (j != strlen(argv[i + 1]))
        return -1;
    return 0;
}

int translation(char **argv, int i, int argc)
{
    int j = 0;

    if (argc <= i + 2)
        return -1;
    if (verify_number(argv, i) == -1 || verify_number(argv, i + 1) == -1)
        return -1;
    printf("Translation along vector (%d, %d)\n",
        atoi(argv[i + 1]), atoi(argv[i + 2]));
    i += 2;
    return i;
}

int scaling(char **argv, int i, int argc)
{
    int j = 0;

    if (argc <= i + 2)
        return -1;
    if (verify_number(argv, i) == -1 || verify_number(argv, i + 1) == -1)
        return -1;
    printf("Scaling by factors %d and %d\n",
        atoi(argv[i + 1]), atoi(argv[i + 2]));
    i += 2;
    return i;
}

int rotation(char **argv, int i, int argc)
{
    int j = 0;

    if (argc <= i + 1)
        return -1;
    if (verify_number(argv, i) == -1)
        return -1;
    printf("Rotation by a %d degree angle\n",
        atoi(argv[i + 1]));
    i += 1;
    return i;
}

int reflection(char **argv, int i, int argc)
{
    int j = 0;

    if (argc <= i + 1)
        return -1;
    if (verify_number(argv, i) == -1)
        return -1;
    printf("Reflection over an axis with an inclination angle of %d degrees\n",
        atoi(argv[i + 1]));
    i += 1;
    return i;
}
