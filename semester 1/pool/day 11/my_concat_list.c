/*
** EPITECH PROJECT, 2024
** my concat list
** File description:
** put one list after the other
*/

#include <stdlib.h>
#include "include/mylist.h"

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *tmp = 0;

    while (begin1 != NULL){
        tmp = *begin1;
        *begin1 = tmp->next;
    }
    tmp->next = begin2;
    *begin1 = tmp->next;
    while (begin2 != NULL)
        begin2 = begin2->next;
}
