/*
** EPITECH PROJECT, 2025
** lib
** File description:
** lib
*/

#ifndef LIB_H_
    #define LIB_H_

typedef struct env_s {
    char *var;
    struct env_s *next;
} env_t;

int find_alphanum(char const *str);
void free_array(char **array);
void free_linked_list(env_t **env);
int my_arraycpy(char **env, char **tempenv);
double my_compute_power_rec(int nb, int p);
double my_compute_square_root(double nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_putchar(char c);
void my_puterr(char const *str);
int my_putstr(char const *str);
void my_rev_list(env_t **begin);
char *my_revstr(char *str);
int my_show_word_array(char *const *tab);
int my_str_isalphanum(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char **my_str_to_word_array(char *buffer);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
void my_strcpy_from_n(char *dest, char *src, int n);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);

#endif /* !LIB_H_ */
