/*
** EPITECH PROJECT, 2024
** my_list_rev
** File description:
** inverse list order
*/

#include "../../include/lib.h"
#include <stdlib.h>

void my_rev_list(env_t **begin)
{
    env_t *ele = *begin;
    env_t *prevele = NULL;
    env_t *nextele = NULL;

    while (ele != NULL){
        nextele = ele->next;
        ele->next = prevele;
        prevele = ele;
        ele = ele->next;
    }
    *begin = prevele;
}
