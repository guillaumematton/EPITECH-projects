/*
** EPITECH PROJECT, 2024
** my find prime sup
** File description:
** search for the smallest prime number above int
*/

#include "../../include/my.h"

int my_find_prime_sup(int nb)
{
    int s;

    s = my_is_prime(nb);
    while (s == 0){
        nb++;
        s = my_is_prime(nb);
    }
    return nb;
}
