/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - raycast
*/

#ifndef PHYSICS_RAYCAST_H
#define PHYSICS_RAYCAST_H

#include "../Utils/utils.h"
#include "../Shapes/aabb_shape.h"

typedef struct pe_raycast_t {
    pe_vec2f_t p1;
    pe_vec2f_t p2;
    pe_vec2f_t delta;
    float time_hit;
    pe_vec2f_t collision_point;
    pe_vec2f_t normal;
    char hit;
} pe_raycast_t;

pe_raycast_t *pe_raycast_init(pe_vec2f_t p1, pe_vec2f_t p2);
void pe_raycast_destroy(pe_raycast_t *ray);

pe_raycast_t *pe_raycast_aabb(pe_aabb_t *box, pe_raycast_t *ray);
char pe_raycast_hit_aabb(pe_aabb_t *box, pe_vec2f_t p1, pe_vec2f_t p2);

#endif /* !PHYSICS_RAYCAST_H */