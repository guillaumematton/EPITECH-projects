/*
** EPITECH PROJECT, 2025
** secured
** File description:
** ht_table
*/

#include "includes/hashtable.h"
#include <stdlib.h>

void print_ht_table(hashtable_t const *ht_table, int i)
{
    elements_t *data = ht_table[i].data;

    my_putchar('[');
    my_put_nbr(i);
    my_putstr("]\n");
    if (data->hashed == 0)
        return;
    else {
        for (; data != NULL; data = data->next) {
            my_putstr("> ");
            my_put_nbr(data->hashed);
            my_putstr(" - ");
            my_putstr(data->value);
            my_putchar('\n');
        }
    }
}

void ht_dump(hashtable_t const *ht)
{
    int size = 0;

    if (ht == NULL)
        return;
    size = ht[0].len;
    for (int i = 0; i < size; i++)
        print_ht_table(ht, i);
}

int help_delete(hashtable_t *ht_table, int i, int hashed)
{
    elements_t *old_data = NULL;
    elements_t *next_data = NULL;
    elements_t *data = ht_table[i].data;

    for (; data != NULL; data = data->next){
        next_data = data->next;
        if (data->hashed == hashed && old_data == NULL){
            free(data);
            ht_table[i].data = next_data;
            return 1;
        }
        if (data->hashed == hashed){
            free(data);
            old_data->next = next_data;
            return 1;
        }
        old_data = data;
    }
    return 0;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int hashed = 0;
    int size = 0;

    if (ht == NULL || key == NULL)
        return 84;
    size = ht[0].len;
    hashed = hash(key, size);
    if (hashed == 84)
        return 84;
    for (int i = 0; i < size; i++)
        if (help_delete(ht, i, hashed) == 1)
            return 0;
    return 84;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    elements_t *temp_data = NULL;
    int size = 0;
    int hashed = 0;

    if (ht == NULL || key == NULL || value == NULL)
        return 84;
    size = ht[0].len;
    temp_data = malloc(sizeof(elements_t));
    hashed = hash(key, size);
    if (temp_data == NULL || hashed == 84)
        return 84;
    temp_data->hashed = hashed;
    temp_data->value = value;
    temp_data->next = ht[temp_data->hashed % size].data;
    ht[temp_data->hashed % size].data = temp_data;
    return 0;
}
