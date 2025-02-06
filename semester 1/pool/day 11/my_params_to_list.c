/*
** EPITECH PROJECT, 2024
** my_params_to_list.c
** File description:
** put the parameters into a list
*/

#include <stdlib.h>
#include "include/mylist.h"

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    struct linked_list *parameter;
    struct linked_list *tmp;

    for (int i = 0; ac > i; i++){
        parameter = malloc(sizeof(linked_list_t));
        parameter->data = av[i];
        parameter->next = tmp;
        tmp = parameter;
    }
    return tmp;
}
