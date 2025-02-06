/*
** EPITECH PROJECT, 2024
** fake
** File description:
** getnbr
*/

int my_getnbr(char const *str)
{
    int j = 0;
    int s = 1;
    long a = 0;
    int nbr;

    while (str[j] == '+' || str[j] == '-'){
        if (str[j] == '-')
            s *= -1;
        j++;
    }
    for (; '0' <= str[j] && str[j] <= '9'; j++){
        a *= 10;
        a += str[j] - 48;
    }
    a *= s;
    nbr = (int) a;
    return nbr;
}
