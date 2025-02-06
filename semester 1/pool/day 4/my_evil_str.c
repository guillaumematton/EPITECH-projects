/*
** EPITECH PROJECT, 2024
** evil str
** File description:
** reverse order
*/

int my_strlen(char const *str);

char *my_evil_str(char *str)
{
    int k = my_strlen(str);
    char i;
    int l = 0;

    k = k - 1;
    while (k > l){
        i = str[k];
        str[k] = str[l];
        str[l] = i;
        k = k - 1;
        l = l + 1;
    }
    return str;
}
