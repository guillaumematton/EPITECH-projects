/*
** EPITECH PROJECT, 2024
** my str n cat
** File description:
** my str n cat
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;

    while (dest[i] != '\0'){
        i++;
    }
    for (int o = 0; src[o] != '\0' && o < nb; o++){
        dest[i] = src[o];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
