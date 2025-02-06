/*
** EPITECH PROJECT, 2024
** my is prime
** File description:
** return 1 if prime 0 if not
*/

int my_is_prime(int nb)
{
    int a = 2;

    if (nb <= 1){
        return 0;
    }
    for (; a < nb; a++){
        if ((nb % a) == 0){
            return 0;
        }
    }
    return 1;
}
