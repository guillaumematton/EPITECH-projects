/*
** EPITECH PROJECT, 2024
** my strncpy
** File description:
** copy strin n
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int a = 0; a != n; a++){
        if (a >= n){
            dest[a] = '\0';
            return dest;
        }
        dest[a] = src[a];
    }
    return dest;
}
