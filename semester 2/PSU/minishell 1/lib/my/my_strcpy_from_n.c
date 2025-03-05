/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my_strcpy_from_n
*/

void my_strcpy_from_n(char *dest, char *src, int n)
{
    int i = 0;

    for (; src[n] != '\0'; n++){
        dest[i] = src[n];
        i++;
    }
    dest[i] = '\0';
}
