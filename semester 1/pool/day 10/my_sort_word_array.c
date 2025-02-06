/*
** EPITECH PROJECT, 2024
** my_sort_word_array
** File description:
** sort words in ascii order
*/

int my_sort_word_array_part2(char **tab, int k, int i)
{
    char *c;

    for (int i = 0; i < nmb; i++)
        if (tab[i][k] == NULL || tab[i + 1][k] == NULL)
            return tab;
        else if (tab[i][k] < tab[i + 1][k]){
            c = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = c;
        }
    return tab;
}

int my_sort_word_array(char **tab)
{
    int nmb = 0;
    int maxl = 0;
    int l;

    for (int j = 0; tab[j] != NULL; j++){
        nmb++;
        l = my_strlen(tab[j]);
        if (l > maxl)
            maxl = l;
    }
    for (int j = 0; j < maxl; j++){
        for (int k = 0; tab[k] != NULL; k++){
            tab = my_sort_word_array_part2(tab, k, i);
        }
    }
    return 0;
}
