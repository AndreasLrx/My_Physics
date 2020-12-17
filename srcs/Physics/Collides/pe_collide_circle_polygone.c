/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - polygone circle collision
*/

#include <float.h>
#include "Physics/physics.h"

static int circle_in_poly(pe_manifold_t *m, pe_polygon_shape_t *poly, \
int normal_face)
{
    m->nb_contacts = 1;
    m->normal = pe_vec2f_opposite(pe_mat22_get_rotated_point(\
    &m->bf->shape.mat_rot, poly->normals[normal_face]));
    m->contacts[0] = VEC2F_ADD(VEC2F_MUL1(m->normal, \
    m->af->shape.shape.circle.radius), SHAPE_POS(m->af));
    m->penetration = m->af->shape.shape.circle.radius;
    return 1;
}

static int get_face_normal(pe_manifold_t *m, pe_vec2f_t *face_vertices, \
pe_vec2f_t center, float *max_sep)
{
    pe_polygon_shape_t *poly = &m->bf->shape.shape.polygon;
    float sep;
    int normal_face = 0;

    for (int i = 0; i < poly->count; ++i) {
        sep = pe_vec2f_dot_product(poly->normals[i], \
        VEC2F_SUB(center, poly->vertices[i]));
        if (sep > m->af->shape.shape.circle.radius)
            return -1;
        if (sep > *max_sep) {
            *max_sep = sep;
            normal_face = i;
        }
    }
    face_vertices[0] = poly->vertices[normal_face];
    face_vertices[1] = poly->vertices[(normal_face + 1 < poly->count) ? \
normal_face + 1 : 0];
    if (*max_sep < PE_EPSILON)
        circle_in_poly(m, poly, normal_face);
    return (*max_sep < PE_EPSILON) ? -2 : normal_face;
}

static int vorioni_region(pe_manifold_t *m, pe_vec2f_t vertex, \
pe_vec2f_t center)
{
    pe_vec2f_t normal;

    m->nb_contacts = 1;
    normal = VEC2F_SUB(vertex, center);
    if (pe_vec2f_length_squared(normal) > \
        powf(m->af->shape.shape.circle.radius, 2))
        return 0;
    pe_mat22_rotate_point(&m->bf->shape.mat_rot, &normal);
    pe_vec2f_normalize(&normal);
    m->normal = normal;
    pe_mat22_rotate_point(&m->bf->shape.mat_rot, &vertex);
    vertex = VEC2F_ADD(vertex, SHAPE_POS(m->bf));
    m->contacts[0] = vertex;
    return 1;
}

static int dispatch_vorioni(pe_manifold_t *m, float dot_products[3], \
pe_vec2f_t face_vertices[2], pe_vec2f_t center)
{
    pe_vec2f_t normal;

    if (dot_products[0] <= 0.0f) {
        return vorioni_region(m, face_vertices[0], center);
    } else if (dot_products[1] <= 0.0f) {
        return vorioni_region(m, face_vertices[1], center);
    } else {
        normal = m->bf->shape.shape.polygon.normals[(int)dot_products[2]];
        if (pe_vec2f_dot_product(VEC2F_SUB(center, face_vertices[0]), \
            normal) > m->af->shape.shape.circle.radius)
            return 0;
        pe_mat22_rotate_point(&m->bf->shape.mat_rot, &normal);
        m->normal = pe_vec2f_opposite(normal);
        m->contacts[0] = VEC2F_ADD(VEC2F_MUL1(m->normal, \
        m->af->shape.shape.circle.radius), SHAPE_POS(m->af));
    }
    return 1;
}

char pe_manifold_fill_circle_polygon(pe_manifold_t *m)
{
    pe_mat22_t mat;
    pe_vec2f_t center = VEC2F_SUB(SHAPE_POS(m->af), SHAPE_POS(m->bf));
    float max_sep = -FLT_MAX;
    float dot_products[3];
    pe_vec2f_t face_vertices[2];

    pe_mat22_transpose(&m->bf->shape.mat_rot, &mat);
    pe_mat22_rotate_point(&mat, &center);
    dot_products[2] = get_face_normal(m, face_vertices, center, &max_sep);
    if (dot_products[2] < 0)
        return ((int)dot_products[2] == -2);
    dot_products[0] = pe_vec2f_dot_product(VEC2F_SUB(center, \
    face_vertices[0]), VEC2F_SUB(face_vertices[1], face_vertices[0]));
    dot_products[1] = pe_vec2f_dot_product(VEC2F_SUB(center, \
    face_vertices[1]), VEC2F_SUB(face_vertices[0], face_vertices[1]));
    m->penetration = m->af->shape.shape.circle.radius - max_sep;
    return dispatch_vorioni(m, dot_products, face_vertices, center);
}