/*
** EPITECH PROJECT, 2024
** count island
** File description:
** literally count islands
*/

#include <stdio.h>

char **checkage(char **world, int x, int y, int nb)
{
    if (world[y][x] == 'X'){
        world[y][x] = (nb + 47);
        if (x == 0)
            checkage(world, x + 1, y, nb);
        if (y == 0)
            checkage(world, x, y + 1, nb);
        if (x != 0 && world[y][x + 1] != '\0'){
            checkage(world, x + 1, y, nb);
            checkage(world, x - 1, y, nb);
        }
        if (y != 0 && world[y + 1] != NULL){
            checkage(world, x, y - 1, nb);
            checkage(world, x, y + 1, nb);
        }
    }
    return world;
}


int changenb(char **world, int x, int y, int nb)
{
    if (world[y][x] == 'X')
        nb++;
    return nb;
}

int count_island(char** world)
{
    int x;
    int y;
    int nb = 0;

    for (y = 0; world[y] != NULL; y++){
        for (x = 0; world[y][x] != '\0'; x++){
            nb = changenb(world, x, y, nb);
            world = checkage(world, x, y, nb);
        }
    }
    return nb;
}
