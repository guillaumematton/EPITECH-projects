/*
** EPITECH PROJECT, 2024
** my_str_isaplpha
** File description:
** return 1 if alpha 0 if other
*/

int my_str_isalphanum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if ((str[i] < 'A' || str[i] > 'Z' && str[i] < 'a' || str[i] > 'z')
            && (str[i] < '0' || str[i] > '9') &&
            str[i] != '_' && str[i] != '.'){
            return 0;
        }
    }
    return 1;
}
