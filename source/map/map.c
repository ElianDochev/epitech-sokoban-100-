/*
** EPITECH PROJECT, 2022
** Sokoban
** File description:
** map and stuff
*/

#include "main.h"

static int is_valid_char(char ch)
{
    if (ch == ' ' || ch == '\n')
        return 0;
    if (ch == 'P' || ch == 'O')
        return 0;
    if (ch == '#' || ch == 'X')
        return 0;
    return 1;
}

static int check_content(char *content)
{
    for (size_t i = 0; content[i]; ++i) {
        if (is_valid_char(content[i])) {
            return 1;
        }
    }
    return 0;
}

static void fill_map(game_t *g_obj, int x, int y)
{
    switch (g_obj->map[y][x]) {
    case ('P') :
        g_obj->player_pos = create_ivector(x, y);
        return;
    case ('X') :
        ++g_obj->boxes_count;
        return;
    }
}

static void fill_boxes(game_t *g_obj)
{
    int index = 0;
    int i = 0;

    g_obj->o_locs = malloc(sizeof(int_vector) * g_obj->boxes_count);
        for (int j = 0; g_obj->map[i] && g_obj->map[i][j]; ++j) {
            if (g_obj->map[i][j] == 'O') {
                g_obj->o_locs[index] =  create_ivector(j, i);
                ++index;
            }
            if (g_obj->map[i][j + 1] == '\0') {
                ++i;
                j = 0;
            }
        }
}

game_t *check_map(char *path)
{
    game_t *g_obj = malloc(sizeof(game_t));
    char *content = open_file(path);

    if (content == NULL)
        return NULL;
    if (check_content(content)) {
        error("Incorrect map given\n");
        xfree((void **) &content);
        xfree((void **) &g_obj);
        return NULL;
    }
    g_obj->player_pos = create_ivector(0, 0);
    g_obj->boxes_count = 0;
    g_obj->map = split_str(content, endl_delim);
    for (int i = 0; g_obj->map[i]; ++i)
        for (int j = 0; g_obj->map[i][j]; ++j)
            fill_map(g_obj, j, i);
    fill_boxes(g_obj);
    return g_obj;
}
