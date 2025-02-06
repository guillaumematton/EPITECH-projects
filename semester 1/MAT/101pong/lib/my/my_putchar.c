/*
** EPITECH PROJECT, 2024
** my putchar
** File description:
** myputchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
