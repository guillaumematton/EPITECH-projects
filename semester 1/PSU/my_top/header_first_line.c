/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** header_first_line
*/

#include <stdio.h>
#include <errno.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <utmp.h>

int my_getloadavg(double *loadavg, int nelem)
{
    FILE *stream = fopen("/proc/loadavg", "r");
    double *load = malloc(sizeof(double) * 4);

    if (nelem < 1 || stream == NULL || load == NULL)
        return 84;
    if (fscanf(stream, "%lf %lf %lf", &load[0], &load[1], &load[2]) != 3)
        return 84;
    loadavg[0] = load[0];
    loadavg[1] = load[1];
    loadavg[2] = load[2];
    fclose(stream);
    free(load);
    return 0;
}

int starting_my_print_uptime(int uptime, int minutes,
    int number_of_user, double *loadavg)
{
    int hours = 0;

    if (uptime == 0){
        mvprintw(0, 15, "up  %i, %i users, load average: %lf, %lf, %lf",
            minutes, number_of_user, loadavg[0], loadavg[1], loadavg[2]);
        return -5;
    }
    hours = uptime % 24;
    uptime = (uptime - uptime % 24) / 24;
    if (uptime == 0){
        mvprintw(0, 15,
            "up  %i:%i, %i users, load average: %lf, %lf, %lf",
            hours, minutes, number_of_user, loadavg[0],
            loadavg[1], loadavg[2]);
        return -5;
    }
    return hours;
}

void my_print_uptime(int uptime, int minutes,
    int number_of_user, double *loadavg)
{
    int hours = 0;

    uptime = (uptime - uptime % 60) / 60;
    hours = starting_my_print_uptime(uptime, minutes,
        number_of_user, loadavg);
    if (hours == -5)
        return;
    uptime = (uptime - uptime % 24) / 24;
    if (hours == 0){
        mvprintw(0, 15,
            "up %i days, %i min, %i users, load average: %lf, %lf, %lf",
            uptime, minutes, number_of_user, loadavg[0],
            loadavg[1], loadavg[2]);
        return;
    }
    mvprintw(0, 15,
        "up %i days, %i:%i, %i users, load average: %lf, %lf, %lf",
        uptime, hours, minutes, number_of_user,
        loadavg[0], loadavg[1], loadavg[2]);
    return;
}

int number_of_users(void)
{
    int number_of_users = -1;
    FILE *stream = fopen("/var/run/utmp", "r");
    struct utmp user;

    if (stream == NULL)
        return -5;
    for (; fread((char *)&user, sizeof(user), 1, stream) == 1;)
        if (*user.ut_user && *user.ut_line && *user.ut_line != '~')
            number_of_users++;
    fclose(stream);
    return number_of_users;
}

int my_get_uptime(void)
{
    FILE *stream = fopen("/proc/uptime", "r");
    int uptime;
    int minutes = 0;
    int hours = 0;
    int number_of_user = 0;
    double *loadavg = malloc(sizeof(double) * 4);

    if (loadavg == NULL)
        return 84;
    number_of_user = number_of_users();
    if (stream == NULL || my_getloadavg(loadavg, 3) || number_of_user == -5)
        return 84;
    if (fscanf(stream, "%i", &uptime) != 1)
        return 84;
    fclose(stream);
    uptime = (uptime - uptime % 60) / 60;
    minutes = uptime % 60;
    my_print_uptime(uptime, minutes, number_of_user, loadavg);
    free(loadavg);
    return 0;
}
