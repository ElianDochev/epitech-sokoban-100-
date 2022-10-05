/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** creates i and f vectors
*/

#include "utilities.h"

int_vector create_ivector(int x, int y)
{
    int_vector vect = {x, y};

    return vect;
}

float_vector create_fvector(float x, float y)
{
    float_vector vect = {x, y};

    return vect;
}
