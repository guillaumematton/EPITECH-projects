/*
** EPITECH PROJECT, 2024
** B-CPE-101-LIL-1-1-myprintf-fabien.skotarek
** File description:
** miniprintffoncition
*/

#include "../../include/my.h"

int case1(int nb, int precision)
{
    int l = my_nbrlength(nb);

    if (precision >= 0){
        for (; l < precision; l++){
            my_putchar('0');
        }
    }
    my_put_nbr(nb);
    return l;
}

int case2(char *str, int precision)
{
    int l;

    if (precision >= 0){
        for (int i = 0; i < precision && str[i] != '\0'; i++)
            my_putchar(str[i]);
        return precision;
    }
    l = my_putstr(str);
    return l;
}
