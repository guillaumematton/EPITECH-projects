/*
** EPITECH PROJECT, 2024
** neutrinos
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include "struct.h"

void print_help(void);
void print_means(mean_t *mean);
void find_arithmetical_mean(mean_t *mean, int newvalue);
int in_loop(char *buffer, mean_t *mean);
int find_num_error(char *buffer);

#endif /* !MY_H_ */
