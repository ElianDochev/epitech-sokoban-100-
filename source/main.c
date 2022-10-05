/*
** EPITECH PROJECT, 2022
** project name
** File description:
** main
*/

#include "main.h"
#include <ncurses.h>

int main (int ac, char **av)
{
    game_t *g_obj;

    if (ac >= 3 || ac != 2) {
        print_bad_args(ac, "my_sokoban", 1);
        return EXIT_ERR_EPI;
    }
    if (str_cmp(av[1], "-h") == 0) {
        print_help("./usage.txt");
        return 0;
    }
    g_obj = check_map(av[1]);
    if (g_obj == NULL)
        return EXIT_ERR_EPI;
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    return game_on(g_obj) == 0 ? 0 : 1;
}
