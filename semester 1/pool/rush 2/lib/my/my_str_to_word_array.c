/*
** EPITECH PROJECT, 2024
** str to word array
** File description:
** change string to a word array
*/

#include <stdlib.h>
#include "../../include/my.h"

int startspace(char const *str, int i)
{
    if (str[i] >= '0' && str[i] <= '9' || 'A' <= str[i] && str[i] <= 'Z')
        return i;
    if ('a' <= str[i] && str[i] <= 'z')
        return i;
    if (str[i] == '\0')
        return i;
    i++;
    startspace(str, i);
}

int spacecond(char const *str, int i)
{
    if (str[i] >= '0' && str[i] <= '9' || 'A' <= str[i] && str[i] <= 'Z')
        return 0;
    if ('a' <= str[i] && str[i] <= 'z')
        return 0;
    return 1;
}

int wordlen(char const *str, int i, int len)
{
    if (str[i] >= '0' && str[i] <= '9' || 'A' <= str[i] && str[i] <= 'Z'){
        len++;
        i++;
        wordlen(str, i, len);
    }
    if ('a' <= str[i] && str[i] <= 'z'){
        len++;
        i++;
        wordlen(str, i, len);
    } else
        return len;
}

char **loop(char const *str, int i, char **newstr)
{
    int j = 0;
    int k = 0;
    char *midstr;

    midstr = malloc(sizeof(char *) * (wordlen(str, i, 0) + 1));
    for (; str[i] != '\0'; i++){
        if (spacecond(str, i) == 1){
            i = startspace(str, i);
            k = 0;
            newstr[j] = my_strdup(midstr);
            midstr = NULL;
            j++;
            midstr = malloc(sizeof(char *) * (wordlen(str, i, 0) + 1));
        }
        midstr[k] = str[i];
        k++;
    }
    newstr[j + 1] = malloc(sizeof(char *) + 1);
    newstr[j + 1] = "0";
    return newstr;
}

char **my_str_to_word_array(char const *str)
{
    int i = startspace(str, 0);
    char **newstr;
    int len = 0;
    int wordnb = 0;

    if (str[i] == '\0')
        return 0;
    len = (wordlen(str, i, len));
    newstr = malloc(sizeof(char *) * (sizeof(str) + 1));
    if (newstr == NULL)
        return 0;
    newstr = loop(str, i, newstr);
    return newstr;
}
