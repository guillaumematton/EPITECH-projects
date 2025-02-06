/*
** EPITECH PROJECT, 2024
** architect
** File description:
** geometric transformation using matrix
*/

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "include/my.h"

void print_doc(void)
{
    printf("USAGE\n");
    printf("    ./102architect x y transfo1 arg11 [arg12]");
    printf(" [transfo2 arg21 [arg22]] ...\n\n\n");
    printf("DESCRIPTION\n");
    printf("    x    abscissa of the original point\n");
    printf("    y    ordinate of the original point\n");
    printf("    transfo arg1 [arg2]\n");
    printf("    -t i j  translation along vector (i, j)\n");
    printf("    -z m n  scaling by factors m (x-axis) and n (y-axis)\n");
    printf("    -r d    rotation centered in O by a d degree angle\n");
    printf("    -s d    reflection over the axis passing through O");
    printf(" with an inclination angle of d degrees\n");
    return;
}

void print_matrix(double *tab, char **argv)
{
    for (int i = 0; i < 9; i++){
        printf("%.2f", tab[i]);
        if (i == 2 || i == 5 || i == 8)
            putchar('\n');
        if (tab[i] < 0 && i != 2 && i != 5 && i != 8)
            printf("   ");
        if (tab[i] >= 0 && i != 2 && i != 5 && i != 8)
            printf("    ");
    }
    printf("(%.2f, %.2f) => ", atof(argv[1]), atof(argv[2]));
    printing_new_values(tab, argv);
    return;
}

int check_param(char **argv, int i, int argc)
{
    if (argv[i][2] != '\0')
        return i;
    if (argv[i][1] == 't'){
        i = translation(argv, i, argc);
        return i;
    }
    if (argv[i][1] == 'z'){
        i = scaling(argv, i, argc);
        return i;
    }
    if (argv[i][1] == 'r'){
        i = rotation(argv, i, argc);
        return i;
    }
    if (argv[i][1] == 's'){
        i = reflection(argv, i, argc);
        return i;
    }
}

int reading_params(char **argv, int argc, double *tab, double *temptab)
{
    int is_matrix_set = 0;

    for (int i = 3; i < argc; i++){
        if (argv[i][0] == '-')
            i = check_param(argv, i, argc);
        else
            return 84;
        if (i == -1)
            return 84;
    }
    tab = read_matrix(argv, argc, tab, temptab);
    if (tab == NULL)
        return 84;
    print_matrix(tab, argv);
    return 0;
}

int main(int argc, char **argv)
{
    double *tab;
    double *temptab;
    int err = 0;

    if (argc == 2){
        if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0'){
            print_doc();
            return 0;
        }
    } else if (argc <= 3)
        return 84;
    tab = malloc(sizeof(double) * 9);
    temptab = malloc(sizeof(double) * 9);
    if (tab == NULL || temptab == NULL)
        return 84;
    err = reading_params(argv, argc, tab, temptab);
    free(tab);
    free(temptab);
    return err;
}
