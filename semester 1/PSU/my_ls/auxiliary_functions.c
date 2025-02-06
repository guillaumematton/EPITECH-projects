/*
** EPITECH PROJECT, 2024
** auxiliary functions
** File description:
** fill in functions for other files
*/

#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "include/my.h"
#include "include/struct.h"

void read_d_dir(char *path, int i, int nbfiles)
{
    my_putstr(path);
    if (i != nbfiles)
        my_putchar(' ');
    else
        my_putchar('\n');
    return;
}

char *find_full_path(char *path, struct dirent *dirbuf, char *full_path)
{
    int i = 0;

    for (; path[i] != '\0'; i++)
        full_path[i] = path[i];
    if (path[i - 1] != '/'){
        full_path[i] = '/';
        i++;
    }
    for (int j = 0; dirbuf->d_name[j] != '\0'; j++){
        full_path[i] = dirbuf->d_name[j];
        i++;
    }
    full_path[i] = '\0';
    return full_path;
}

int block_finder(char *path, struct dirent *dirbuf, params_t *po)
{
    char *full_path;
    struct stat blockinfo;
    int number_of_blocks = 0;
    int pathlen = my_strlen(path);
    int namelen = my_strlen(dirbuf->d_name);

    if (po->a == 0 && dirbuf->d_name[0] != '.' || po->a == 1){
        full_path = malloc(sizeof(char) * (pathlen + namelen + 3));
        if (full_path == NULL)
            return -1;
        find_full_path(path, dirbuf, full_path);
        if (stat(full_path, &blockinfo) != 0)
            return -1;
        free(full_path);
        number_of_blocks += blockinfo.st_blocks;
    }
    return number_of_blocks;
}

int helping_to_read_l(char *path, params_t *po)
{
    struct dirent *dirbuf;
    DIR *directory;
    int err = 0;

    directory = opendir(path);
    dirbuf = readdir(directory);
    if (dirbuf == NULL)
        return 84;
    for (; dirbuf != NULL; dirbuf = readdir(directory))
        if (po->a == 0 && dirbuf->d_name[0] != '.' || po->a == 1)
            err = read_l_dir_file(path, dirbuf);
    closedir(directory);
}
