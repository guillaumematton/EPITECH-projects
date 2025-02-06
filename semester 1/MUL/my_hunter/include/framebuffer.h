/*
** EPITECH PROJECT, 2024
** framebuffer
** File description:
** framebuffer for bootstrap
*/

#ifndef FRAMEBUFFER_H_
    #define FRAMEBUFFER_H_
    #include <SFML/Graphics.h>

struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};
typedef struct framebuffer framebuffer_t;
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void framebuffer_destroy(framebuffer_t *framebuffer);
#endif    /* FRAMEBUFFER_H_ */
