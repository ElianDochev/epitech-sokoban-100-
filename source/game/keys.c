/*
** EPITECH PROJECT, 2022
** my sokoban
** File description:
** movement function part one
*/

#include "main.h"
#include <ncurses.h>

int is_valid_key(int key)
{
    if (key == 'q')
        return key;
    if (key != ESACAPE_KEY)
        return -1;
    getch();
    key = getch();
    if (key >= 'A' && key <= 'D')
        return key;
    else
        return -1;
}

void try_move_left(game_t *g_obj)
{
    if (g_obj->map[g_obj->player_pos.y][g_obj->player_pos.x - 1] == '#')
        return;
    if (g_obj->map[g_obj->player_pos.y][g_obj->player_pos.x - 1] == ' ' ||
    g_obj->map[g_obj->player_pos.y][g_obj->player_pos.x - 1] == 'O') {
        g_obj->map[g_obj->player_pos.y][g_obj->player_pos.x] = ' ';
        g_obj->map[g_obj->player_pos.y][g_obj->player_pos.x - 1] = 'P';
        g_obj->player_pos.x = g_obj->player_pos.x - 1;
        return;
    }
    if (g_obj->map[g_obj->player_pos.y][g_obj->player_pos.x - 1] == 'X') {
        if (check_box(g_obj, g_obj->player_pos.y, g_obj->player_pos.x
        - 1, LEFT)) {
            g_obj->map[g_obj->player_pos.y][g_obj->player_pos.x] = ' ';
            g_obj->map[g_obj->player_pos.y][g_obj->player_pos.x - 1] = 'P';
            g_obj->player_pos.x = g_obj->player_pos.x - 1;
        }
        return;
    }
}

void try_move_right(game_t *g_obj)
{
    if (g_obj->map[g_obj->player_pos.y][g_obj->player_pos.x + 1] == '#')
        return;
    if (g_obj->map[g_obj->player_pos.y][g_obj->player_pos.x + 1] == ' ' ||
    g_obj->map[g_obj->player_pos.y][g_obj->player_pos.x + 1] == 'O') {
        g_obj->map[g_obj->player_pos.y][g_obj->player_pos.x] = ' ';
        g_obj->map[g_obj->player_pos.y][g_obj->player_pos.x + 1] = 'P';
        g_obj->player_pos.x = g_obj->player_pos.x + 1;
        return;
    }
    if (g_obj->map[g_obj->player_pos.y][g_obj->player_pos.x + 1] == 'X') {
        if (check_box(g_obj, g_obj->player_pos.y, g_obj->player_pos.x +
        1, RIGHT)) {
            g_obj->map[g_obj->player_pos.y][g_obj->player_pos.x] = ' ';
            g_obj->map[g_obj->player_pos.y][g_obj->player_pos.x + 1] = 'P';
            g_obj->player_pos.x = g_obj->player_pos.x + 1;
        }
        return;
    }
}

void try_move_up(game_t *g_obj)
{
    if (g_obj->map[g_obj->player_pos.y - 1][g_obj->player_pos.x] == '#')
        return;
    if (g_obj->map[g_obj->player_pos.y - 1][g_obj->player_pos.x] == ' ' ||
    g_obj->map[g_obj->player_pos.y - 1][g_obj->player_pos.x] == 'O') {
        g_obj->map[g_obj->player_pos.y][g_obj->player_pos.x] = ' ';
        g_obj->map[g_obj->player_pos.y - 1][g_obj->player_pos.x] = 'P';
        g_obj->player_pos.y = g_obj->player_pos.y - 1;
        return;
    }
    if (g_obj->map[g_obj->player_pos.y - 1][g_obj->player_pos.x] == 'X') {
        if (check_box(g_obj, g_obj->player_pos.y -
        1, g_obj->player_pos.x, UP)) {
            g_obj->map[g_obj->player_pos.y][g_obj->player_pos.x] = ' ';
            g_obj->map[g_obj->player_pos.y - 1][g_obj->player_pos.x] = 'P';
            g_obj->player_pos.y = g_obj->player_pos.y - 1;
        }
        return;
    }
}

void try_move_down(game_t *g_obj)
{
    if (g_obj->map[g_obj->player_pos.y + 1][g_obj->player_pos.x] == '#')
        return;
    if (g_obj->map[g_obj->player_pos.y + 1][g_obj->player_pos.x] == ' ' ||
    g_obj->map[g_obj->player_pos.y + 1][g_obj->player_pos.x] == 'O') {
        g_obj->map[g_obj->player_pos.y][g_obj->player_pos.x] = ' ';
        g_obj->map[g_obj->player_pos.y + 1][g_obj->player_pos.x] = 'P';
        g_obj->player_pos.y = g_obj->player_pos.y + 1;
        return;
    }
    if (g_obj->map[g_obj->player_pos.y + 1][g_obj->player_pos.x] == 'X') {
        if (check_box(g_obj, g_obj->player_pos.y +
        1, g_obj->player_pos.x, DOWN)) {
            g_obj->map[g_obj->player_pos.y][g_obj->player_pos.x] = ' ';
            g_obj->map[g_obj->player_pos.y + 1][g_obj->player_pos.x] = 'P';
            g_obj->player_pos.y = g_obj->player_pos.y + 1;
        }
        return;
    }
}
