/*
** EPITECH PROJECT, 2024
** my_strupcase
** File description:
** put every letter in upper case
*/

char *my_strupcase(char *str)
{
    int i;
    int length = 0;

    for (i = 0; str[i] != '\0'; i++)
        length++;
    for (i = 0; i < length; i++){
        if ('a' <= str[i] && str[i] <= 'z')
            str[i] -= 32;
    }
    return str;
}
