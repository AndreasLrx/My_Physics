/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - Collision jump table
*/

#ifndef PHYSICS_COLLISION_JUMP_TABLE_H
#define PHYSICS_COLLISION_JUMP_TABLE_H

struct pe_manifold_t;

extern const char (*pe_collide_table[2][2])(struct pe_manifold_t *);

#endif /* !PHYSICS_COLLISION_JUMP_TABLE_H */