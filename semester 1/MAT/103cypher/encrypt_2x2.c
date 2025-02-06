/*
** EPITECH PROJECT, 2024
** cypher
** File description:
** encrypt_2x2
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

void print_encrypted(int *encrypted, int *message, int i, int size)
{
    encrypted[i] = 0;
    printf("Encrypted message:\n");
    printf("%d", encrypted[0]);
    for (i = 1; encrypted[i] != 0 || i % size != 0; i++)
        printf(" %d", encrypted[i]);
    putchar('\n');
    return;
}

int encrypt_2x2(char **argv, double *key)
{
    int *message = malloc(sizeof(int) * (strlen(argv[1]) + 3));
    int *encrypted = malloc(sizeof(int) * (strlen(argv[1]) + 3));
    int i = 0;

    if (message == NULL || encrypted == NULL)
        return 84;
    message = get_message_2x2(argv, message);
    for (i = 0; message[i] != 0; i++){
        encrypted[i] = message[i] * key[0] + message[i + 1] * key[2];
        i++;
        encrypted[i] = message[i - 1] * key[1] + message[i] * key[3];
    }
    print_encription_matrix(key, 2);
    print_encrypted(encrypted, message, i, 2);
    free(message);
    free(encrypted);
    return 0;
}

void print_decrypted(int *decrypted, int i, double *key)
{
    decrypted[i] = '\0';
    printf("Decrypted message:\n");
    for (i = 0; decrypted[i] != 0; i++)
        printf("%c", decrypted[i]);
    putchar('\n');
    return;
}

int decrypt_message_2x2(char **argv, double *key)
{
    int *message = malloc(sizeof(int) * (strlen(argv[1]) + 2));
    int *decrypted = malloc(sizeof(int) * (strlen(argv[1]) + 2));
    int i = 0;

    if (message == NULL || decrypted == NULL)
        return 84;
    for (; argv[1][i] != '\0'; i++)
        message[i] = argv[1][i];
    for (; i % 2 != 0; i++)
        message[i] = 0;
    message[i] = 0;
    decrypted = get_decrypted_message(message, decrypted, key);
    print_decrypted(decrypted, i, key);
    print_decription_matrix(key, 2);
    free(message);
    free(decrypted);
    return 0;
}

int decrypt_2x2(char **argv, double *key)
{
    double det = key[0] * key[3] - key[1] * key[2];
    double *revkey = malloc(sizeof(double) * 5);

    if (det == 0 || revkey == NULL)
        return 84;
    revkey[0] = key[3] / det;
    revkey[1] = (- key[1]) / det;
    revkey[2] = (- key[2]) / det;
    revkey[3] = key[0] / det;
    if (decrypt_message_2x2(argv, revkey) == 84)
        return 84;
    return 0;
}
