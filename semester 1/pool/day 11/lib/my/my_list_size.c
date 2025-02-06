/*
** EPITECH PROJECT, 2024
** my_list_size
** File description:
** return the number of elements on the list
*/

#include <stdlib.h>
#include "../../include/mylist.h"

int my_list_size(linked_list_t const *begin)
{
    int length = 0;

    while (begin != NULL){
        length++;
        begin = begin->next;
    }
    return length;
}
