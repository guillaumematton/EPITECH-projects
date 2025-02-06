/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

int my_get_uptime(void);
int get_nbr_proc(void);
int get_cpu_info(void);
int read_mem(void);
int read_swap(void);
double *get_mem_info(double *info, char *str, int i, int j);
int set_list_header(void);
void print_second_line(int total, int run, int stop, int zombie);
char *get_path(char *path, char *name, char *proc);

#endif /* !MY_H_ */
