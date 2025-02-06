/*
** EPITECH PROJECT, 2024
** 103cypher
** File description:
** main
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

int get_matrix_3x3(char **argv)
{
    double *key = malloc(sizeof(double) * 9);
    int i = 0;

    if (key == NULL)
        return 84;
    for (; i < 9 && argv[2][i] != '\0'; i++)
        key[i] = argv[2][i];
    for (; i < 9; i++)
        key[i] = 0;
    if (strcmp(argv[3], "0") == 0) {
        if (encrypt_3x3(argv, key) == 84)
            return 84;
    } else
        if (decrypt_3x3(argv, key) == 84)
            return 84;
    free(key);
    return 0;
}

int decrypt(char **argv, double *key)
{
    return 0;
}

int get_matrix_2x2(char **argv)
{
    double *key = malloc(sizeof(double) * 5);
    int i = 0;

    if (key == NULL)
        return 84;
    for (; i < 4 && argv[2][i] != '\0'; i++)
        key[i] = argv[2][i];
    for (; i < 4; i++)
        key[i] = 0;
    if (strcmp(argv[3], "0") == 0) {
        if (encrypt_2x2(argv, key) == 84)
            return 84;
    } else
        if (decrypt_2x2(argv, key) == 84)
            return 84;
    free(key);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 4 && argc != 2)
        return 84;
    if (strcmp(argv[3], "0") != 0 && strcmp(argv[3], "1") != 0)
        return 84;
    if (strcmp(argv[1], "-h") == 0 && argc == 2){
        print_help();
        return 0;
    } else if (argc != 4)
        return 84;
    if (strlen(argv[2]) > 9)
        return 84;
    if (strlen(argv[2]) <= 4) {
        if (get_matrix_2x2(argv) == 84)
            return 84;
    } else
        if (get_matrix_3x3(argv) == 84)
            return 84;
    return 0;
}
