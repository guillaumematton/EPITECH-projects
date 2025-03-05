/*
** EPITECH PROJECT, 2024
** mystrcat
** File description:
** concatenates two string
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;

    while (dest[i] != '\0'){
        i++;
    }
    for (int n = 0; src[n] != '\0'; n++){
        dest[i] = src[n];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
