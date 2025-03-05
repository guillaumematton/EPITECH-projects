/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my_str_to_word_array
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/lib.h"

int find_size(char *buffer)
{
    int size = 2;
    int i = 0;

    for (; buffer[i] == ' ' || buffer[i] == '\t'; i++);
    if (buffer[i] == '\0')
        return 0;
    for (; buffer[i] != '\0'; i++){
        if (buffer[i] == ' ' || buffer[i] == '\t')
            size++;
        for (; buffer[i] == ' ' || buffer[i] == '\t'; i++);
        if (buffer[i] == '\0')
            return (size - 1);
    }
    return size;
}

char *cpy_str(char *array, char *buffer, int i, int j)
{
    int l = 0;

    array = malloc(sizeof(char) * ((j - i) + 1));
    if (array == NULL)
        return NULL;
    for (l = 0; i < j; l++){
        array[l] = buffer[i];
        i++;
    }
    array[l] = '\0';
    return array;
}

char **alloc_array(char **array, int size)
{
    if (size == 0)
        return NULL;
    array = malloc(sizeof(char *) * size);
    if (array == NULL)
        return NULL;
    return array;
}

char **my_str_to_word_array(char *buffer)
{
    int size = find_size(buffer);
    char **array = alloc_array(array, size);
    int j = 0;
    int k = 0;

    if (array == NULL)
        return NULL;
    for (; buffer[j] == ' ' || buffer[j] == '\t'; j++);
    for (int i = j; buffer[i] != '\0'; i = j){
        for (j = i; buffer[j] != ' ' && buffer[j] != '\t' &&
            buffer[j] != '\0'; j++);
        array[k] = cpy_str(array[k], buffer, i, j);
        if (array[k] == NULL)
            return NULL;
        k++;
        for (; buffer[j] == ' ' || buffer[j] == '\t'; j++);
    }
    array[k] = NULL;
    return array;
}
