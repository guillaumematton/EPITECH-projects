/*
** EPITECH PROJECT, 2024
** organize
** File description:
** sort
*/

#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

storage_t *sort_id(storage_t *sorted, int reverse, storage_t *newstorage)
{
    storage_t *storage = NULL;

    if (sorted == NULL || newstorage->id >= sorted->id && reverse >= 0
        || sorted->id >= newstorage->id && reverse == 1){
            newstorage->next = sorted;
            sorted = newstorage;
    } else {
        storage = sorted;
        for (; storage->next != NULL && storage->next->id > newstorage->id
            && reverse == 1 || storage->next != NULL
            && storage->next->id < newstorage->id && reverse == -1;
            storage = storage->next);
        newstorage->next = storage->next;
        storage->next = newstorage;
    }
    return sorted;
}

storage_t *sort_name(storage_t *sorted, int reverse, storage_t *newstorage)
{
    storage_t *storage = NULL;

    if (sorted == NULL || my_strcmp(newstorage->name, sorted->name) <= 0
        && reverse >= 0 || my_strcmp(sorted->name, newstorage->name) <= 0
        && reverse == -1){
            newstorage->next = sorted;
            sorted = newstorage;
    } else {
        storage = sorted;
        for (; storage->next != NULL &&
            my_strcmp(storage->next->name, newstorage->name) > 0
            && reverse == 1 || storage->next != NULL
            && my_strcmp(storage->next->name, newstorage->name) < 0 &&
            reverse == -1;
            storage = storage->next);
        newstorage->next = storage->next;
        storage->next = newstorage;
    }
    return sorted;
}

storage_t *sort_type(storage_t *sorted, int reverse, storage_t *newstorage)
{
    storage_t *storage = NULL;

    if (sorted == NULL || my_strcmp(newstorage->name, sorted->name) <= 0
        && reverse >= 0 || my_strcmp(sorted->name, newstorage->name) <= 0
        && reverse == -1){
            newstorage->next = sorted;
            sorted = newstorage;
    } else {
        storage = sorted;
        for (; storage->next != NULL &&
            my_strcmp(storage->next->name, newstorage->name) > 0
            && reverse == 1 || storage->next != NULL
            && my_strcmp(storage->next->name, newstorage->name) < 0
            && reverse == -1;
            storage = storage->next);
        newstorage->next = storage->next;
        storage->next = newstorage;
    }
    return sorted;
}

storage_t *insertion_sort(storage_t *sorted, storage_t *head,
    int reverse, int type)
{
    storage_t *current = head;
    storage_t *nextstorage = NULL;

    for (; current != NULL; current = nextstorage){
        nextstorage = current->next;
        if (type == 0)
            sorted = sort_id(sorted, reverse, current);
        if (type == 1)
            sorted = sort_name(sorted, reverse, current);
        if (type == 2)
            sorted = sort_type(sorted, reverse, current);
    }
    return sorted;
}

storage_t *sort_list(void *data, char **args)
{
    storage_t *sorted = NULL;
    storage_t *head = *(storage_t **)data;
    int reverse = 1;

    if (my_strcmp(args[0], "ID") == 0){
        for (int i = 1; args[i] != NULL && my_strcmp(args[i], "-r") == 0; i++)
            reverse *= -1;
        sorted = insertion_sort(sorted, head, reverse, 0);
    }
    if (my_strcmp(args[0], "NAME") == 0){
        for (int i = 1; args[i] != NULL && my_strcmp(args[i], "-r") == 0; i++)
            reverse *= -1;
        sorted = insertion_sort(sorted, head, reverse, 1);
    }
    if (my_strcmp(args[0], "TYPE") == 0){
        for (int i = 1; args[i] != NULL && my_strcmp(args[i], "-r") == 0; i++)
            reverse *= -1;
        sorted = insertion_sort(sorted, head, reverse, 2);
    }
    return sorted;
}
