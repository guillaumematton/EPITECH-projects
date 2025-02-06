/*
** EPITECH PROJECT, 2025
** countwords
** File description:
** main file
*/

#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

int *stock_word(char **words_found, int *nbr_of_times, int i, char *argv)
{
    int j = 0;
    int itemp = i;
    int k = 0;
    int size = 0;

    for (; words_found[j] != NULL; j++){
        itemp = i;
        for (k = 0; words_found[j][k] == argv[itemp]; k++)
            itemp++;
        if (argv[itemp] == ' ' && words_found[j][k] == '\0'){
            nbr_of_times[j] += 1;
            return nbr_of_times;
        }
    }
    nbr_of_times[j] = 1;
    if (stock_new_word(words_found, argv, i) == 84)
        return NULL;
    return nbr_of_times;
}

int find_new_i(char *argv, int i)
{
    for (; argv[i] == ' '; i++);
    return i;
}

int find_word(char *argv, char **words_found, int *nbr_of_times)
{
    int itemp = 0;

    words_found[0] = NULL;
    for (int i = 1; argv[i - 1] != '\0'; i++){
        if (argv[i] == ' ' || argv[i] == '\0') {
            nbr_of_times = stock_word(words_found, nbr_of_times, itemp, argv);
            i = find_new_i(argv, i);
            itemp = i;
        }
        if (nbr_of_times == NULL)
            return 84;
    }
    print_words_found(words_found, nbr_of_times);
    return 0;
}

void free_everything(int *nbr_of_times, char **words_found)
{
    free(nbr_of_times);
    for (int i = 0; words_found[i] != NULL; i++)
        free(words_found[i]);
    free(words_found);
    return;
}

int main(int argc, char **argv)
{
    int *nbr_of_times = NULL;
    char **words_found = NULL;
    int number_of_words = 0;

    if (argc != 2)
        return 84;
    for (int i = 0; argv[1][i] != '\0'; i++)
        if (argv[1][i] == ' ')
            number_of_words += 1;
    nbr_of_times = malloc(sizeof(int) * (number_of_words + 1));
    words_found = malloc(sizeof(char *) * (number_of_words + 1));
    if (nbr_of_times == NULL || words_found == NULL)
        return 84;
    if (find_word(argv[1], words_found, nbr_of_times) == 84){
        free_everything(nbr_of_times, words_found);
        return 84;
    }
    free_everything(nbr_of_times, words_found);
    return 0;
}
