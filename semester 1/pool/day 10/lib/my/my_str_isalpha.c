/*
** EPITECH PROJECT, 2024
** my str isalpha
** File description:
** check for letters
*/

int my_str_isalpha(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++){
        if (str[i] > 'z' || 'a' > str[i] && str[i] > 'Z' || 'A' > str[i])
            return 0;
    }
    return 1;
}
