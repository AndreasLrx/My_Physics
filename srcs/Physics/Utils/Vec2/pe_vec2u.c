/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics vec2u
*/

#include "Physics/Utils/utils.h"

int pe_vec2u_cmp(pe_vec2u_t v1, pe_vec2u_t v2)
{
    return (v1.x == v2.x && v1.y == v2.y);
}