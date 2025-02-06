/*
** EPITECH PROJECT, 2024
** main
** File description:
** main file
*/

#include "include/struct.h"
#include "include/my.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

static int following_of_find_square(square_t *po)
{
    for (int k = 0; k < po->size; k++){
        if (po->buffer[po->i + po->j * po->basenbr + k] != '.')
            return -1;
    }
    return 0;
}

static int find_square(char *buffer, int i, int basenbr)
{
    square_t po = {i, 0, buffer, basenbr, 0};
    int err = 0;

    if (buffer[i] == '.')
        po.size += 1;
    while (1){
        po.j = 0;
        for (; po.j < po.size && err == 0; po.j += 1)
            err = following_of_find_square(&po);
        if (err == -1)
            break;
        po.size += 1;
    }
    return po.size - 1;
}

static int compare_spot(int i, int basenbr, int max_i)
{
    int temp_i = (i / basenbr) * 1000;
    int temp_max_i = (max_i / basenbr) * 1000;

    if (temp_max_i % 1000 < temp_i % 1000)
        max_i = i;
    return max_i;
}

static void replace_square(char *buffer, int i, int size, int basenbr)
{
    int l = 0;
    int j = 0;

    for (int j = 0; j < size; j++)
        for (int k = 0; k < size; k++)
            buffer[i + (j * basenbr) + k] = 'x';
    if ('0' <= buffer[l] && buffer[l] <= '9'){
        for (; buffer[l] != '\n'; l++);
        l++;
    }
    for (; buffer[l] != '\0'; l++){
        buffer[j] = buffer[l];
        j++;
    }
    buffer[j] = '\0';
    my_putstr(buffer);
    return;
}

int compare_square(char *buffer, int basenbr)
{
    int size = 0;
    int max_i = 0;
    int newsize = 0;

    for (int i = 0; buffer[i] != '\0'; i++){
        newsize = find_square(buffer, i, basenbr);
        if (newsize == size && size != 0)
            max_i = compare_spot(i, basenbr, max_i);
        if (newsize > size){
            size = newsize;
            max_i = i;
        }
    }
    replace_square(buffer, max_i, size, basenbr);
}

static int compare_line(int i, int basenbr, char *buffer)
{
    int linenbr = 1;

    for (; buffer[i] != '\n'; i++){
        if (buffer[i] != '.' && buffer[i] != 'o')
            return -1;
        linenbr++;
    }
    if (linenbr != basenbr)
        return -1;
    return i;
}

static int reading_map(char *buffer, int length)
{
    long nbr = 0;
    long i = 0;
    long itemp;
    int basenbr = 1;

    buffer[length] = '\0';
    for (; '0' <= buffer[i] && buffer[i] <= '9'; i++){
        nbr *= 10;
        nbr += (buffer[i] - 48);
    }
    if (nbr == 0 || buffer[i] != '\n')
        return 84;
    itemp = i + 1;
    for (; buffer[itemp] != '\n'; itemp++)
        basenbr++;
    for (; buffer[i + 1] != '\0'; i = compare_line(i + 1, basenbr, buffer))
        if (i == -1)
            return 84;
    compare_square(buffer, basenbr);
    return 0;
}

static int checking_for_map(char *argv)
{
    int length = 0;
    char *buffer;
    int fd;
    int err;
    struct stat slen;

    stat(argv, &slen);
    length = slen.st_size;
    buffer = malloc(sizeof(char) * (length + 1));
    fd = open(argv, O_RDONLY);
    if (fd == -1 || buffer == NULL)
        return 84;
    err = read(fd, buffer, length);
    close(fd);
    if (err != length)
        return 84;
    err = reading_map(buffer, length);
    free(buffer);
    return err;
}

int main(int argc, char **argv)
{
    int length = 0;
    int nbr = my_getnbr(argv[1]);
    int rvalue = 0;
    struct stat po;
    int i = 0;

    if (argc > 3)
        return 84;
    if (stat(argv[1], &po) != 0){
        for (; '0' <= argv[1][i] && argv[1][i] <= '9'; i++);
        if (i != my_strlen(argv[1]) || argc != 3 || nbr > 3000)
            return 84;
        rvalue = self_made_map(nbr, argv[2]);
    } else
        rvalue = checking_for_map(argv[1]);
    return rvalue;
}
