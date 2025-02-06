/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** cpy string to memory
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = 0;
    char *str;

    while (src[i] != '\0')
        i++;
    str = malloc(sizeof(char) * (i + 1));
    i = 0;
    if (str == NULL)
        return 0;
    while (src[i] != '\0'){
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return str;
}
