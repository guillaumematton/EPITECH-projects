/*
** EPITECH PROJECT, 2024
** my_ls
** File description:
** make ls
*/

#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "include/my.h"
#include "include/struct.h"

int read_file(char *path)
{
    int slash = 0;
    char *buf;

    for (int i = 0; i < my_strlen(path); i++)
        if (path[i] == '/' && path[i + 1] != '\0')
            slash = i + 1;
    buf = malloc(sizeof(char) * (my_strlen(path) - slash + 2));
    if (buf == NULL)
        return 84;
    for (int i = 0; slash < my_strlen(path); i++){
        buf[i] = path[slash];
        slash++;
    }
    my_putstr(buf);
    return 0;
}

static void prechecks_for_read_dir(int i, int nbfiles, char *path)
{
    if (i != 1)
        my_putchar('\n');
    if (nbfiles > 1)
        my_printf("%s:\n", path);
    return;
}

static int read_dir(char *path, params_t *po, int nbfiles, int i)
{
    struct dirent *dirbuf;
    DIR *directory;

    if (po->d == 1){
        read_d_dir(path, i, nbfiles);
        return 0;
    }
    prechecks_for_read_dir(i, nbfiles, path);
    directory = opendir(path);
    dirbuf = readdir(directory);
    if (dirbuf == NULL)
        return 84;
    for (; dirbuf != NULL; dirbuf = readdir(directory))
        if (po->a == 0 && dirbuf->d_name[0] != '.' || po->a == 1)
            my_printf("%s ", dirbuf->d_name);
    my_putchar('\n');
    closedir(directory);
    return 0;
}

static int read_standard_path(char *path, params_t *po, int nbfiles, int i)
{
    struct stat filetype;
    int err = 0;

    err = stat(path, &filetype);
    if (err != 0)
        return 84;
    if (S_ISDIR(filetype.st_mode) == 1){
        err = read_dir(path, po, nbfiles, i);
    } else {
        err = read_file(path);
        if (i != nbfiles)
            my_putstr(" ");
        else
            my_putchar('\n');
    }
    return err;
}

static int read_l_path(char *path, params_t *po, int nbfiles, int i)
{
    struct stat filetype;
    int err = 0;

    err = stat(path, &filetype);
    if (err != 0)
        return 84;
    if (S_ISDIR(filetype.st_mode) == 1)
        err = read_l_dir(path, po, nbfiles, i);
    else {
        err = read_l_file(path);
    }
    return err;
}

static int read_path(char *path, params_t *po, int nbfiles, int i)
{
    int err = 0;

    if (po->l == 0)
        err = read_standard_path(path, po, nbfiles, i);
    else
        err = read_l_path(path, po, nbfiles, i);
    return err;
}

static params_t *parameters_check(char argv, params_t *po)
{
    if (argv == 'l')
        po->l = 1;
    if (argv == 'a')
        po->a = 1;
    if (argv == 'd')
        po->d = 1;
    if (argv == 'R')
        po->R = 1;
    if (argv == 't')
        po->t = 1;
    if (argv == 'r')
        po->r = 1;
    return po;
}

int main(int argc, char **argv)
{
    params_t po = {0, 0, 0, 0, 0, 0};
    int err;
    int nbfile = 0;
    int noarg = 0;
    int i = 0;

    for (int j = 1; j < argc; j++){
        if (argv[j][0] != '-')
            nbfile++;
        for (int i = 1; i < my_strlen(argv[j]) && argv[j][0] == '-'; i++)
            parameters_check(argv[j][i], &po);
    }
    for (int j = 1; j < argc; j++)
        if (argv[j][0] != '-'){
            i++;
            err = read_path(argv[j], &po, nbfile, i);
        }
    if (nbfile == 0)
        err = read_path(".", &po, nbfile, 1);
    return err;
}
