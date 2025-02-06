/*
** EPITECH PROJECT, 2024
** my is prime
** File description:
** prime nbr or not
*/

int my_is_prime(int nb)
{
    int a = 0;

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
