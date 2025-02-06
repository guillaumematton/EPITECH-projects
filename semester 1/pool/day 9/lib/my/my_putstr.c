/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** first char of string
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i = i + 1;
    }
    return 0;
}
