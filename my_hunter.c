/*
** EPITECH PROJECT, 2023
** SAMY
** File description:
** MY_HUNTER
*/

#include "my.h"

void ouvrir(sfRenderWindow* window, sfSprite *playerSprite,
    sfVideoMode mode, int *counter)
{
    float player_x = 600.0;
    float player_y = 600.0;
    float playerSpeed = 15.0;
    sfEvent event;
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(window);
            sfFloatRect playerBounds = sfSprite_getGlobalBounds(playerSprite);

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft) {
            if (sfFloatRect_contains(&playerBounds, mousePos.x, mousePos.y)) {
                sfSprite_setColor(playerSprite, sfColor_fromRGBA(255, 255, 255, 0));
                (*counter)++;
                player_x += playerSpeed;
                if (player_x > mode.width) {
                    player_x = -40;
                    sfSprite_setColor(playerSprite, sfColor_fromRGBA(255, 255, 255, 255));
                }
            }
        }
    }
}

void position(sfRenderWindow* window, sfSprite *backgroundSprite, sfSprite *playerSprite, sfSprite *cursorSprite, sfText *counterText, float player_x, float player_y, float background_x, int counter)
{
    sfVideoMode mode = {1920, 1080, 32};
    float playerSpeed = 10.0;
    float backgroundSpeed = -5.0;
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }

    sfVector2i mousePos = sfMouse_getPositionRenderWindow(window);
    sfSprite_setPosition(cursorSprite, (sfVector2f){(float)mousePos.x, (float)mousePos.y});
    sfSprite_setPosition(playerSprite, (sfVector2f){player_x, player_y});
    sfSprite_setPosition(backgroundSprite, (sfVector2f){background_x, 0.0});

    sfRenderWindow_drawSprite(window, backgroundSprite, NULL);
    sfRenderWindow_drawSprite(window, playerSprite, NULL);
    sfRenderWindow_drawSprite(window, cursorSprite, NULL);

    char counterStr[32];
    counterStr[0] = 'S';
    counterStr[1] = 'C';
    counterStr[2] = 'O';
    counterStr[3] = 'R';
    counterStr[4] = 'E';
    counterStr[5] = ' ';
    counterStr[6] = ':';
    counterStr[7] = ' ';
    counterStr[8] = '0' + (counter / 100) % 10;
    counterStr[9] = '0' + (counter / 10) % 10;
    counterStr[10] = '0' + counter % 10;
    counterStr[11] = '\0';

    sfText_setString(counterText, counterStr);
    sfRenderWindow_drawText(window, counterText, NULL);

    sfRenderWindow_display(window);
}

int main(void)
{
    sfVideoMode mode = {1920,1125, 32};
    sfRenderWindow* window;
    sfTexture *texture = sfTexture_createFromFile("man.png", NULL);
    sfTexture *backgroundTexture = sfTexture_createFromFile("road.png", NULL);
    sfTexture *cursorTexture = sfTexture_createFromFile("viseur.png", NULL);
    sfSprite *backgroundSprite;
    sfSprite *playerSprite;
    sfSprite *cursorSprite;
    sfText *counterText;
    sfFont *font = sfFont_createFromFile("police.otf");

    float background_x = 0.0;

    float player_x = 600.0;
    float player_y = 600.0;
    float playerSpeed = 15.0;
    int totalFrames = 10;
    sfEvent event;
    int frameWidth = sfTexture_getSize(texture).x / totalFrames;
    int frameHeight = sfTexture_getSize(texture).y;

    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    playerSprite = sfSprite_create();
    sfSprite_setTexture(playerSprite, texture, sfTrue);
    backgroundSprite = sfSprite_create();
    sfSprite_setTexture(backgroundSprite, backgroundTexture, sfTrue);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    cursorSprite = sfSprite_create();
    sfSprite_setTexture(cursorSprite, cursorTexture, sfTrue);

    counterText = sfText_create();
    sfText_setFont(counterText, font);
    sfText_setCharacterSize(counterText, 20);
    sfText_setFillColor(counterText, sfWhite);

    sfIntRect frameRect = {0, 0, frameWidth, frameHeight};
    sfSprite_setTextureRect(playerSprite, frameRect);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfClock *clock = sfClock_create();
    sfTime elapsed = sfTime_Zero;
    sfTime interval = sfMilliseconds(10);

    int counter = 0;
    start();
    song();
    while (sfRenderWindow_isOpen(window)) {
        ouvrir(window, playerSprite, mode, &counter);
        elapsed = sfClock_getElapsedTime(clock);
        if (sfTime_asMilliseconds(elapsed) >= sfTime_asMilliseconds(interval)) {
            sfClock_restart(clock);
            frameRect.left += frameWidth;
            if (frameRect.left >= sfTexture_getSize(texture).x)
                frameRect.left = 0;
            sfSprite_setTextureRect(playerSprite, frameRect);
            player_x += playerSpeed;
            if (player_x > mode.width) {
                player_x = -40;
                sfSprite_setColor(playerSprite, sfColor_fromRGBA(255, 255, 255, 255));
            }
            if (background_x < -mode.width)
                background_x = 0.0;
        }

        position(window, backgroundSprite, playerSprite, cursorSprite, counterText, player_x, player_y, background_x, counter);
    }
detruire(playerSprite, texture, backgroundSprite, backgroundTexture, window, cursorSprite, clock, counterText);
    return 0;
}