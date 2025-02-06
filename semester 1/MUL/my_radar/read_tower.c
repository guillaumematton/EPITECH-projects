/*
** EPITECH PROJECT, 2025
** radar
** File description:
** read_tower
*/

#include "include/my.h"
#include "include/struct.h"
#include "include/c_lib.h"

tower_t *set_tower(char *line, tower_t *tower)
{
    int j = 2;

    tower->x = 0;
    tower->y = 0;
    tower->radius = 0;
    for (; '0' <= line[j] && line[j] <= '9'; j++){
        tower->x *= 10;
        tower->x += line[j] - 48;
    }
    j++;
    for (; '0' <= line[j] && line[j] <= '9'; j++){
        tower->y *= 10;
        tower->y += line[j] - 48;
    }
    j++;
    for (; '0' <= line[j] && line[j] <= '9'; j++){
        tower->radius *= 10;
        tower->radius += line[j] - 48;
    }
    return tower;
}

int add_tower(char *line, tower_t **tower)
{
    int j = 2;
    tower_t *temp_tower = malloc(sizeof(tower_t));
    tower_t *list = *tower;

    if (temp_tower == NULL)
        return 84;
    temp_tower = set_tower(line, temp_tower);
    temp_tower->next = NULL;
    temp_tower->next = list;
    *tower = temp_tower;
    return 0;
}

int read_tower(char *line, tower_t **tower)
{
    int i = 1;

    for (int j = 0; j < 3; j++){
        if (line[i] != ' ')
            return 84;
        i++;
        if ('0' > line[i] || line[i] > '9')
            return 84;
        for (; '0' <= line[i] && line[i] <= '9'; i++);
    }
    if (line[i] != '\n' && line[i] != '\0')
        return 84;
    if (add_tower(line, tower) == 84)
        return 84;
    if (line[i] == '\0')
        return 1;
    return 0;
}
