/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** csfml_basics
*/

#include "include/my.h"
#include "include/struct.h"
#include "include/c_lib.h"

int set_towers(tower_t *tower_list, sfRenderWindow *window)
{
    sfVector2f place = {tower_list->x, tower_list->y};
    sfIntRect rect;
    sfSprite *tower = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(
        "ressources/tower.png", NULL);

    if (!tower || !texture)
        return 84;
    rect.top = 0;
    rect.left = 0;
    rect.width = 20;
    rect.height = 20;
    sfSprite_setTexture(tower, texture, sfFalse);
    sfSprite_setTextureRect(tower, rect);
    sfSprite_move(tower, place);
    sfRenderWindow_drawSprite(window, tower, NULL);
    tower_list->tower = tower;
    return 0;
}

int while_open_window(sfRenderWindow *window, sfSprite *background,
    tower_t **tower, airplane_t **airplane)
{
    sfEvent event;
    int rvalue;
    tower_t *tower_list;

    while (sfRenderWindow_isOpen(window)){
        sfRenderWindow_pollEvent(window, &event);
        if (event.type == sfEvtClosed)
            return 0;
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, background, NULL);
    }
}

int set_background(tower_t **tower, airplane_t **airplane,
    sfTexture *background, sfRenderWindow *window)
{
    sfSprite *sprite;
    sfMusic *music;
    int err = 0;

    music = sfMusic_createFromFile("ressources/music.wav");
    if (!music)
        return 84;
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, 25);
    sprite = sfSprite_create();
    if (!sprite)
        return 84;
    sfMusic_play(music);
    sfSprite_setTexture(sprite, background, sfTrue);
    err = while_open_window(window, sprite, tower, airplane);
    sfRenderWindow_close(window);
    sfSprite_destroy(sprite);
    sfMusic_stop(music);
    sfMusic_destroy(music);
    return err;
}

int set_window(tower_t **tower, airplane_t **airplane)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfTexture *background;
    int err = 0;

    window = sfRenderWindow_create(mode, "my_radar",
        sfClose, NULL);
    if (!window)
        return 84;
    sfRenderWindow_setVerticalSyncEnabled(window, sfTrue);
    background = sfTexture_createFromFile("ressources/map.png", NULL);
    if (!background)
        return 84;
    err = set_background(tower, airplane, background, window);
    sfTexture_destroy(background);
    sfRenderWindow_destroy(window);
    return err;
}
