/*
** EPITECH PROJECT, 2024
** str isupper
** File description:
** if str is uppercase
*/

int my_str_isupper(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++){
        if (str[i] > 'Z' || 'A' > str[i])
            return 0;
    }
    return 1;
}
