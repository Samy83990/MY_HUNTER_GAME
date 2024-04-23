/*
** EPITECH PROJECT, 2023
** Sans titre(Espace de travail)
** File description:
** my.h
*/

#ifndef MY_H_
    # define MY_H_
#include <SFML/Audio.h>
#include <SFML/Graphics.h> 
#include <math.h>
#include <stdlib.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/Rect.h>
int song(void);
void start(void);
void ouvrir(sfRenderWindow* window, sfSprite *playerSprite, sfVideoMode mode, int *counter);
void position(sfRenderWindow* window, sfSprite *backgroundSprite, sfSprite *playerSprite, sfSprite *cursorSprite, sfText *counterText, float player_x, float player_y, float background_x, int counter);
void detruire(sfSprite *playerSprite, sfTexture *texture, sfSprite *backgroundSprite, sfTexture *backgroundTexture, sfRenderWindow* window, sfSprite *cursorSprite, sfClock *clock, sfText *counterText);
#define sfCf sfTexture_createFromFile
#define sfWc sfRenderWindow_create

#endif
