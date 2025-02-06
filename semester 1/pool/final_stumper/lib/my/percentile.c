/*
** EPITECH PROJECT, 2024
** percentile
** File description:
** calculating the percentile of a letter in parameters
*/

#include "../../include/my.h"

void percentileintegers(int counter, int maxc)
{
    int percent1 = (counter * 10 / maxc) % 10;
    int percent2 = (counter * 100 / maxc) % 10;
    int percent3 = (counter * 1000 / maxc) % 10;
    int percent4 = (counter * 10000 / maxc) % 10;

    my_putstr(" (");
    my_put_nbr(percent1);
    my_put_nbr(percent2);
    my_putchar('.');
    my_put_nbr(percent3);
    my_put_nbr(percent4);
    my_putstr("%)");
}
