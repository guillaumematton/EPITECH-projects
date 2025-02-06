/*
** EPITECH PROJECT, 2024
** str lower case
** File description:
** lower cases
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] += 32;
        }
    }
}
