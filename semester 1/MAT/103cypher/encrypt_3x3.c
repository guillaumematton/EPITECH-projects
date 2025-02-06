/*
** EPITECH PROJECT, 2024
** cypher
** File description:
** encrypt_3x3
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

int encrypt(int *encrypted, int *message, double *key)
{
    int i = 0;

    for (i = 0; message[i] != 0; i++){
        encrypted[i] = message[i] * key[0] + message[i + 1] * key[3]
            + message[i + 2] * key[6] + 0.1;
        i++;
        encrypted[i] = message[i - 1] * key[1] + message[i] * key[4]
            + message[i + 1] * key[7] + 0.1;
        i++;
        encrypted[i] = message[i - 2] * key[2] + message[i - 1] * key[5]
            + message[i] * key[8] + 0.1;
    }
    return i;
}

int encrypt_3x3(char **argv, double *key)
{
    int *message = malloc(sizeof(int) * (strlen(argv[1]) + 4));
    int *encrypted = malloc(sizeof(int) * (strlen(argv[1]) + 4));
    int i = 0;

    if (message == NULL || encrypted == NULL)
        return 84;
    for (; argv[1][i] != '\0'; i++)
        message[i] = argv[1][i];
    for (; (i + 1) % 3 != 0; i++)
        message[i] = 0;
    message[i] = 0;
    i = encrypt(encrypted, message, key);
    print_encription_matrix(key, 3);
    print_encrypted(encrypted, message, i, 3);
    free(message);
    free(encrypted);
    return 0;
}

int decrypt_message_3x3(char **argv, double *key)
{
    int j = 0;
    int *decrypted = malloc(sizeof(int) * (strlen(argv[1]) + 4));
    int *message = malloc(sizeof(int) * (strlen(argv[1]) + 4));

    if (decrypted == NULL || message == NULL)
        return 84;
    message = get_message(argv, message);
    j = encrypt((int *)decrypted, message, key);
    print_decription_matrix(key, 3);
    print_decrypted(decrypted, j, key);
    free(decrypted);
    free(message);
    return 0;
}

int decrypt_key_3x3(char **argv, double *key, double *revkey, int *cofactors)
{
    double det = 0;

    for (int i = 0; i < 9; i++)
        det += ((double)cofactors[i] * key[i]);
    if (det == 0)
        return 84;
    revkey[0] = cofactors[0] / det * 3;
    revkey[1] = cofactors[3] / det * 3;
    revkey[2] = cofactors[6] / det * 3;
    revkey[3] = cofactors[1] / det * 3;
    revkey[4] = cofactors[4] / det * 3;
    revkey[5] = cofactors[7] / det * 3;
    revkey[6] = cofactors[2] / det * 3;
    revkey[7] = cofactors[5] / det * 3;
    revkey[8] = cofactors[8] / det * 3;
    if (decrypt_message_3x3(argv, revkey) == 84)
        return 84;
    return 0;
}

int decrypt_3x3(char **argv, double *key)
{
    int *cofactors = malloc(sizeof(double) * 9);
    double *revkey = malloc(sizeof(double) * 9);

    if (cofactors == NULL || revkey == NULL)
        return 84;
    cofactors[0] = key[4] * key[8] - key[5] * key[7];
    cofactors[1] = key[5] * key[6] - key[3] * key[8];
    cofactors[2] = key[3] * key[7] - key[4] * key[6];
    cofactors[3] = key[7] * key[2] - key[8] * key[1];
    cofactors[4] = key[0] * key[8] - key[2] * key[6];
    cofactors[5] = key[6] * key[1] - key[7] * key[0];
    cofactors[6] = key[1] * key[5] - key[2] * key[4];
    cofactors[7] = key[3] * key[2] - key[5] * key[0];
    cofactors[8] = key[0] * key[4] - key[1] * key[3];
    if (decrypt_key_3x3(argv, key, revkey, cofactors) == 84)
        return 84;
    free(cofactors);
    free(revkey);
    return 0;
}
