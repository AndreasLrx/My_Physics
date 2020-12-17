/*
** EPITECH PROJECT, 2020
** My runnr
** File description:
** Physics - collisions
*/

#ifndef PHYSICS_COLLISIONS_H
#define PHYSICS_COLLISIONS_H

#include "./aabb_collides.h"
#include "./circle_collides.h"
#include "./manifold.h"

int pe_collide_get_collide_aabb_id(pe_bin_tree_t *tree, pe_body_t *body);
void pe_collide_body_from_parent(pe_bin_tree_t *tree, \
int parent_box_id, pe_body_t *body);
void pe_collide_bodies(pe_body_t *b1, pe_body_t *b2, pe_manifold_t *m);
void pe_resolve_collision(pe_manifold_t *m);
void pe_resolve_collision_rotate(pe_manifold_t *m);
void pe_position_correction(pe_manifold_t *m);

#endif /* !PHYSICS_COLLISIONS_H */