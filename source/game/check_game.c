/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** chechs for game over and win
*/

#include "main.h"
#include <ncurses.h>

//make a it so the array contains the location of all the O
void check_blocked(game_t *g_obj, int y, int x, int *block_boxes)
{
    int blocked = 0;

    if (g_obj->map[y][x - 1] == '#')
        ++blocked;
    if (g_obj->map[y][x + 1] == '#')
        ++blocked;
    if (g_obj->map[y - 1][x] == '#')
        ++blocked;
    if (g_obj->map[y + 1][x] == '#')
        ++blocked;
    if (blocked >= 2) {
        if (g_obj->map[y][x + 1] - g_obj->map[y][x - 1] == 0)
            return;
        if (g_obj->map[y - 1][x] - g_obj->map[y + 1][x] == 0)
            return;
        ++(*block_boxes);
    }
}

void check_game(game_t *g_obj, int *running)
{
    int i = 0;
    int destinations = 0;
    int block_boxes = 0;

    for (int i = 0; i < g_obj->boxes_count; ++i)
        if (g_obj->map[(g_obj->o_locs[i]).y][(g_obj->o_locs[i]).x] == 'X')
            ++destinations;
    for (int j = 0; g_obj->map[i] && g_obj->map[i][j]; ++j) {
        if (g_obj->map[i][j] == 'X')
            check_blocked(g_obj, i, j, &block_boxes);
        if (!g_obj->map[i][j+1]) {
            ++i;
            j = 0;
        }
    }
    if (destinations == g_obj->boxes_count)
        *running = 0;
    if (block_boxes == g_obj->boxes_count)
        *running = -1;
}