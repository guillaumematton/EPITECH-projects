/*
** EPITECH PROJECT, 2024
** rush1_2_check
** File description:
** Analysis of the rush1-2
*/

#include "include/my.h"

int centerloop2(char *square, int i, int longueur)
{
    if (square[i] != '*') {
        return 84;
    }
    i += 1;
    for (int f = 0; f < longueur - 2; f += 1) {
        if (square[i] != ' ') {
            return 84;
        }
        i += 1;
    }
    if (square[i] != '*') {
        return 84;
    }
    return 1;
}

int error_handling_firstlast2(char *square, int longueur, int largeur)
{
    int i = 1;
    int g = 0;

    for (; i <= longueur - 2; i += 1)
        if (square[i] != '*')
            return 84;
    if (square[i] != 92)
        return 84;
    i = (longueur + 1) * (largeur - 1);
    if (square[i] != 92)
        return 84;
    g = i;
    i += 1;
    for (; i <= g + longueur - 2; i++)
        if (square[i] != '*')
            return 84;
    if (square[i] != '/')
        return 84;
    return 1;
}

int error_handling_center2(char *square, int i, int longueur, int largeur)
{
    i = 0;
    for (int j = 0; j < largeur - 2; j += 1) {
        i += longueur + 1;
        if (centerloop2(square, i, longueur) == 84) {
            return 84;
        }
    }
    return 1;
}

static void end_print2(int longueur, int largeur)
{
    my_putstr("[rush1-2] ");
    my_put_nbr(longueur);
    my_putchar(' ');
    my_put_nbr(largeur);
    my_putchar('\n');
    return;
}

int square2_analysis(char *square)
{
    int i = 0;
    int j = 0;
    int longueur = 0;
    int largeur = 0;

    while (square[i] != '\0') {
        if (square[i] == '\n')
            largeur += 1;
        i += 1;
    }
    while (square[j] != '\n') {
        longueur += 1;
        j += 1;
    }
    if (error_handling_firstlast2(square, longueur, largeur) == 84)
        return 0;
    if (error_handling_center2(square, i, longueur, largeur) == 84)
        return 0;
    end_print2(longueur, largeur);
    return 1;
}
