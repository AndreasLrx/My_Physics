/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - polygone circle collision
*/

#include <float.h>
#include "Physics/physics.h"

char pe_manifold_fill_circle_polygon(pe_manifold_t *m)
{
    pe_fixture_t *fix_a = m->a->fixtures[m->fa];
    pe_fixture_t *fix_b = m->b->fixtures[m->fb];
    pe_polygon_shape_t *poly = &fix_b->shape.shape.polygon;
    pe_mat22_t mat;
    pe_vec2f_t center = VEC2F_SUB(VEC2F_ADD(fix_a->body->pos, \
    fix_a->shape.pos), VEC2F_ADD(fix_b->body->pos, fix_b->shape.pos));
    float max_sep = -FLT_MAX;
    float sep;
    int normal_face = 0;
    float dot_products[2];
    pe_vec2f_t face_vertices[2];
    pe_vec2f_t normal;

    pe_mat22_transpose(&fix_b->shape.mat_rot, &mat);
    pe_mat22_rotate_point(&mat, &center);
    for (int i = 0; i < poly->count; ++i) {
        sep = pe_vec2f_dot_product(poly->normals[i], \
        VEC2F_SUB(center, poly->vertices[i]));
        if (sep > fix_a->shape.shape.circle.radius)
            return 0;
        if (sep > max_sep) {
            max_sep = sep;
            normal_face = i;
        }
    }
    face_vertices[0] = poly->vertices[normal_face];
    face_vertices[1] = poly->vertices[(normal_face + 1 <= poly->count) ? \
normal_face + 1 : 0];
    if (max_sep < PE_EPSILON) {
        //m->contact_count = 1;
        m->normal = pe_vec2f_opposite(pe_mat22_get_rotated_point(\
        &fix_b->shape.mat_rot, poly->normals[normal_face]));
        //m->contacts[0] = m->normal * A->radius + a->position;
        m->penetration = fix_a->shape.shape.circle.radius;
        return 1;
    }
    dot_products[0] = pe_vec2f_dot_product(VEC2F_SUB(center, \
    face_vertices[0]), VEC2F_SUB(face_vertices[1], face_vertices[0]));
    dot_products[1] = pe_vec2f_dot_product(VEC2F_SUB(center, \
    face_vertices[1]), VEC2F_SUB(face_vertices[0], face_vertices[1]));
    m->penetration = fix_a->shape.shape.circle.radius - max_sep;
    if (dot_products[0] <= 0.0f) {
        if (pe_vec2f_length_squared(VEC2F_SUB(face_vertices[0], \
            center)) > powf(fix_a->shape.shape.circle.radius, 2))
            return 0;
        //m->contact_count = 1;
        normal = VEC2F_SUB(face_vertices[0], center);
        pe_mat22_rotate_point(&fix_b->shape.mat_rot, &normal);
        pe_vec2f_normalize(&normal);
        m->normal = normal;
        pe_mat22_rotate_point(&fix_b->shape.mat_rot, &face_vertices[0]);
        face_vertices[0] = VEC2F_ADD(face_vertices[0], fix_b->body->pos);
        //m->contacts[0] = face_vertices[0];
    } else if (dot_products[1] <= 0.0f) {
        if (pe_vec2f_length_squared(VEC2F_SUB(face_vertices[1], \
            center)) > powf(fix_a->shape.shape.circle.radius, 2))
            return 0;
        //m->contact_count = 1;
        normal = VEC2F_SUB(face_vertices[1], center);
        pe_mat22_rotate_point(&fix_b->shape.mat_rot, &normal);
        pe_vec2f_normalize(&normal);
        m->normal = normal;
        pe_mat22_rotate_point(&fix_b->shape.mat_rot, &face_vertices[1]);
        face_vertices[1] = VEC2F_ADD(face_vertices[1], fix_b->body->pos);
        //m->contacts[0] = face_vertices[1];
    } else {
        normal = poly->normals[normal_face];
        if (pe_vec2f_dot_product(VEC2F_SUB(center, face_vertices[0]), \
            normal) > fix_a->shape.shape.circle.radius)
            return 0;
        pe_mat22_rotate_point(&fix_b->shape.mat_rot, &normal);
        m->normal = pe_vec2f_opposite(normal);
        /*m->contacts[0] = m->normal * fix_a->shape.shape.circle.radius + \
        fix_a->body->pos;
        m->contact_count = 1;*/
    }
    return 1;
}

char pe_manifold_fill_polygone_circle(pe_manifold_t *m)
{
    char res;

    pe_manifold_swap_bodies(m);
    res = pe_manifold_fill_circle_polygon(m);
    return res;
}