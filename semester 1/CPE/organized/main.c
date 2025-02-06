/*
** EPITECH PROJECT, 2024
** organised
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/shell.h"
#include "include/struct.h"
#include "include/my.h"

int add(void *data, char **args)
{
    storage_t *storage = NULL;
    storage_t *tempstorage = NULL;
    int i = 0;

    for (; args[i] != NULL; i++);
    if (i % 2 != 0 || args[0] == NULL)
        return 84;
    for (int j = 0; j < i; j += 2){
        storage = *(storage_t **)data;
        tempstorage = error_management(args, tempstorage, j);
        if (tempstorage == NULL)
            return 84;
        my_strcpy(tempstorage->type, args[j]);
        my_strcpy(tempstorage->name, args[j + 1]);
        tempstorage->next = storage;
        *(storage_t **)data = tempstorage;
        print_values(tempstorage, 1, -1);
    }
    return 0;
}

int del(void *data, char **args)
{
    int index = 0;

    if (args[0] == NULL)
        return 84;
    for (int j = 0; args[j] != NULL; j++){
        if (find_num_error(args, j) == 84)
            return 84;
        index = my_getnbr(args[j]);
        if (find_node_to_del(index, data) == 84)
            return 84;
    }
    return 0;
}

int sort(void *data, char **args)
{
    int j = 0;
    storage_t *sorted = NULL;

    for (j = 0; args[j] != NULL; j++){
        if (my_strcmp(args[j], "TYPE") != 0 && my_strcmp(args[j], "NAME") != 0
            && my_strcmp(args[j], "ID") != 0)
            return 84;
        for (; args[j + 1] != NULL && my_strcmp(args[j + 1], "-r") == 0; j++);
    }
    if (j == 0)
        return 84;
    sorted = sort_list(data, args);
    *(storage_t **)data = sorted;
    return 0;
}

int disp(void *data, char **args)
{
    storage_t *storage = *(storage_t **)data;

    if (args[0] != NULL)
        return 84;
    for (; storage != NULL; storage = storage->next)
        print_values(storage, 0, -1);
    return 0;
}

int main(void)
{
    storage_t *storage = NULL;
    storage_t *nextstorage = NULL;
    int err = 0;

    err = workshop_shell(&storage);
    for (; storage != NULL; storage = nextstorage){
        nextstorage = storage->next;
        free(storage->name);
        free(storage->type);
        free(storage);
    }
    return err;
}
