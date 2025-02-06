/*
** EPITECH PROJECT, 2024
** my_str is num
** File description:
** return 1 if digits
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] < '0' || str[i] > '9'){
            return 0;
        }
    }
    return 1;
}
