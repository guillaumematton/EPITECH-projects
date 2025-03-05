/*
** EPITECH PROJECT, 2024
** revstr
** File description:
** reverse a string
*/

#include "../../include/lib.h"

char *my_revstr(char *str)
{
    int k = 0;
    char c = 0;
    char d = 0;

    k = k + (my_strlen(str)) - 1;
    while (k > d){
        c = str[k];
        str[k] = str[d];
        str[d] = c;
        k--;
        d++;
    }
    return str;
}
