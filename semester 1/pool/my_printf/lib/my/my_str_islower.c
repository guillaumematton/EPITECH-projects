/*
** EPITECH PROJECT, 2024
** my str is lower
** File description:
** return 1 if lower alphabet
*/

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] < 'a' || str[i] > 'z'){
            return 0;
        }
    }
    return 1;
}
