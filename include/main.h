/*
** EPITECH PROJECT, 2022
** HEADER FILE
** File description:
** Main Header File
*/

#ifndef MAIN_H
    #define MAIN_H

    #include "utilities.h"

    #define ESACAPE_KEY 27
typedef enum {UP, DOWN, RIGHT, LEFT} directions;
typedef struct {
    char **map;
    int_vector player_pos;
    int boxes_count;
    int_vector *o_locs;
} game_t;
//checks the map and inits in the game_t object
game_t *check_map(char *path);
//runs the game
int game_on(game_t *g_obj);
//checks if the key pressed is an arrow key
int is_valid_key(int key);
//chechs if the game is over(win or lose) and set running acordingly
void check_game(game_t *g_obj, int *running);
//checks and moves the box X if possible in the direction
int check_box(game_t *g_obj, int y, int x, directions dir);
//tries to move the player to the left does nothing if it cant
void try_move_left(game_t *g_obj);
//tries to move the player to the right does nothing if it cant
void try_move_right(game_t *g_obj);
//tries to move the player to the up does nothing if it cant
void try_move_up(game_t *g_obj);
//tries to move the player to the down does nothing if it cant
void try_move_down(game_t *g_obj);
#endif
