/*
** EPITECH PROJECT, 2024
** my_list_rev
** File description:
** inverse list order
*/

#include "include/mylist.h"
#include "include/my.h"
#include <stdlib.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *ele = *begin;
    linked_list_t *prevele = NULL;
    linked_list_t *nextele = NULL;

    while (ele != NULL){
        nextele = ele->next;
        ele->next = prevele;
        prevele = ele;
        ele = ele->next;
    }
    *begin = prevele;
}
