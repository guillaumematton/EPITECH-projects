/*
** EPITECH PROJECT, 2024
** str islower
** File description:
** if str is lowercase
*/

int my_str_islower(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++){
        if (str[i] > 'z' || 'a' > str[i])
            return 0;
    }
    return 1;
}
