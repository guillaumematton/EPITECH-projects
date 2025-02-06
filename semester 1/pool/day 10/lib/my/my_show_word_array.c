/*
** EPITECH PROJECT, 2024
** concat params
** File description:
** make parameters 1 string
*/

#include <stdlib.h>
#include <unistd.h>

int my_show_word_array(char *const *tab)
{
    int j = 0;
    int k = '\n';

    for (int i = 0; tab[i] != 0; i++){
        while (tab[i][j] != '\0'){
            write(1, &tab[i][j], 1);
            j++;
        }
        j = 0;
        write(1, &k, 1);
    }
    return 1;
}
