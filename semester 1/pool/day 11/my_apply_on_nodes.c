/*
** EPITECH PROJECT, 2024
** my_apply_on_nodes
** File description:
** apply a function given as parameter
*/

#include "include/mylist.h"
#include <stdlib.h>

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    while (begin != NULL){
        f(begin->data);
        begin = begin->next;
    }
    return 0;
}
