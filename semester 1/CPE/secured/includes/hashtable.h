/*
** EPITECH PROJECT, 2025
** Secured
** File description:
** hashtable
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H

    #define NULL ((void *)0)

typedef struct elements_s {
    int hashed;
    char *value;
    struct elements_s *next;
} elements_t;

typedef struct hashtable_s {
    int len;
    struct elements_s *data;
} hashtable_t;

int my_strlen(char const *str);
void my_putstr(char const *str);
void my_putchar(char c);
int my_put_nbr(int n);
int hash(char *key, int len);
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);
#endif /* HASHTABLE_H */
