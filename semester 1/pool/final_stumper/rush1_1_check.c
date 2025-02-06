/*
** EPITECH PROJECT, 2024
** rush1_1_check
** File description:
** Analysis of the rush1-1
*/

#include "include/my.h"

int centerloop1(char *square, int i, int longueur)
{
    if (square[i] != '|') {
        return 84;
    }
    i += 1;
    for (int f = 0; f < longueur - 2; f += 1) {
        if (square[i] != ' ') {
            return 84;
        }
        i += 1;
    }
    if (square[i] != '|') {
        return 84;
    }
    return 1;
}

int error_handling_firstlast1(char *square, int longueur, int largeur)
{
    int i = 1;
    int g = 0;

    for (; i <= longueur - 2; i += 1)
        if (square[i] != '-')
            return 84;
    if (square[i] != 'o')
        return 84;
    i = (longueur + 1) * (largeur - 1);
    if (square[i] != 'o')
        return 84;
    g = i;
    i += 1;
    for (; i <= g + longueur - 2; i++)
        if (square[i] != '-')
            return 84;
    if (square[i] != 'o')
        return 84;
    return 1;
}

int error_handling_center1(char *square, int i, int longueur, int largeur)
{
    i = 0;
    for (int j = 0; j < largeur - 2; j += 1) {
        i += longueur + 1;
        if (centerloop1(square, i, longueur) == 84) {
            return 84;
        }
    }
    return 1;
}

static void end_print1(int longueur, int largeur)
{
    my_putstr("[rush1-1] ");
    my_put_nbr(longueur);
    my_putchar(' ');
    my_put_nbr(largeur);
    my_putchar('\n');
    return;
}

int square1_analysis(char *square)
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
    if (error_handling_firstlast1(square, longueur, largeur) == 84)
        return 0;
    if (error_handling_center1(square, i, longueur, largeur) == 84)
        return 0;
    end_print1(longueur, largeur);
    return 1;
}
