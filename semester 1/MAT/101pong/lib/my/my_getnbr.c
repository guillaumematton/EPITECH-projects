/*
** EPITECH PROJECT, 2024
** fake
** File description:
** getnbr
*/

static double follow(int j, char const *str)
{
    int l = 0;
    double b = 0;

    j++;
    for (; '0' <= str[j] && str[j] <= '9'; j++){
        b *= 10;
        b += str[j] - 48;
        l++;
    }
    for (; l > 0; l--){
        b /= 10;
    }
    return b;
}

double my_getnbr(char const *str)
{
    int j = 0;
    int s = 1;
    double a = 0;

    while (str[j] == '+' || str[j] == '-'){
        if (str[j] == '-')
            s *= -1;
        j++;
    }
    for (; '0' <= str[j] && str[j] <= '9'; j++){
        a *= 10;
        a += str[j] - 48;
    }
    if (str[j] == '.'){
        a += follow(j, str);
    }
    a *= s;
    return a;
}
