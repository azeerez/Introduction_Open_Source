/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** message.c
*/

#include "matchstick.h"

int message(matchstick_t *game)
{
    if (game->turn == 0){
        write(1, "You lost, too bad...\n", 21);
        return (2);
    }
    if (game->turn == 1){
        write(1, "I lost... snif... but I'll get you next time!!\n", 47);
        return (1);
    }
}