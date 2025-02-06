/*
** EPITECH PROJECT, 2024
** organized
** File description:
** help_add
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/shell.h"
#include "include/struct.h"
#include "include/my.h"

storage_t *error_management(char **args, storage_t *storage, int j)
{
    static int index = 0;

    storage = malloc(sizeof(storage_t));
    if (storage == NULL)
        return NULL;
    if (args[j + 1] == NULL || args[j] == NULL)
        return NULL;
    if (my_strcmp(args[j], "WIRE") != 0 && my_strcmp(args[j], "DEVICE") != 0
        && my_strcmp(args[j], "ACTUATOR") &&
        my_strcmp(args[j], "PROCESSOR") != 0
        && my_strcmp(args[j], "SENSOR") != 0)
        return NULL;
    storage->name = malloc(sizeof(char) * (my_strlen(args[j + 1]) + 1));
    storage->type = malloc(sizeof(char) * (my_strlen(args[j]) + 1));
    if (storage->name == NULL || storage->type == NULL)
        return NULL;
    storage->id = index;
    index += 1;
    return storage;
}

int help_delete(storage_t *oldstorage, storage_t *storage,
    storage_t *nextstorage, void *data)
{
    if (oldstorage == NULL){
        nextstorage = storage->next;
        free(storage->name);
        free(storage->type);
        free(storage);
        *(storage_t **)data = nextstorage;
        return 0;
        }
    free(storage->name);
    free(storage->type);
    free(storage);
    oldstorage->next = nextstorage;
    return 0;
}

int find_num_error(char **args, int j)
{
    int i = 0;

    for (; '0' <= args[j][i] && args[j][i] <= '9'
        && args[j][i] != '\0'; i++);
    if (args[j][i] != '\0')
        return 84;
    return 0;
}

int print_values(storage_t *storage, int actionvalue, int index)
{
    if (index >= 0)
        if (storage->id != index)
            return 84;
    my_putstr(storage->type);
    my_putstr(" n°");
    my_put_nbr(storage->id);
    my_putstr(" - ");
    my_putchar('"');
    my_putstr(storage->name);
    my_putchar('"');
    if (actionvalue == 1)
        my_putstr(" added");
    else if (actionvalue == 2)
        my_putstr(" deleted");
    my_putstr(".\n");
    return 0;
}

int find_node_to_del(int index, void *data)
{
    storage_t *storage = NULL;
    storage_t *oldstorage = NULL;
    storage_t *nextstorage = NULL;

    storage = *(storage_t **)data;
    if (storage == NULL)
        return 84;
    for (; storage->id != index && storage->next != NULL;){
        oldstorage = storage;
        storage = storage->next;
        nextstorage = storage->next;
    }
    if (print_values(storage, 2, index) == 84)
        return 84;
    help_delete(oldstorage, storage, nextstorage, data);
    return 0;
}
