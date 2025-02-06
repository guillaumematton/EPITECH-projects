/*
** EPITECH PROJECT, 2024
** my_strncpy.c
** File description:
** copy n characters
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; n != 0; n--){
        dest[i] = src[i];
        i++;
    }
    return dest;
}
