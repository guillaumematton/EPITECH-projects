/*
** EPITECH PROJECT, 2024
** rush1-3ana
** File description:
** Analysis of the rush1-3
*/

#include "include/my.h"

int error_handling_firstlast(char *square, int longueur, int largeur)
{
    int i = 1;

    while (i <= longueur - 2) {
	if (square[i] != 'B') {
	    return 84;
	}
	i += 1;
    }
    i = (longueur * largeur) - 1;
    if (square[i] != 'C') {
	return 84;
    }
    i += 1;
    while (i <= longueur + (longueur * largeur) - 3) {
	if (square[i] != 'B') {
	    return 84;
	}
	i += 1;
    }
    if (square[i] != 'C') {
	return 84;
    }
    return 1;
}

int square3_analysis(char *square)
{
    int i = 0;
    int j = 0;
    int longueur = 0;
    int largeur = 0;

    while (square[i] != '\0') {
	if (square[i] == '\n') {
	    largeur += 1;
	}
	i += 1;
    }
    while (square[j] != '\n') {
	longueur += 1;
	j += 1;
    }
    if (error_handling_firstlast(square, longueur, largeur + 1) == 84) {
	return 84;
    }
    my_put_nbr(longueur);
    my_putchar('-');
    my_put_nbr(largeur + 1);
}
