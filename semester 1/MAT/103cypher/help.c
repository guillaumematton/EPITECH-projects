/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** print help
*/

#include <stdio.h>
#include <stdlib.h>

void print_help(void)
{
    printf("USAGE\n    ");
    printf("./103cipher message key flag\n\n\n");
    printf("DESCRIPTION\n    ");
    printf("message     a message, made of ASCII characters\n");
    printf("    key the encryption key, made of ASCII characters\n");
    printf("    flag 0 for the message to be encrypted, 1 to be decrypted\n");
    return;
}

int *get_message_2x2(char **argv, int *message)
{
    int i = 0;

    for (; argv[1][i] != '\0'; i++)
        message[i] = argv[1][i];
    for (; (i + 1) % 2 != 0; i++)
        message[i] = 0;
    message[i] = 0;
    return message;
}

int *get_decrypted_message(int *message, int *decrypted, double *key)
{
    int i = 0;

    for (i = 0; message[i] != 0; i++){
        decrypted[i] = message[i] * key[0] + message[i + 1] * key[2];
        i++;
        decrypted[i] = message[i - 1] * key[1] + message[i] * key[3];
    }
    return decrypted;
}
