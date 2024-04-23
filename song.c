/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myhunter-samy.chakrouni
** File description:
** song
*/

#include "my.h"

int song(void)
{
    sfMusic *music;
    
    music = sfMusic_createFromFile("last.ogg");
        if (!music)
        return EXIT_FAILURE;
    sfMusic_play(music);
    return 0;    
}