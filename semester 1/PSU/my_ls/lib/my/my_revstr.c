/*
** EPITECH PROJECT, 2024
** revstr
** File description:
** reverse a string
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int k = 0;
    char c = 0;
    int d = 0;

    for (; str[k] != '\0'; k++);
    k = k - 1;
    while (k > d){
        c = str[k];
        str[k] = str[d];
        str[d] = c;
        k--;
        d++;
    }
    return str;
}
