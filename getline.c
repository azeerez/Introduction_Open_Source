/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** getline.c
*/

#include "matchstick.h"

int get_line(errors_t *err)
{
    char *lines = NULL;
    size_t size = 0;
    int len;
    int p;

    err->rtrn = getline(&lines, &size, stdin);
    if (err->rtrn == -1){
        err->err = 84;
        return 84;
    }
    len = my_strlen(lines);
    if (size == 0)
        return 0;
    if (lines[len - 1] == '\n')
        (lines[len - 1] = '\0');
    p = my_getnbr(lines);
    free(lines);
    return p;
}