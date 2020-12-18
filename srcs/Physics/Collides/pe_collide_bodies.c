/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - search collide btwn 2 bodies (when aabb's overlap)
*/

#include "Physics/physics.h"

static void push_manifold(pe_manifold_t **m_vec, \
pe_manifold_t **m, int collided)
{
    if (!collided)
        return;
    //my_vector_push((size_t **)&m_vec, (size_t)*m);
    pe_manifold_init(*m, 0.005, VEC2F(0, 9.8));
    pe_resolve_collision_rotate(*m);
    pe_position_correction(*m);
    //*m = malloc(sizeof(pe_manifold_t));
}

static int pe_fill_manifold(pe_manifold_t *m)
{
    return pe_collide_table[m->af->shape.shape_type]\
        [m->bf->shape.shape_type](m);
}

void pe_collide_bodies(pe_body_t *b1, pe_body_t *b2, pe_manifold_t **m_vec)
{
    size_t nb_fixtures_a = my_vector_get_size((size_t *)b1->fixtures);
    size_t nb_fixtures_b = my_vector_get_size((size_t *)b2->fixtures);
    int collide = 0;
    pe_manifold_t *m = malloc(sizeof(pe_manifold_t));

    for (size_t i = 0; i < nb_fixtures_a; i++) {
        for (size_t j = 0; j < nb_fixtures_b; j++) {
            collide = 0;
            m->af = b1->fixtures[i];
            m->bf = b2->fixtures[j];
            m->nb_contacts = 0;
            collide = pe_fill_manifold(m);
            push_manifold(m_vec, &m, collide);
        }
    }
    free(m);
}