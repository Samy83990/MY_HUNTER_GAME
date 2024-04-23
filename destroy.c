/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myhunter-samy.chakrouni
** File description:
** destroy
*/

#include "my.h"

void detruire(sfSprite *playerSprite, sfTexture *texture, sfSprite *backgroundSprite, sfTexture *backgroundTexture, sfRenderWindow* window, sfSprite *cursorSprite, sfClock *clock, sfText *counterText)
{
    sfSprite_destroy(playerSprite);
    sfTexture_destroy(texture);
    sfSprite_destroy(backgroundSprite);
    sfTexture_destroy(backgroundTexture);
    sfRenderWindow_destroy(window);
    sfSprite_destroy(cursorSprite);
    sfClock_destroy(clock);
    sfText_destroy(counterText);
}