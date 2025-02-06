/*
** EPITECH PROJECT, 2024
** my delete nodes
** File description:
** delete matching nodes
*/

#include "include/mylist.h"
#include <stdlib.h>
#include "include/my.h"

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    struct linked_list *tmp = NULL;

    while (begin != NULL){
        tmp = *begin;
        if (cmp(tmp->data, data_ref) == 0){
            free(begin);
            *begin = tmp->next;
        }
        if (cmp(tmp->data, data_ref) != 0){
            *begin = tmp->next;
        }
    }
    return 0;
}
