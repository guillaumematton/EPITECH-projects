/*
** EPITECH PROJECT, 2025
** 105demography
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #define NULL  ((void *) 0)
    #include <stdio.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <math.h>

int manipulate_values(int *nbr_array);
int *get_nbrs(char *line, int i);

#endif /* !MY_H_ */
