/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my lib
*/

#include <errno.h>
#include <stdarg.h>
#include "struct.h"
#include <dirent.h>
#ifndef MY_H
    #define MY_H

int case2(char *str, int precision);
int case1(int nb, int precision);
void switch_case_flag_1(int j, va_list *ap);
void switch_case_length_1(int j, va_list *ap);
int a_conv(double toconvert, int uporlow);
int upper_a_conv(void);
int errfonct(int l, int err);
int percn(int *adress, int l);
int mixscirou(double nbr, int uporlow, int precision);
int pconv(void *fake, int uporlow);
int science(double nbr, int uporlow, int precision);
int rounder(double nbr, int yesornoscience, int precision);
int octal(unsigned int toconvert, int precision);
int hexa(unsigned int toconvert, int uporlow, int precision);
int decimale(unsigned int toconvert, int precision);
int switch_case_conv_1(int tabvalue, va_list *ap, int precision);
int my_printf(const char *format, ...);
int functionafterperc(const char *format, int i, va_list *ap, int l);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
double my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
double my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_show_word_array(char *const *tab);
int overflow(long k);
int inr(int a, int b, int nb);
int pow1(int i);
int my_nbrlength(int nb);
int function(int nb);
int myif(int nb);
int condi(char const *s1, char const *s2, int i);
char *cond(char *str, int i);
int elsecond(char *str, char const *to_find, int loop);
int read_l_file(char *path);
int read_l_dir(char *path, params_t *po, int nbfiles, int i);
int helping_to_read_l(char *path, params_t *po);
int read_l_dir_file(char *path, struct dirent *dirbuf);
char *find_full_path(char *path, struct dirent *dirbuf, char *full_path);
int block_finder(char *path, struct dirent *dirbuf, params_t *po);
void read_d_dir(char *path, int i, int nbfiles);
int read_file(char *path);

#endif /*MY_H*/
