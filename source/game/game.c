/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** main game function
*/

#include "main.h"
#include <unistd.h>
#include <ncurses.h>

void print_map(game_t *g_obj)
{
    clear();
    for (int i = 0; g_obj->map[i]; ++i)
        printw("%s\n", g_obj->map[i]);
    refresh();
}

static void check_movement(game_t *g_obj, int *running)
{
    int key = -1;

    while ((key = is_valid_key(getch())) == -1);
    if (key == 'q')
        *running = 0;
    switch (key) {
    case 'A':
        try_move_up(g_obj);
        break;
    case 'B':
        try_move_down(g_obj);
        break;
    case 'C':
        try_move_right(g_obj);
        break;
    case 'D':
        try_move_left(g_obj);
        break;
    }
}

static void print_msg(char *msg)
{
    clear();
    printw(msg);
    refresh();
    usleep(2000000);
}

static void check_o(game_t *g_obj)
{
    for (int i = 0; i < g_obj->boxes_count; ++i) {
        if (g_obj->map[(g_obj->o_locs[i]).y][(g_obj->o_locs[i]).x]
        == ' ')
            g_obj->map[(g_obj->o_locs[i]).y][(g_obj->o_locs[i]).x] =
            'O';
    }
}

int game_on(game_t *g_obj)
{
    int running = 1;

    print_map(g_obj);
    while (running == 1) {
        check_movement(g_obj, &running);
        check_o(g_obj);
        move(0, 0);
        print_map(g_obj);
        check_game(g_obj, &running);
    }
    usleep(100000);
    endwin();
    for (int i = 0; g_obj->map[i]; ++i)
        xfree((void **) &g_obj->map[i]);
    xfree((void **) &g_obj->map);
    xfree((void **) &g_obj);
    return running;
}
