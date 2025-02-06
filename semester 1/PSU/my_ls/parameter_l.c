/*
** EPITECH PROJECT, 2024
** parameter l
** File description:
** if parameter l is called
*/

#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "include/my.h"
#include "include/struct.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>

static void printchmod(int nb1, int nb2, int nb3)
{
    if (nb1 == 1)
        my_putchar('r');
    else
        my_putchar('-');
    if (nb2 == 1)
        my_putchar('w');
    else
        my_putchar('-');
    if (nb3 == 1)
        my_putchar('x');
    else
        my_putchar('-');
    return;
}

static void readchmod(int octal)
{
    int nb1 = 0;
    int nb2 = 0;
    int nb3 = 0;

    nb3 = octal % 2;
    octal -= nb3;
    octal /= 2;
    nb2 = octal % 2;
    octal -= nb2;
    octal /= 2;
    nb1 = octal % 2;
    printchmod(nb1, nb2, nb3);
    return;
}

static int string_octal(int toconvert)
{
    char *oconvert;
    int i = 0;

    oconvert = malloc(sizeof(char) * 7);
    if (oconvert == NULL)
        return 84;
    for (; toconvert != 0; i++){
        oconvert[i] = toconvert % 8 + 48;
        toconvert -= toconvert % 8;
        toconvert /= 8;
    }
    oconvert[i] = '\0';
    oconvert = my_revstr(oconvert);
    for (int i = 3; i > 0; i--){
        readchmod(oconvert[my_strlen(oconvert) - i] - 48);
    }
    free(oconvert);
    my_putchar(' ');
    return 0;
}

static int print_ids(char *path)
{
    struct passwd *pwd;
    struct group *grp;
    struct stat fileinfo;

    if (stat(path, &fileinfo) != 0)
        return 84;
    pwd = getpwuid(fileinfo.st_uid);
    if (pwd == NULL)
        return 84;
    my_printf("%s ", pwd->pw_name);
    grp = getgrgid(fileinfo.st_gid);
    if (grp == NULL)
        return 84;
    my_printf("%s ", grp->gr_name);
    return 0;
}

static void print_first_character(struct stat *fileinfo)
{
    if (S_ISDIR(fileinfo->st_mode) == 1)
        my_putchar('d');
    else if (S_ISLNK(fileinfo->st_mode) == 1)
        my_putchar('l');
    else
        my_putchar('-');
    return;
}

static int print_modified_time(struct stat *fileinfo)
{
    char *time = ctime(&fileinfo->st_mtime);

    my_printf("%c%c%c ", time[4], time[5], time[6]);
    my_printf("%c%c ", time[8], time[9]);
    my_printf("%c%c%c%c%c ", time[11], time[12], time[13], time[14], time[15]);
    return 0;
}

int read_l_file(char *path)
{
    struct stat fileinfo;
    int err = 0;

    err = stat(path, &fileinfo);
    if (err != 0)
        return 84;
    print_first_character(&fileinfo);
    err = string_octal(fileinfo.st_mode);
    my_printf("%d ", fileinfo.st_nlink);
    err = print_ids(path);
    my_printf("%d ", fileinfo.st_size);
    err = print_modified_time(&fileinfo);
    my_printf("%s\n", path);
    return err;
}

int read_l_dir_file(char *path, struct dirent *dirbuf)
{
    struct stat fileinfo;
    int err = 0;
    char *full_path;

    full_path = malloc(sizeof(char) *
        (my_strlen(path) + my_strlen(dirbuf->d_name) + 3));
    full_path = find_full_path(path, dirbuf, full_path);
    err = stat(full_path, &fileinfo);
    if (err != 0)
        return 84;
    print_first_character(&fileinfo);
    err = string_octal(fileinfo.st_mode);
    my_printf("%d ", fileinfo.st_nlink);
    err = print_ids(full_path);
    my_printf("%d ", fileinfo.st_size);
    err = print_modified_time(&fileinfo);
    my_printf("%s\n", dirbuf->d_name);
    free(full_path);
    return err;
}

static int read_total(char *path, params_t *po)
{
    struct dirent *dirbuf;
    DIR *directory;
    int number_of_blocks = 0;

    directory = opendir(path);
    dirbuf = readdir(directory);
    if (dirbuf == NULL)
        return 84;
    for (; dirbuf != NULL; dirbuf = readdir(directory)){
        number_of_blocks += block_finder(path, dirbuf, po);
        if (number_of_blocks == -1)
            return 84;
    }
    my_printf("total %i\n", number_of_blocks / 2);
    closedir(directory);
    return 0;
}

int read_l_dir(char *path, params_t *po, int nbfiles, int i)
{
    int err = 0;

    if (po->d == 1){
        read_l_file(path);
        return 0;
    }
    if (i != 1)
        my_putchar('\n');
    if (nbfiles > 1)
        my_printf("%s:\n", path);
    if (read_total(path, po) == 84)
        return 84;
    err = helping_to_read_l(path, po);
    return err;
}
