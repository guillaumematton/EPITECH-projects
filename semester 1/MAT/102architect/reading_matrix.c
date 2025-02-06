/*
** EPITECH PROJECT, 2024
** architect
** File description:
** reading parameters for matrix
*/

#include "include/my.h"

double *read_matrix(char **argv, int argc, double *tab, double *temptab)
{
    int is_matrix_set = 0;

    for (argc -= 1; argc != 2; argc -= 1)
        if (argv[argc][0] == '-' && is_matrix_set == 0 &&
            verify_argument(argv, argc) == 1){
            tab = set_matrix(tab, argv, argc);
            is_matrix_set += 1;
        } else if (argv[argc][0] == '-' && is_matrix_set == 1){
            tab = multiply_matrix(tab, temptab, argv, argc);
        }
    return tab;
}
