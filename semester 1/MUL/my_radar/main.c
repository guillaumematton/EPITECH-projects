/*
** EPITECH PROJECT, 2025
** radar
** File description:
** main
*/

#include "include/my.h"
#include "include/c_lib.h"
#include "include/struct.h"

void free_linked_lists(tower_t **tower, airplane_t **airplane)
{
    tower_t *next_tower;
    airplane_t *next_airplane;
    tower_t *tower_list = *tower;
    airplane_t *airplane_list = *airplane;

    for (; tower_list != NULL; tower_list = next_tower){
        next_tower = tower_list->next;
        free(tower_list);
    }
    for (; airplane_list != NULL; airplane_list = next_airplane){
        next_airplane = airplane_list->next;
        free(airplane_list);
    }
    return;
}

int main(int argc, char **argv)
{
    int err = 0;
    airplane_t *airplane = NULL;
    tower_t *tower = NULL;

    if (argc != 2)
        return 84;
    if (my_strcmp(argv[1], "-h") != 0){
        err = read_file(argv[1], &airplane, &tower);
        if (err == 84)
            return 84;
        err = set_window(&tower, &airplane);
        free_linked_lists(&tower, &airplane);
        return err;
    } else if (my_strcmp(argv[1], "-h") == 0){
        print_help();
        return 0;
    }
}
