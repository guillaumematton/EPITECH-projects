/*
** EPITECH PROJECT, 2024
** setting up
** File description:
** self_made_map
*/

#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

static int end_of_patern_check(char *argv, int i)
{
    if (argv[i] == '\0')
        return 0;
    return i;
}

static char *create_map(char *buffer, int nbr, char *argv)
{
    int k = 0;
    int line_size;
    int i = 0;

    for (; k < (nbr * nbr + 1); k++){
        for (line_size = 0; line_size < nbr; line_size++){
            buffer[k] = argv[i];
            k++;
            i++;
            i = end_of_patern_check(argv, i);
        }
        buffer[k] = '\n';
    }
    buffer[k] = '\0';
    return buffer;
}

int self_made_map(int nbr, char *argv)
{
    char *buffer;

    buffer = malloc(sizeof(char) * (nbr * (nbr + 1) + 1));
    if (buffer == NULL)
        return 84;
    for (int j = 0; argv[j] != '\0'; j++)
        if (argv[j] != '.' && argv[j] != 'o')
            return 84;
    buffer = create_map(buffer, nbr, argv);
    compare_square(buffer, nbr + 1);
    free(buffer);
    return 0;
}
