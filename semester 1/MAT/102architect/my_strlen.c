/*
** EPITECH PROJECT, 2024
** my strlen
** File description:
** string's length returned
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i++;
    }
    return i;
}
