/*
** EPITECH PROJECT, 2024
** my top
** File description:
** help_second_line
*/

#include <curses.h>

void print_second_line(int total, int run, int stop, int zombie)
{
    mvprintw(1, 0,
        "Tasks: %d total, %d running, %d sleeping, %d stopped, %d zombie",
        total, run, total - run - stop - zombie, stop, zombie);
    return;
}

char *get_path(char *path, char *name, char *proc)
{
    for (int i = 0; i < 6; i++)
        path[i] = proc[i];
    strcat(path, name);
    strcat(path, "/status");
    return path;
}
