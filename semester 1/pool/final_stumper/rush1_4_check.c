/*
** EPITECH PROJECT, 2024
** rush1-4ana
** File description:
** Analysis of the rush1-4
*/

#include "include/my.h"

int centerloop4(char *square, int i, int longueur)
{
    if (square[i] != 'B') {
        return 84;
    }
    i += 1;
    for (int f = 0; f < longueur - 2; f += 1) {
        if (square[i] != ' ') {
            return 84;
        }
        i += 1;
    }
    if (square[i] != 'B') {
        return 84;
    }
    return 1;
}

int error_handling_firstlast4(char *square, int longueur, int largeur)
{
    int i = 1;
    int g = 0;

    for (; i <= longueur - 2; i += 1){
        if (square[i] != 'B')
            return 84;
    }
    if (square[i] != 'C')
        return 84;
    i = (longueur + 1) * (largeur - 1);
    if (square[i] != 'A')
        return 84;
    g = i;
    i += 1;
    for (; i <= g + longueur - 2; i++)
        if (square[i] != 'B')
            return 84;
    if (square[i] != 'C')
        return 84;
    return 1;
}

int error_handling_center4(char *square, int i, int longueur, int largeur)
{
    i = 0;
    for (int j = 0; j < largeur - 2; j += 1) {
        i += longueur + 1;
        if (centerloop4(square, i, longueur) == 84) {
            return 84;
        }
    }
    return 1;
}

static void end_print4(int longueur, int largeur)
{
    my_putstr("[rush1-4] ");
    my_put_nbr(longueur);
    my_putchar(' ');
    my_put_nbr(largeur);
    my_putchar('\n');
    return;
}

int square4_analysis(char *square)
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
    if (error_handling_firstlast4(square, longueur, largeur) == 84)
        return 0;
    if (error_handling_center4(square, i, longueur, largeur) == 84)
        return 0;
    end_print4(longueur, largeur);
    return 1;
}
