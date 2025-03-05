/*
** EPITECH PROJECT, 2024
** my putstr
** File description:
** print char by char
*/

#include "../../include/lib.h"
#include <unistd.h>

void my_puterr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(2, &str[i], 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i++;
    }
    return i;
}
