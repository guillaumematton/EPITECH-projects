/*
** EPITECH PROJECT, 2024
** bs_mytop
** File description:
** testing functions
*/

#include <stdio.h>
#include <errno.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "include/my.h"

int my_get_realtime(void)
{
    char *realtime;
    time_t tm;
    int j = 11;
    int i = 0;

    realtime = malloc(sizeof(char) * 9);
    if (realtime == NULL)
        return 84;
    time(&tm);
    for (; i < 8; i++){
        realtime[i] = ctime(&tm)[j];
        j++;
    }
    realtime[i] = '\0';
    mvprintw(0, 0, "top - %s", realtime);
    free(realtime);
    return 0;
}

int main(int argc, char **argv)
{
    initscr();
    noecho();
    curs_set(0);
    timeout(3000);
    while (1){
        if (my_get_uptime() == 84 || my_get_realtime() == 84
            || get_nbr_proc() == -5 || get_cpu_info() == 84
            || set_list_header() == 84 || read_mem() == 84
            || read_swap() == 84){
            curs_set(1);
            endwin();
            return 84;
        }
        if (getch() == 'q'){
            curs_set(1);
            endwin();
            return 0;
        }
        clear();
    }
}
