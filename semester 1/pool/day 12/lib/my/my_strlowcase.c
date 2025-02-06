/*
** EPITECH PROJECT, 2024
** my_strlowercase
** File description:
** same as before but lowering instead
*/

char *my_strlowcase(char *str)
{
    int i;
    int length = 0;

    for (i = 0; str[i] != '\0'; i++)
        length++;
    for (i = 0; i < length; i++){
        if ('A' <= str[i] && str[i] <= 'Z')
            str[i] += 32;
    }
    return str;
}
