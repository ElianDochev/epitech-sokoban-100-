/*
** EPITECH PROJECT, 2022
** my sokoban
** File description:
** box funtions
*/

#include "main.h"

int move_box(game_t *g_obj, int_vector loc, int x_offset, int y_offset)
{
    if (g_obj->map[loc.y - y_offset][loc.x - x_offset] == '#')
        return 0;
    if (g_obj->map[loc.y - y_offset][loc.x - x_offset] == ' ' ||
    g_obj->map[loc.y - y_offset][loc.x - x_offset] == 'O') {
        g_obj->map[loc.y][loc.x] = ' ';
        g_obj->map[loc.y - y_offset][loc.x - x_offset] = 'X';
        return 1;
    }
    return 0;
}

int check_box(game_t *g_obj, int y, int x, directions dir)
{
    int y_offset = 0;
    int x_offset = 0;

    switch (dir) {
    case DOWN:
    y_offset = -1;
        break;
    case UP:
    y_offset = 1;
        break;
    case LEFT:
    x_offset = 1;
        break;
    case RIGHT:
    x_offset = -1;
        break;
    }
    return move_box(g_obj, create_ivector(x, y), x_offset, y_offset);
}
