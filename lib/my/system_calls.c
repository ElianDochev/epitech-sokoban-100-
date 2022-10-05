/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** free but safe
*/

#include "utilities.h"

void xfree(void **ptr)
{
    free(*ptr);
    *ptr = NULL;
}
