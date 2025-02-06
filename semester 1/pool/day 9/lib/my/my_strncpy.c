/*
** EPITECH PROJECT, 2024
** my_strncpy.c
** File description:
** copy n characters
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (n >= 0){
        while (i < n){
            dest[i] = src[i];
            i += 1;
        }
        return dest;
    } else
        return 0;
}
