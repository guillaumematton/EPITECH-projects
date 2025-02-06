/*
** EPITECH PROJECT, 2024
** fake
** File description:
** getnbr
*/

long my_getnbr(char const *str)
{
    int j = 0;
    int s = 1;
    long a = 0;

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
    return a;
}
