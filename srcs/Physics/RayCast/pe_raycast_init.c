/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - init raycast
*/

#include <stdlib.h>
#include "Physics/Raycast/raycast.h"

pe_raycast_t *pe_raycast_init(pe_vec2f_t p1, pe_vec2f_t p2)
{
    pe_raycast_t *ray = malloc(sizeof(pe_raycast_t));

    ray->p1 = p1;
    ray->p2 = p2;
    ray->delta = pe_vec2f_operate(p2, p1, SUBSTRACT);
    ray->hit = 0;
    return ray;
}

void pe_raycast_destroy(pe_raycast_t *ray)
{
    free(ray);
}