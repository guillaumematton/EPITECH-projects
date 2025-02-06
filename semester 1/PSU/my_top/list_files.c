/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** list
*/

#include <dirent.h>
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>

char *get_proc_name(char *proc_name)
{
    int i = 0;

    for (int j = 6; proc_name[j] != '\0' && proc_name[j] != '\n'; j++){
        proc_name[i] = proc_name[j];
        i++;
    }
    proc_name[i] = '\0';
    return proc_name;
}

int read_info(int line, char *dirname, char *path)
{
    char *proc_name = malloc(sizeof(char) * 50);
    FILE *filename;
    char *status = malloc(sizeof(char) * 50);
    int end_of_line = 3;

    filename = fopen(path, "r");
    if (proc_name == NULL || status == NULL || filename == NULL)
        return 84;
    fgets(proc_name, 50, filename);
    for (int i = 0; proc_name[i] != '\0'; i++)
        if (proc_name[i] == '\n')
            end_of_line = 2;
    proc_name = get_proc_name(proc_name);
    for (int k = 0; k < end_of_line; k++)
        fgets(status, 50, filename);
    fclose(filename);
    mvprintw(line, 0, "%s %s %c", dirname, proc_name, status[7]);
    free(proc_name);
    free(status);
    return 0;
}

int temp(char *name, int line)
{
    char *path = malloc(sizeof(char) * (strlen(name) + 15));
    char proc[6] = "/proc/";
    int err = 0;

    if (path == NULL)
        return -5;
    for (int i = 0; i < 6; i++)
        path[i] = proc[i];
    strcat(path, name);
    strcat(path, "/status");
    err = read_info(line, name, path);
    free(path);
    return err;
}

int read_pid(void)
{
    DIR *directory = opendir("/proc");
    struct dirent *info;
    int line = 7;

    if (directory == NULL)
        return 84;
    info = readdir(directory);
    if (info == NULL)
        return 84;
    for (; info != NULL; info = readdir(directory)){
        if ('0' <= info->d_name[0] && info->d_name[0] <= '9'){
            temp(info->d_name, line);
            line++;
        }
    }
    closedir(directory);
    return 0;
}

int set_list_header(void)
{
    mvprintw(6, 0, "PID COMMAND S");
    if (read_pid() == 84)
        return 84;
    return 0;
}
