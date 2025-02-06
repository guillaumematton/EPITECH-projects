/*
** EPITECH PROJECT, 2024
** my chow word array
** File description:
** display content of an array of words
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_show_word_array(char *const *tab)
{
    int g = 0;
    int n = 0;

    for (int i = 0; tab[i] != 0; i++){
        while (tab[i][g] != '\0'){
            write(1, &tab[i][g], 1);
            g++;
        }
        g = 0;
        n = '\n';
        write(1, &n, 1);
    }
    return 0;
}
