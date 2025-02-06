/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "include/my.h"
#include <unistd.h>

int main(void)
{
    char buff[30000 + 1];
    int offset = 0;
    int len = read(0, buff, 30000 - offset);

    while (len > 0) {
        offset = offset + len;
        len = read(0, buff, 30000 - offset);
    }
    if (len < 0)
        return 84;
    return final_stumper(buff);
}
