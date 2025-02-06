/*
** EPITECH PROJECT, 2024
** struct
** File description:
** struct
*/

#ifndef STRUCT_H
    #define STRUCT_H
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>

typedef struct values {
    int y;
    int score;
} values_t;

typedef struct word_array_s {
    char **word_array;
    int j;
    int itemp;
} array_t;

typedef struct tower_s {
    int x;
    int y;
    sfSprite *tower;
    int radius;
    struct tower_s *next;
} tower_t;

typedef struct airplane_s {
    int x;
    int y;
    int end_x;
    int end_y;
    double angle;
    struct airplane_s *next;
} airplane_t;

#endif /*STRUCT_H*/
