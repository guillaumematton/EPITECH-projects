/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** my_hunter
*/

#include <unistd.h>
#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Window.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Types.h>
#include "include/framebuffer.h"
#include "include/my.h"
#include "include/struct.h"

static int manage_mouse_click(sfMouseButtonEvent *mouse,
    sfRenderWindow *window, sfVector2f *place)
{
    sfEvent event;
    sfTime time;

    time.microseconds = 150000;
    sfSleep(time);
    sfRenderWindow_pollEvent(window, &event);
    mouse->x = event.mouseButton.x;
    mouse->y = event.mouseButton.y;
    if (event.type == sfEvtMouseButtonReleased)
        if (place->x <= mouse->x && mouse->x <= place->x + (110) &&
            place->y <= mouse->y && mouse->y <= place->y + (110))
            return 1;
    return 0;
}

static int analyse_event(sfRenderWindow *window,
    sfEvent event, sfVector2f *place)
{
    sfMouseButtonEvent mouse;
    int rvalue;

    if (event.type == sfEvtMouseButtonPressed){
        mouse.button = event.mouseButton.button;
        if (mouse.button == sfMouseLeft){
            rvalue = manage_mouse_click(&mouse, window, place);
        }
        event.type = 0;
        mouse.button = 0;
    }
    return rvalue;
}

static sfSprite *create_sprite(sfRenderWindow *window, int offset)
{
    sfSprite *bird;
    sfTexture *texture;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;

    rect.top = 0;
    rect.left = offset;
    rect.width = 110;
    rect.height = 110;
    texture = sfTexture_createFromFile("ressources/bird.png", NULL);
    bird = sfSprite_create();
    sfSprite_setTexture(bird, texture, sfFalse);
    sfSprite_setTextureRect(bird, rect);
    return bird;
}

static int sprite_movement(sfRenderWindow *window,
    sfSprite *bird, sfVector2f place, values_t *values)
{
    sfVector2f scale = {0.8, 0.8};
    sfEvent event;

    sfRenderWindow_pollEvent(window, &event);
    sfSprite_scale(bird, scale);
    sfSprite_move(bird, place);
    sfRenderWindow_drawSprite(window, bird, NULL);
    if (analyse_event(window, event, &place) == 1){
        values->y = 100 + (int) (870.0 * rand() / (RAND_MAX + 1.0));
        values->score += 1;
        return 1;
    } else if (place.x >= 1880)
        return 2;
    return 0;
}

static int draw_sprite(sfRenderWindow *window, sfClock *clock,
    values_t *values)
{
    sfSprite *bird;
    sfTime time;
    sfVector2f place;
    int rvalue;

    time = sfClock_getElapsedTime(clock);
    if ((time.microseconds % 1000000) < 1000000 / 4)
        bird = create_sprite(window, 0);
    else if ((time.microseconds % 1000000) < 2000000 / 4 ||
        (time.microseconds % 1000000) >= 3000000 / 4)
        bird = create_sprite(window, 110);
    else
        bird = create_sprite(window, 220);
    place.y = values->y;
    place.x = (int) (time.microseconds * values->score / 100000);
    rvalue = sprite_movement(window, bird, place, values);
    return rvalue;
}

static void while_open_window(sfRenderWindow *window, sfSprite *sprite)
{
    sfEvent event;
    sfClock *clock;
    values_t values = {100 + (int) (970.0 * rand() / (RAND_MAX + 1.0)), 5};
    int rvalue;

    clock = sfClock_create();
    while (sfRenderWindow_isOpen(window)){
        sfRenderWindow_pollEvent(window, &event);
        if (event.type == sfEvtClosed)
            return;
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        rvalue = draw_sprite(window, clock, &values);
        if (rvalue == 1)
            sfClock_restart(clock);
        if (rvalue == 2)
            return;
        sfRenderWindow_display(window);
    }
}

static int set_music_and_sprite(sfRenderWindow *window, sfTexture *background)
{
    sfSprite *sprite;
    sfMusic *music;

    music = sfMusic_createFromFile("ressources/music.wav");
    if (!music)
        return 84;
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, 35);
    sprite = sfSprite_create();
    if (!sprite)
        return 84;
    sfMusic_play(music);
    sfSprite_setTexture(sprite, background, sfTrue);
    while_open_window(window, sprite);
    sfRenderWindow_close(window);
    sfSprite_destroy(sprite);
    sfMusic_stop(music);
    sfMusic_destroy(music);
    return 0;
}

static int set_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfTexture *background;
    int err;

    window = sfRenderWindow_create(mode, "my_Hunter",
        sfClose | sfFullscreen, NULL);
    if (!window)
        return 84;
    sfRenderWindow_setVerticalSyncEnabled(window, sfTrue);
    background = sfTexture_createFromFile("ressources/forest.jpg", NULL);
    if (!background)
        return 84;
    err = set_music_and_sprite(window, background);
    sfTexture_destroy(background);
    sfRenderWindow_destroy(window);
    return err;
}

int main(int argc, char **argv)
{
    int err = 0;

    if (argc == 1){
        err = set_window();
        return err;
    } else if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0'){
        print_help();
        return 0;
    } else
        return 84;
}
