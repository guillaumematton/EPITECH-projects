/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** print help
*/

#include "include/my.h"

void print_help(void)
{
    my_putstr("Air traffic simulation panel\n");
    my_putstr("USAGE\n ./my_radar [OPTIONS] path_to_script\n");
    my_putstr("  path_to_script     The path to the script file.\n");
    my_putstr("OPTIONS\n -h               print the usage and quit.\n");
    my_putstr("USER INTERACTIONS (not implemented yet)\n");
    my_putstr(" 'L' key        enable/disable hitboxes and areas\n");
    my_putstr(" 'S' key        enable/disable sprites\n");
    my_putstr("Copyright\n");
    my_putstr("Music by music_for_video from Pixabay:\n");
    my_putstr("https://pixabay.com/music/elevator-music-elevator-");
    my_putstr("music-bossa-nova-background-music-version-60s-10900\n");
    return;
}
