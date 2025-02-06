/*
** EPITECH PROJECT, 2024
** my_revstr.c
** File description:
** reverse string
*/

char *my_revstr(char *str)
{
    int i = 0;
    char j;
    int length = 0;

    while (str[i] != '\0'){
        length += 1;
        i += 1;
    }
    i = 0;
    while (length > i){
        j = str[length];
        str[length] = str[i];
        str[i] = j;
        length--;
        i = i + 1;
    }
    return str;
}
