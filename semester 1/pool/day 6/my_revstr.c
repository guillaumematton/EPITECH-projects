/*
** EPITECH PROJECT, 2024
** my_revstr.c
** File description:
** reverse string
*/

char *my_revstr(char *str)
{
    int k = 0;
    char i;
    int l = 0;

    while (str[k] != '\0')
        k++;
    k = k - 1;
    while (k > l){
        i = str[k];
        str[k] = str[l];
        str[l] = i;
        k = k - 1;
        l = l + 1;
    }
    return str;
}
