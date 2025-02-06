/*
** EPITECH PROJECT, 2024
** cipher
** File description:
** print_matrix
*/

#include <stdio.h>
#include <stdlib.h>

void print_spaces_encrypted(double *key, int i)
{
    int nbrlen = 0;

    if (key[i] < 0)
        nbrlen++;
    if (key[i] < 10)
        nbrlen++;
    else if (key[i] < 100)
        nbrlen += 2;
    else
        nbrlen += 3;
    for (; nbrlen < 8; nbrlen++)
        putchar(' ');
    return;
}

void print_encription_matrix(double *key, int size)
{
    printf("Key matrix:\n");
    for (int i = 0; i < size * size; i++){
        if (i != 0 && i != size && i != size * 2)
            print_spaces_encrypted(key, i - 1);
        printf("%d", (int)key[i]);
        if (i == size - 1 || i == size * 2 - 1 || i == size * size - 1)
            putchar('\n');
    }
    putchar('\n');
    return;
}

void print_spaces_decrypted(double *key, int i)
{
    int nbrlen = 2;

    if (key[i] < 0)
        nbrlen++;
    if (key[i] < 0.01 && key[i] > -0.01)
        nbrlen += 2;
    else if (key[i] < 0.1 && key[i] > -0.1)
        nbrlen += 1;
    for (; nbrlen < 8; nbrlen++)
        putchar(' ');
    return;
}

void print_decription_matrix(double *key, int size)
{
    printf("Key matrix:\n");
    for (int i = 0; i < size * size; i++){
        if (i != 0 && i != size && i != size * 2)
            print_spaces_decrypted(key, i - 1);
        if (key[i] < 0.001 && key[i] > -0.001)
            printf("0.0");
        else
            printf("%.3f", key[i]);
        if (i == size - 1 || i == size * 2 - 1 || i == size * size - 1)
            putchar('\n');
    }
    putchar('\n');
    return;
}

int *get_message(char **argv, int *message)
{
    int i = 0;
    int j = 0;

    for (; argv[1][i] != '\0'; j++){
        message[j] = 0;
        for (; argv[1][i] != ' ' && argv[1][i] != '\0'; i++){
            message[j] *= 10;
            message[j] += argv[1][i] - 48;
        }
        if (argv[1][i] == ' ')
            i++;
    }
    message[j] = 0;
    return message;
}
