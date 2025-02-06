/*
** EPITECH PROJECT, 2024
** str printable
** File description:
** check for non-printable characters
*/

int my_str_isprintable(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++){
        if (str[i] < 32 || str[i] == 127)
            return 0;
    }
    return 1;
}
