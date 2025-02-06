/*
** EPITECH PROJECT, 2024
** strcat
** File description:
** link both string
*/

char *my_strcat(char *dest, char const *src)
{
    int i;

    for (i = 0; dest[i] != '\0'; i++);
    for (int j = 0; src[j] != '\0'; j++){
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
