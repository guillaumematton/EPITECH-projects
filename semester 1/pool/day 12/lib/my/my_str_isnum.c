/*
** EPITECH PROJECT, 2024
** my is num
** File description:
** check if only numbers
*/

int my_str_isnum(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++){
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}
