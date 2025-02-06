/*
** EPITECH PROJECT, 2025
** str to word array
** File description:
** my_str_to_word_array
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/struct.h"

int place_after_spaces(char *string, int i)
{
    for (; string[i] == ' ' || string[i] == '\n'; i++);
    return i;
}

char **alloc_mem(array_t *array, char *string, int i)
{
    int k = 0;

    if (string[i] == ' ' || string[i] == '\n' || string[i] == '\0'){
        array->word_array[array->j] = malloc(sizeof(char)
            * (i - array->itemp + 1));
        if (array->word_array == NULL)
            return NULL;
        for (k = 0; array->itemp < i; array->itemp += 1){
            array->word_array[array->j][k] = string[array->itemp];
            k++;
        }
        array->word_array[array->j][k] = '\0';
    }
    return array->word_array;
}

void store_words(array_t *array, char *string)
{
    array->itemp = 0;
    array->j = 0;
    for (int i = 1; string[i - 1] != '\0'; i++){
        array->word_array = alloc_mem(array, string, i);
        if (string[i] == ' ' || string[i] == '\n' || string[i] == '\0'){
            array->j += 1;
            i = place_after_spaces(string, i);
            array->itemp = i;
        }
    }
    array->word_array[array->j] = NULL;
}

char **my_str_to_word_array(char *string)
{
    array_t array;
    int nbr_of_words = 2;

    for (int i = 0; string[i] != '\0'; i++){
        if (string[i] == ' ' || string[i] == '\n'){
            nbr_of_words += 1;
            i = place_after_spaces(string, i);
        }
    }
    array.word_array = malloc(sizeof(char *) * nbr_of_words);
    if (array.word_array == NULL)
        return NULL;
    store_words(&array, string);
    return array.word_array;
}
