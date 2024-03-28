/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-2-1-mydefender-doan.lai
** File description:
** screensaver.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "lib/my.h"

typedef struct {
    int *map;
    int max;
    int size;
    int turn;
    int sticks;
    int line;
} matchstick_t;

typedef struct {
    int rtrn;
    int err;
} errors_t;

int main(int ac, char **av, char **env);
int game(int size, int max);
int *load(int size);
void print_map(matchstick_t *game);
void aff_line(int spaces, int line, matchstick_t *game);

int errors(int ac, char **av);

int get_line(errors_t *err);

int turn(matchstick_t *game, errors_t *err);

void player(matchstick_t *game, errors_t *err);
void verif_rm(matchstick_t *game, errors_t *err);
void verif_remains(matchstick_t *game, errors_t *err);
void verif_sticks(matchstick_t *game, errors_t *err);
void verif_line(matchstick_t *game, errors_t *err);

int verifmap(matchstick_t *game);

void ai(matchstick_t *game, errors_t *err);
void verif_ia(matchstick_t *game, errors_t *err);
void verif_remains_ia(matchstick_t *game, errors_t *err);
void verif_sticks_ia(matchstick_t *game, errors_t *err);
void verif_line_ia(matchstick_t *game, errors_t *err);

int message(matchstick_t *game);

#endif