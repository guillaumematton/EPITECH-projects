/*
** EPITECH PROJECT, 2024
** get number
** File description:
** show series of number
*/

int my_getnbr(char const *str)
{
    int j = 0;
    int s = 1;
    long long a = 0;
    int end;

    while (str[j] == '+' || str[j] == '-'){
        if (str[j] == '-'){
            s *= -1;
        }
        j++;
    }
    while ('0' <= str[j] && str[j] <= '9'){
        a *= 10;
        a += str[j] - 48;
        if (a > 2147483647 && s == 1 || a < -2147483648 && s == -1){
            return 0;
        }
    }
    a *= s;
    end = a;
    return end;
}
