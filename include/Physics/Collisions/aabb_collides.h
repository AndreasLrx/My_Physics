/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - aabb collisions fcts
*/

#ifndef PHYSICS_AABB_COLLISIONS_H
#define PHYSICS_AABB_COLLISIONS_H

struct pe_manifold_t;

char pe_fill_aabb_circle_manifold(struct pe_manifold_t *m);
char pe_fill_aabb_aabb_manifold(struct pe_manifold_t *m);

#endif /* !PHYSICS_AABB_COLLISIONS_H */