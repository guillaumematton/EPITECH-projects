/*
** EPITECH PROJECT, 2024
** neutrinos
** File description:
** mean
*/

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include "include/struct.h"
#include "include/my.h"
#include <stdlib.h>

void find_hamonic_mean(mean_t *mean, int newvalue)
{
    double temp_harm_mean = 0;

    temp_harm_mean = (mean->nb_of_nbr - 1) / mean->harmonic_mean;
    temp_harm_mean += pow(newvalue, -1);
    mean->harmonic_mean = ((mean->nb_of_nbr) / temp_harm_mean);
    return;
}

void find_std_deviation(mean_t *mean, int newvalue, double arithm_mean)
{
    double temp_std_deviation = 0;

    temp_std_deviation = mean->std_deviation * mean->std_deviation;
    temp_std_deviation += (arithm_mean * arithm_mean);
    temp_std_deviation *= (mean->nb_of_nbr - 1);
    temp_std_deviation += pow(newvalue, 2);
    temp_std_deviation /= (mean->nb_of_nbr);
    mean->root_mean_square = sqrt(temp_std_deviation);
    temp_std_deviation -= pow(mean->arithmetical_mean, 2);
    mean->std_deviation = sqrt(temp_std_deviation);
    find_hamonic_mean(mean, newvalue);
}

void find_arithmetical_mean(mean_t *mean, int newvalue)
{
    double temp_arith_mean = 0;
    double old_arithm_mean = 0;

    mean->nb_of_nbr += 1;
    temp_arith_mean = mean->arithmetical_mean * (mean->nb_of_nbr - 1);
    old_arithm_mean = mean->arithmetical_mean;
    temp_arith_mean += newvalue;
    temp_arith_mean /= mean->nb_of_nbr;
    mean->arithmetical_mean = temp_arith_mean;
    find_std_deviation(mean, newvalue, old_arithm_mean);
    return;
}

void print_means(mean_t *mean)
{
    printf("    Number of values:   %d\n", mean->nb_of_nbr);
    printf("    Standard deviation: %.2f\n", mean->std_deviation);
    printf("    Arithmetic mean:    %.2f\n", mean->arithmetical_mean);
    printf("    Root mean square:   %.2f\n", mean->root_mean_square);
    printf("    Harmonic mean:      %.2f\n\n", mean->harmonic_mean);
    write(1, "Enter next value: ", 19);
    return;
}

int in_loop(char *buffer, mean_t *mean)
{
    int newvalue = 0;

    if (find_num_error(buffer) == 84){
            free(buffer);
            return 84;
        }
    newvalue = atof(buffer);
    find_arithmetical_mean(mean, newvalue);
    return 0;
}
