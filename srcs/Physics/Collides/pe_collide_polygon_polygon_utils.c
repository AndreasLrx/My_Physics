/*
** EPITECH PROJECT, 2020
** My runne
** File description:
** Physics - polygon/ polygon collision utils fcts
*/

#include <float.h>
#include "Physics/physics.h"

static void fill_face_vertices(pe_vec2f_t *face_vertices, \
pe_fixture_t *inc, int inc_face)
{
    face_vertices[0] = VEC2F_ADD(pe_mat22_get_rotated_point(\
    &inc->shape.mat_rot, inc->shape.shape.polygon.vertices[inc_face]), \
    SHAPE_POS(inc));
    inc_face = \
    ((inc_face + 1) >= inc->shape.shape.polygon.count) ? 0 : inc_face + 1;
    face_vertices[1] = VEC2F_ADD(pe_mat22_get_rotated_point(\
    &inc->shape.mat_rot, inc->shape.shape.polygon.vertices[inc_face]), \
    SHAPE_POS(inc));
}

void find_incident_angle(pe_vec2f_t *face_vertices, \
pe_fixture_t *ref, pe_fixture_t *inc, int ref_id)
{
    pe_vec2f_t referenceNormal = ref->shape.shape.polygon.normals[ref_id];
    pe_mat22_t mat;
    int inc_face = 0;
    float min_dot = FLT_MAX;
    float dot_res;

    pe_mat22_rotate_point(&ref->shape.mat_rot, &referenceNormal);
    pe_mat22_transpose(&inc->shape.mat_rot, &mat);
    pe_mat22_rotate_point(&mat, &referenceNormal);
    for (int i = 0; i < inc->shape.shape.polygon.count; i++) {
        dot_res = pe_vec2f_dot_product(referenceNormal, \
        inc->shape.shape.polygon.normals[i]);
        if (dot_res < min_dot) {
            min_dot = dot_res;
            inc_face = i;
        }
    }
    fill_face_vertices(face_vertices, inc, inc_face);
}