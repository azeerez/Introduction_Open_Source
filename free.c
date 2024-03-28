/*
** EPITECH PROJECT, 2020
** B-CPE-200-PAR-2-1-matchstick-luca.guilliere
** File description:
** free.c
*/

#include "matchstick.h"

void free_all(matchstick_t *matchstick)
{
    free(matchstick->map);
}