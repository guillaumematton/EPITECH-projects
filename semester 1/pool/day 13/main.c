/*
** EPITECH PROJECT, 2024
** main
** File description:
** trying out stuff
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <SFML/Config.h>

void pixels(void)
{
    int width = 800;
    int height = 600;
    int bitsPerPixel;
    sfUint8 *pixels;

    pixels = malloc(width * height * bitsPerPixel / 8);
    pixels[0] = 255;
    pixels[1] = 0;
    pixels[2] = 0;
    pixels[3] = 255;
}

int main(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = 800;
    video_mode.height = 600;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "My Window",
        sfDefaultStyle, NULL);
    while (sfRenderWindow_isOpen(window)){
        sfRenderWindow_display(window);
        pixels();
    }
    sfRenderWindow_destroy(window);
    return 0;
}
