/*
** EPITECH PROJECT, 2020
** My Physics
** File description:
** debug - update body shape pos
*/

#include "DebugDraw/debug_draw.h"

static void update_circle(pe_fixture_t *fix, sfCircleShape *circle, \
sfVertex *end_orientation)
{
    pe_mat22_t mat;
    pe_vec2f_t pos_vr = VEC2F(fix->shape.shape.circle.radius, 0);

    pe_mat22_init_from_angle(&mat, fix->body->angle);
    pe_mat22_rotate_point(&mat, &pos_vr);
    sfCircleShape_setPosition(circle, PE_TO_SF(VEC2F_MUL1\
    (VEC2F_SUB(SHAPE_POS(fix), \
    VEC2F_MUL1(fix->body->aabb.size, 0.5)), M_TO_PX)));
    end_orientation->position = PE_TO_SF(VEC2F_MUL1\
    (VEC2F_ADD(fix->body->pos, pos_vr), M_TO_PX));
}

static void update_poly(pe_fixture_t *fix, sfConvexShape *poly, \
sfVertex *end_orientation)
{
    pe_vec2f_t pos_v0 = VEC2F_SUB(fix->shape.shape.polygon.vertices[0], \
    fix->shape.pos);

    pe_mat22_rotate_point(&fix->shape.mat_rot, &pos_v0);
    sfConvexShape_setPosition(poly, \
    PE_TO_SF(VEC2F_MUL1(SHAPE_POS(fix), M_TO_PX)));
    sfConvexShape_setRotation(poly, TO_DEG(fix->body->angle));
    end_orientation->position = PE_TO_SF(VEC2F_MUL1(\
    VEC2F_ADD(fix->body->pos, pos_v0), M_TO_PX));
}

void sf_body_update(sf_body_t *body)
{
    size_t nb_fix = sf_boddy_nb_fixtures(body);
    int circle = 0;
    int poly = 0;

    sf_body_update_aabb(body);
    for (size_t i = 0; i < nb_fix; i++) {
        if (body->types[i] == CIRCLE) {
            update_circle(body->body->fixtures[i], \
            body->circles[circle++], &body->orientation_vertices[1]);
        } else {
            update_poly(body->body->fixtures[i], \
            body->polys[poly++], &body->orientation_vertices[1]);
        }
    }
}

void sf_body_update_vec(sf_body_t **vec)
{
    size_t nb_bodies = my_vector_get_size((size_t *)vec);

    for (size_t i = 0; i < nb_bodies; i++) {
        sf_body_update(vec[i]);
    }
}