/*
** EPITECH PROJECT, 2024
** find node
** File description:
** find the node with matching data
*/

#include "include/mylist.h"
#include <stdlib.h>
#include "include/my.h"

linked_list_t *my_find_node(linked_list_t const *begin,
    void const *data_ref, int (*cmp)())
{
    linked_list_t *tmp = 0;

    while (begin != NULL){
        if (cmp(begin->data, data_ref) == 0){
            tmp = (linked_list_t *)begin;
            return tmp;
        }
        begin = begin->next;
    }
    return 0;
}
