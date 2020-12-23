/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - find axis of least penetration (sat)
*/

#include <float.h>
#include "Physics/physics.h"

static pe_vec2f_t get_support_point(pe_vec2f_t dir, \
pe_vec2f_t *vertices, int count)
{
    float bestProjection = -FLT_MAX;
    pe_vec2f_t bestVertex;
    pe_vec2f_t vertex;
    float projection;

    for (int i = 0; i < count; ++i) {
        vertex = vertices[i];
        projection = pe_vec2f_dot_product(vertex, dir);
        if (projection > bestProjection) {
            bestVertex = vertex;
            bestProjection = projection;
        }
    }
    return bestVertex;
}

static float get_penetration_dist(pe_mat22_t *mat, \
pe_fixture_t *a, pe_fixture_t *b, int i)
{
    pe_polygon_shape_t *poly_a = &a->shape.shape.polygon;
    pe_polygon_shape_t *poly_b = &b->shape.shape.polygon;
    pe_vec2f_t normal = pe_mat22_get_rotated_point(mat, \
    pe_mat22_get_rotated_point(&a->shape.mat_rot, poly_a->normals[i]));
    pe_vec2f_t vertex_world = VEC2F_SUB(VEC2F_ADD(SHAPE_POS(a), \
    pe_mat22_get_rotated_point(&a->shape.mat_rot, \
    poly_a->vertices[i])), SHAPE_POS(b));
    pe_mat22_rotate_point(mat, &vertex_world);
    return pe_vec2f_dot_product(normal, \
        VEC2F_SUB(get_support_point(pe_vec2f_opposite(normal), \
        poly_b->vertices, poly_b->count), vertex_world));
}

float find_axis_least_penetration(int *face_id, \
pe_fixture_t *a, pe_fixture_t *b)
{
    pe_polygon_shape_t *poly_a = &a->shape.shape.polygon;
    float bestDistance = -FLT_MAX;
    int bestIndex;
    pe_mat22_t mat;
    float penetration_dist;

    pe_mat22_transpose(&b->shape.mat_rot, &mat);
    for (int i = 0; i < poly_a->count; ++i) {
        penetration_dist = get_penetration_dist(&mat, a, b, i);
        if (penetration_dist > bestDistance) {
            bestDistance = penetration_dist;
            bestIndex = i;
        }
    }
    *face_id = bestIndex;
    return bestDistance;
}