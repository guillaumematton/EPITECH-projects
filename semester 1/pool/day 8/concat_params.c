/*
** EPITECH PROJECT, 2024
** concat params
** File description:
** make parameters 1 string
*/

#include <stdlib.h>

int len(int argc, char **argv)
{
    int j = 0;
    int length = 0;

    for (int i = 0; i < argc; i++){
        while (argv[i][j] != '\0'){
            length++;
            j++;
        }
        j = 0;
    }
    return length;
}

char *concat_params(int argc, char **argv)
{
    int j;
    int k = 0;
    char *str;
    int length = len(argc, argv);

    str = malloc(sizeof(char) * (length + 1));
    for (int i = 0; i < argc; i++){
        while (argv[i][j] != '\0'){
            str[k] = argv[i][j];
            k++;
            j++;
        }
        str[k] = '\n';
        k++;
        j = 0;
    }
    str[k - 1] = '\0';
    return str;
}
