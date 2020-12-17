/*
** EPITECH PROJECT, 2020
** My Physics
** File description:
** debug - init body
*/

#include "DebugDraw/debug_draw.h"

size_t sf_boddy_nb_fixtures(sf_body_t *body)
{
    return my_vector_get_size((size_t *)body->body->fixtures);
}

sf_body_t *sf_body_init(pe_body_t *body)
{
    sf_body_t *sf_body = malloc(sizeof(sf_body_t));

    sf_body->body = body;
    sf_body->circles = \
    (sfCircleShape **)my_vector_init(sizeof(sfCircleShape *), 3);
    sf_body->polys = \
    (sfConvexShape **)my_vector_init(sizeof(sfConvexShape *), 3);
    sf_body->aabb = sfRectangleShape_create();
    sf_body->types = (int *)my_vector_init(sizeof(int), 4);
    sfRectangleShape_setOutlineColor(sf_body->aabb, sfBlue);
    sfRectangleShape_setOutlineThickness(sf_body->aabb, 2);
    sfRectangleShape_setFillColor(sf_body->aabb, sfTransparent);
    sf_body->com = sfCircleShape_create();
    sfCircleShape_setFillColor(sf_body->com, sfBlue);
    sfCircleShape_setRadius(sf_body->com, 5);
    sf_body->orientation_vertices = malloc(sizeof(sfVertex) * 2);
    sf_body->orientation_vertices[0].color = sfBlack;
    sf_body->orientation_vertices[1].color = sfBlack;
    return sf_body;
}

void sf_body_update_aabb(sf_body_t *body)
{
    pe_mat22_t mat;
    pe_vec2f_t center = body->body->mass.center;

    pe_mat22_init_from_angle(&mat, body->body->angle);
    sfRectangleShape_setPosition(body->aabb, \
    PE_TO_SF(VEC2F_MUL1(body->body->aabb.min, M_TO_PX)));
    sfRectangleShape_setSize(body->aabb, \
    PE_TO_SF(VEC2F_MUL1(body->body->aabb.size, M_TO_PX)));
    pe_mat22_rotate_point(&mat, &center);
    center = VEC2F_MUL1(VEC2F_ADD(center, body->body->pos), M_TO_PX);
    sfCircleShape_setPosition(body->com, \
    PE_TO_SF(VEC2F_SUB(center, VEC2F(5, 5))));
    body->orientation_vertices[0].position = \
    PE_TO_SF(VEC2F_MUL1(body->body->pos, M_TO_PX));
}

void sf_body_add_circle(sf_body_t *body, pe_shape_t *shape)
{
    size_t nb_fix = sf_boddy_nb_fixtures(body);
    sfCircleShape *circle = sfCircleShape_create();
    pe_shape_t *circ_shape = &body->body->fixtures[nb_fix - 1]->shape;

    sfCircleShape_setRadius(circle, circ_shape->shape.circle.radius * M_TO_PX);
    sfCircleShape_setOutlineColor(circle, sfRed);
    sfCircleShape_setOutlineThickness(circle, -3);
    my_vector_push((size_t **)&body->circles, (size_t)circle);
    my_vector_push((size_t **)&body->types, (size_t)CIRCLE);
}

void sf_body_add_poly(sf_body_t *body, pe_shape_t *shape)
{
    size_t nb_fix = sf_boddy_nb_fixtures(body);
    sfConvexShape *poly = sfConvexShape_create();
    pe_shape_t *poly_shape = &body->body->fixtures[nb_fix - 1]->shape;
    pe_polygon_shape_t *polygon = &poly_shape->shape.polygon;
    pe_vec2f_t v;

    sfConvexShape_setOutlineColor(poly, sfGreen);
    sfConvexShape_setOutlineThickness(poly, -3);
    sfConvexShape_setPointCount(poly, polygon->count);
    for (int i = 0; i < polygon->count; i++) {
        v = polygon->vertices[i];
        sfConvexShape_setPoint(poly, i, PE_TO_SF(VEC2F_MUL1(v, M_TO_PX)));
    }
    my_vector_push((size_t **)&body->polys, (size_t)poly);
    my_vector_push((size_t **)&body->types, (size_t)POLYGON);
}