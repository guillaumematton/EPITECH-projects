/*
** EPITECH PROJECT, 2024
** my putstr
** File description:
** print char by char
*/

#include "include/my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i++;
    }
    return i;
}
