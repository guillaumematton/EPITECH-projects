/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** afficher un string
*/

#include <unistd.h>
#include "../includes/hashtable.h"

void my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar (*str);
        str++;
    }
}
