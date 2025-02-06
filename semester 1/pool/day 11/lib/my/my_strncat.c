/*
** EPITECH PROJECT, 2024
** strncat
** File description:
** strcat but add n characters instead
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i;

    for (i = 0; dest[i] != '\0'; i++);
    for (int j = 0; src[j] != '\0' && j < nb; j++){
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
