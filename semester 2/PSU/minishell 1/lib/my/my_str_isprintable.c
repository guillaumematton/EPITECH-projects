/*
** EPITECH PROJECT, 2024
** my str is printable
** File description:
** return 1 if printable
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] < 32 || str[i] > 126){
            return 1;
        }
    }
    return 0;
}
