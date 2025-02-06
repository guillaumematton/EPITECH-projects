/*
** EPITECH PROJECT, 2024
** organised
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct storage_s {
    char *type;
    char *name;
    int id;
    struct storage_s *next;
} storage_t;

#endif /* !STRUCT_H_ */
