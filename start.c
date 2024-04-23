/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myhunter-samy.chakrouni
** File description:
** start
*/

#include "my.h"

void start()
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfEvent event;

    sfTexture *texture2 = sfTexture_createFromFile("start.png", NULL);
    sfSprite *button = sfSprite_create();

    sfVector2f scale_button = {5, 5};
    sfVector2f position_button = {500, 100};

    sfSprite_setTexture(button, texture2, sfTrue); 
    sfSprite_setScale(button, scale_button);
    sfSprite_setPosition(button, position_button);

    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);

    while (sfRenderWindow_isOpen(window))
    {
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            else if (event.type == sfEvtMouseButtonPressed)
            {
                sfVector2i mousePosition = sfMouse_getPositionRenderWindow(window);
                sfFloatRect buttonBounds = sfSprite_getGlobalBounds(button);

                if (sfFloatRect_contains(&buttonBounds, mousePosition.x, mousePosition.y))
                {
                    sfRenderWindow_close(window);
                }
            }
        }
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, button, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    sfTexture_destroy(texture2);
    sfSprite_destroy(button);
}