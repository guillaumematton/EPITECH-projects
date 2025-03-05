/*
** EPITECH PROJECT, 2024
** my find prime sup
** File description:
** returns the smallest prime number
*/

#include "../../include/lib.h"

int my_find_prime_sup(int nb)
{
    while (my_is_prime(nb) != 1){
        nb++;
    }
    return nb;
}
