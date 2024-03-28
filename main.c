/*
** EPITECH PROJECT, 2020
** B-CPE-200-PAR-2-1-matchstick-luca.guilliere
** File description:
** main.c
*/

#include "matchstick.h"

void aff_line(int spaces, int line, matchstick_t *game)
{
    int sticks = line * 2 + 1;
    my_putchar('*');
    for (int n = 0; n < spaces; ++n)
        my_putchar(' ');
    for (int n = 0; n < game->map[line]; ++n)
        my_putchar('|');
    for (int n = 0; n < spaces + (sticks - game->map[line]); ++n)
        my_putchar(' ');
    my_putchar('*');
    my_putchar('\n');
}

void print_map(matchstick_t *game)
{
    int nb_col = (game->size * 2) + 1;
    int line = 0;
    int spaces;
    for (int n = 0; n < nb_col; ++n)
        my_putchar('*');
    my_putchar('\n');
    while (line != game->size)
    {
        spaces = game->size - (line + 1);
        aff_line(spaces, line, game);
        ++line;
    }
    for (int n = 0; n < nb_col; ++n)
        my_putchar('*');
    my_putchar('\n');
}

int *load(int size)
{
    int line_tot = (size * 2) + 1;
    int *sticks = malloc(sizeof(int) * size + 1);
    for (int n = 0; n != size; ++n)
    {
        sticks[n] = n * 2 + 1;
    }
    return (sticks);
}

int game(int size, int max)
{
    srandom(time(0));
    errors_t err = {0, 0};
    matchstick_t game;
    game.size = size;
    game.max = max;
    game.turn = 1;
    game.map = load(size);
    print_map(&game);
    while (verifmap(&game) != 0)
    {
        if (turn(&game, &err) == 84){
            free(game.map);
            return 0;
        }
    }
    free(game.map);
    return (message(&game));
}

int main(int ac, char **av, char **env)
{

    int size;
    int max;

    if (errors(ac, av) == 84)
        return (84);
    size = my_getnbr(av[1]);
    max = my_getnbr(av[2]);
    if (size > 99)
        return 84;
    if (max <= 0)
        return 84;
    return (game(size, max));
}