/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - body init
*/

#include "Physics/physics.h"

static void pe_body_init_zeros(pe_body_t *body)
{
    body->pos = VEC2F(0, 0);
    body->velocity = VEC2F(0, 0);
    body->force = VEC2F(0, 0);
    body->linear_damping = 1;
    body->angle = 0;
    body->angular_velocity = 0;
    body->angular_damping = 1;
    body->datas = 0;
    body->fixed_rotation = 0;
    body->torque = 0;
}

pe_body_t *pe_body_init(char body_type, int fixture_init_capacity, \
int moves_init_capacity)
{
    pe_body_t *body = malloc(sizeof(pe_body_t));

    if (body == NULL)
        return NULL;
    pe_body_init_zeros(body);
    body->body_type = body_type;
    pe_mass_data_init(&body->mass, 0, 0, body_type);
    body->enabled = 1;
    pe_aabb_init(&body->aabb, VEC2F(0, 0), VEC2F(0, 0), 1);
    body->fixtures = (pe_fixture_t **)my_vector_init(\
    sizeof(pe_fixture_t *), fixture_init_capacity);
    return body;
}

void pe_body_add_fixture(pe_body_t *body, pe_fixture_t *fixture)
{
    pe_fixture_update_mass_datas(fixture);
    my_vector_push((size_t **)&body->fixtures, (size_t)fixture);
    fixture->body = body;
    fixture->shape.body_pos = &body->pos;
    pe_body_compute_mass(body, fixture->mass, fixture->shape.inertia, \
    my_vector_get_size((size_t *)body->fixtures) == 1);
    pe_aabb_union_shape(&body->aabb, &body->aabb, &fixture->shape, VEC2F(0, 0));
}