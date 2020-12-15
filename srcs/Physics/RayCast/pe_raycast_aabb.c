/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - aabb raycast
*/

#include "Physics/Shapes/aabb_shape.h"
#include "Physics/Raycast/raycast.h"
#include "Physics/physics_constants.h"

pe_raycast_t *pe_raycast_aabb(pe_aabb_t *box, pe_raycast_t *ray)
{
    pe_vec2f_t h_size = VEC2F_MUL(box->size, VEC2F(0.5, 0.5));
    pe_vec2f_t scale = {1.0 /ray->delta.x, 1.0 / ray->delta.y};
    pe_vec2f_t signs = {SIGN(scale.x), SIGN(scale.y)};
    pe_vec2f_t near_times = {(box->min.x - signs.x * h_size.x - ray->p1.x) * \
        scale.x, (box->min.y - signs.y * h_size.y - ray->p1.y) * scale.y};
    pe_vec2f_t far_times = {(box->min.x + signs.x * h_size.x - ray->p1.x) * \
        scale.x, (box->min.y + signs.y * h_size.y - ray->p1.y) * scale.y};

    ray->hit = 0;
    if (near_times.x > far_times.y || near_times.y > far_times.x)
        return ray;
    if (MAX(near_times.x, near_times.y) >= 1 || \
        (MIN(far_times.x, far_times.y)) <= 0)
        return ray;
    ray->hit = 1;
    ray->time_hit = CLAMP(MAX(near_times.x, near_times.y), 0, 1);
    ray->normal.x = (near_times.x > near_times.y) ? -signs.x : 0;
    ray->normal.y = (near_times.x > near_times.y) ? 0 : -signs.y;
    ray->collision_point = VEC2F_ADD(ray->p1, \
    VEC2F_MUL(ray->delta, VEC2F(ray->time_hit, ray->time_hit)));
    return ray;
}

char pe_raycast_hit_aabb(pe_aabb_t *box, pe_vec2f_t p1, pe_vec2f_t p2)
{
    pe_raycast_t *ray = pe_raycast_init(p1, p2);
    char hit = 0;

    hit = pe_raycast_aabb(box, ray)->hit;
    pe_raycast_destroy(ray);
    return hit;
}