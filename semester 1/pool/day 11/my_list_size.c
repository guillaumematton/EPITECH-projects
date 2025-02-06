/*
** EPITECH PROJECT, 2024
** my_list_size
** File description:
** return the number of elements on the list
*/

#include <stdlib.h>
#include "include/mylist.h"

int my_list_size(linked_list_t const *begin)
{
    int length = 0;
    linked_list_t *tmp = (linked_list_t *)begin;

    while (tmp != NULL){
        tmp = tmp->next;
        length++;
    }
    return length;
}
