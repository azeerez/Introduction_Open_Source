/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** ai.c
*/

#include "matchstick.h"

void verif_line_ia(matchstick_t *game, errors_t *err)
{
    while (game->line > game->size){
        game->line = random() % game->size + 1;
        game->sticks = random() % game->max + 1;
    }
}

void verif_sticks_ia(matchstick_t *game, errors_t *err)
{
    while (game->sticks > game->max){
        game->line = random() % game->size + 1;
        game->sticks = random() % game->max + 1;
    }
}

void verif_remains_ia(matchstick_t *game, errors_t *err)
{
    while (game->map[game->line] < game->sticks){
        game->line = random() % game->size + 1;
        game->sticks = random() % game->max + 1;
    }
}

void verif_ia(matchstick_t *game, errors_t *err)
{
    verif_line_ia(game, err);
    verif_sticks_ia(game, err);
    verif_remains_ia(game, err);
    while (game->line > game->size ||
        game->sticks > game->max || game->map[game->line] < game->sticks)
        verif_ia(game, err);
}

void ai(matchstick_t *game, errors_t *err)
{
    write(1, "\n", 1);
    write(1, "AI's turn:\n", 11);
    game->sticks = random() % game->max + 1;
    game->line = random() % game->size + 1;
    verif_ia(game, err);
    write(1, "AI removed ", 11);
    my_put_nbr(game->sticks);
    write(1, " match(es) from line ", 21);
    my_put_nbr(game->line + 1);
    write(1, "\n", 1);
    game->map[game->line] = game->map[game->line] - game->sticks;
    game->turn = 1;
}