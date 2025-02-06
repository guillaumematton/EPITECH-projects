/*
** EPITECH PROJECT, 2024
** countwords
** File description:
** functions related to word storage
*/

#include <stdio.h>
#include <stdlib.h>

int stock_new_word(char **words_found, char *argv, int i)
{
    int itemp = i;
    int size = 0;
    int j = 0;
    int k = 0;

    for (; argv[i] != ' ' && argv[i] != '\0'; i++);
    size = i - itemp + 1;
    for (; words_found[j] != NULL; j++);
    words_found[j] = malloc(sizeof(char) * size);
    if (words_found[j] == NULL)
        return 84;
    for (i = itemp; argv[i] != ' ' && argv[i] != '\0'; k++){
        words_found[j][k] = argv[i];
        i++;
    }
    words_found[j][k + 1] = '\0';
    return 0;
}

void print_words_found(char **words_found, int *nbr_of_times)
{
    int i = 0;

    if (words_found[0] == NULL)
        printf("\n");
    for (; words_found[i] != NULL; i++)
        printf("%s: %d\n", words_found[i], nbr_of_times[i]);
    return;
}
