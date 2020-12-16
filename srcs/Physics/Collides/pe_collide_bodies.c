/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - search collide btwn 2 bodies (when aabb's overlap)
*/

#include "Physics/physics.h"

static void resolve_manifold(pe_manifold_t *m, int collided)
{
    if (!collided)
        return;
    pe_resolve_collision(m);
    pe_position_correction(m);
}

static int pe_fill_manifold(pe_manifold_t *m)
{
    return pe_collide_table[m->a->fixtures[m->fa]->shape.shape_type]\
        [m->b->fixtures[m->fb]->shape.shape_type](m);
}

void pe_collide_bodies(pe_body_t *b1, pe_body_t *b2, pe_manifold_t *m)
{
    size_t nb_fixtures_a = my_vector_get_size((size_t *)b1->fixtures);
    size_t nb_fixtures_b = my_vector_get_size((size_t *)b2->fixtures);
    int collide = 0;

    m->a = b1;
    m->b = b2;
    for (size_t i = 0; i < nb_fixtures_a; i++) {
        for (size_t j = 0; j < nb_fixtures_b; j++) {
            collide = 0;
            m->fa = i;
            m->fb = j;
            m->a = b1;
            m->b = b2;
            collide = pe_fill_manifold(m);
            resolve_manifold(m, collide);
        }
    }
}