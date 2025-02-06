/*
** EPITECH PROJECT, 2025
** Secured
** File description:
** hash function
*/

#include "includes/hashtable.h"

#include <stdlib.h>

int hash(char const *key, int len)
{
    int d = 0;
    long hashed = 0;

    if (key == NULL || len == 0)
        return 84;
    for (int i = 0; key[i] != '\0'; i++)
        d += key[i];
    hashed = (d * d) + (d * len);
    while (hashed > 2147483647)
        hashed /= 2;
    if (hashed == 84)
        hashed *= 2;
    return (int) hashed;
}

char *help_search(hashtable_t *ht_table, int i, int hashed)
{
    elements_t *data;

    for (; ht_table[i].data != NULL; ht_table[i].data = data->next){
        data = (elements_t *)ht_table[i].data;
        if (data->hashed == hashed)
            return data->value;
    }
    return NULL;
}

char *ht_search(hashtable_t *ht, char *key)
{
    int hashed = 0;
    int size = 0;
    char *phrase = NULL;

    if (ht == NULL || key == NULL)
        return NULL;
    while (ht[size].len != 0)
        size++;
    hashed = hash(key, size);
    if (hashed == 84)
        return NULL;
    for (int i = 0; ht[i].len != 0; i++){
        phrase = help_search(ht, i, hashed);
        if (phrase != NULL)
            return phrase;
    }
    return NULL;
}

void delete_hashtable(hashtable_t *ht)
{
    elements_t *data_next = NULL;
    int len = 0;
    elements_t *data;

    if (ht == NULL)
        return;
    len = ht[0].len;
    for (int i = 0; i < len; i++){
        data = (elements_t *)ht[i].data;
        for (; data != NULL; ht[i].data = data_next){
            data_next = (elements_t *)data->next;
            free(data->value);
            free(data);
        }
    }
    free(ht);
}

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = NULL;

    if (hash == NULL)
        return NULL;
    ht = malloc(sizeof(hashtable_t *) * len);
    if (ht == NULL)
        return NULL;
    for (int i = 0; i < len; i++)
        ht[i].len = len;
    return ht;
}
