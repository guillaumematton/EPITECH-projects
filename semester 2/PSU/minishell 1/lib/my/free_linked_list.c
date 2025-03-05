/*
** EPITECH PROJECT, 2025
** lib
** File description:
** free_linked_list
*/

#include "../../include/lib.h"
#include <stdlib.h>

void free_linked_list(env_t **env)
{
    env_t *environ = *env;
    env_t *next_env = NULL;

    while (environ != NULL){
        next_env = environ->next;
        free(environ->var);
        free(environ);
        environ = next_env;
    }
}
