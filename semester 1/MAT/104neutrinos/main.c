/*
** EPITECH PROJECT, 2024
** neutrinos
** File description:
** main
*/

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "include/my.h"
#include "include/struct.h"

int find_num_error(char *buffer)
{
    int i = 0;
    int j = 0;

    for (; '0' <= buffer[i] && buffer[i] <= '9'; i++);
    if (buffer[i] == '.' && i != 0 || buffer[i] == ',' && i != 0)
        i++;
    for (; '0' <= buffer[i] && buffer[i] <= '9'; i++);
    for (; buffer[j] == '0'; j++);
    if (buffer[i] != '\n' || buffer[j] == '\n')
        return 84;
    buffer[i] = '\0';
    return 0;
}

int start_loop(mean_t *mean)
{
    char *buffer = malloc(sizeof(char) * 12);
    int newvalue = 0;
    int len = 0;

    if (buffer == NULL)
        return 84;
    write(1, "Enter next value: ", 19);
    read(0, buffer, 11);
    for (; strcmp(buffer, "END\n") != 0; len = read(0, buffer, 11)){
        if (in_loop(buffer, mean) == 84)
            return 84;
        print_means(mean);
        for (int i = 0; buffer[i] != '\0' && i < 12; i++)
            buffer[i] = '\0';
    }
    free(buffer);
    return 0;
}

int find_argv_error(char **argv, int j)
{
    int i = 0;
    int k = 0;

    for (; '0' <= argv[j][i] && argv[j][i] <= '9'
        && argv[j][i] != '\0'; i++);
    if (argv[j][i] == '.' && j != 1)
        i++;
    for (; '0' <= argv[j][i] && argv[j][i] <= '9'
        && argv[j][i] != '\0'; i++);
    for (; argv[j][k] == '0'; k++);
    if (argv[j][i] != '\0' || argv[j][k] == '\0')
        return 84;
    return 0;
}

void set_struct(mean_t *mean, char **argv)
{
    mean->nb_of_nbr = atoi(argv[1]);
    mean->arithmetical_mean = atof(argv[2]);
    mean->harmonic_mean = atof(argv[3]);
    mean->std_deviation = atof(argv[4]);
    return;
}

int main(int argc, char **argv)
{
    mean_t mean;
    int err = 0;

    if (argc == 1)
        return 84;
    if (strcmp(argv[1], "-h") == 0){
        if (argc != 2)
            return 84;
        print_help();
        return 0;
    }
    if (argc != 5)
        return 84;
    for (int j = 1; j < 5; j++)
        if (find_argv_error(argv, j) == 84)
            return 84;
    set_struct(&mean, argv);
    err = start_loop(&mean);
    return err;
}
