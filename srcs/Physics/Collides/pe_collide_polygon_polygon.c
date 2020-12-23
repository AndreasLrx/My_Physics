/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - collision btwn 2 polygons
*/

#include <float.h>
#include "Physics/physics.h"

static int clip_face(pe_vec2f_t normal, float c, pe_vec2f_t *face)
{
    int separation = 0;
    pe_vec2f_t out[2] = {face[0], face[1]};
    float alpha;
    float distances[2] = {pe_vec2f_dot_product(normal, face[0]) - c, \
        pe_vec2f_dot_product(normal, face[1]) - c};
    if (distances[0] <= 0.0f)
        out[separation++] = face[0];
    if (distances[1] <= 0.0f)
        out[separation++] = face[1];
    if (distances[0] * distances[1] < 0.0f) {
        alpha = distances[0] / (distances[0] - distances[1]);
        out[separation] = VEC2F_ADD(face[0], \
        VEC2F_MUL1(VEC2F_SUB(face[1], face[0]), alpha));
        separation++;
    }
    face[0] = out[0];
    face[1] = out[1];
    return separation;
}

static void fill_manifold(pe_manifold_t *m, pe_vec2f_t *inc_face, \
float ref_c, pe_vec2f_t ref_face_normal)
{
    int cp = 0;
    float separation = \
    pe_vec2f_dot_product(ref_face_normal, inc_face[0]) - ref_c;

    if (separation <= 0.0f) {
        m->contacts[cp] = inc_face[0];
        m->penetration = -separation;
        cp++;
    } else
        m->penetration = 0;
    separation = pe_vec2f_dot_product(ref_face_normal, inc_face[1]) - ref_c;
    if (separation <= 0.0f) {
        m->contacts[cp] = inc_face[1];
        m->penetration += -separation;
        cp++;
        m->penetration /= (float)cp;
    }
    m->nb_contacts = cp;
}

static void get_ref_face(pe_manifold_t *m, pe_vec2f_t *ref_face, \
int ref_id, pe_shape_t *poly_a)
{
    int ref = ref_id;

    ref_face[0] = VEC2F_ADD(pe_mat22_get_rotated_point(&poly_a->mat_rot, \
    poly_a->shape.polygon.vertices[ref]), SHAPE_POS(m->af));
    ref = (ref + 1 >= poly_a->shape.polygon.count) ? 0 : ref + 1;
    ref_face[1] = VEC2F_ADD(pe_mat22_get_rotated_point(&poly_a->mat_rot, \
    poly_a->shape.polygon.vertices[ref]), SHAPE_POS(m->af));
}

static void handle_collide(pe_manifold_t *m, int ref_id, int flip)
{
    pe_shape_t *poly_a = &m->af->shape;
    pe_vec2f_t inc_face[2];
    pe_vec2f_t ref_face[2];
    pe_vec2f_t side_plane_normal;
    pe_vec2f_t ref_face_normal;
    float infos[3];

    find_incident_angle(inc_face, m->af, m->bf, ref_id);
    get_ref_face(m, ref_face, ref_id, poly_a);
    side_plane_normal = VEC2F_SUB(ref_face[1], ref_face[0]);
    pe_vec2f_normalize(&side_plane_normal);
    ref_face_normal = VEC2F(side_plane_normal.y, - side_plane_normal.x);
    infos[0] = pe_vec2f_dot_product(ref_face_normal, ref_face[0]);
    infos[1] = -pe_vec2f_dot_product(side_plane_normal, ref_face[0]);
    infos[2] = pe_vec2f_dot_product(side_plane_normal, ref_face[1]);
    if (clip_face(pe_vec2f_opposite(side_plane_normal), infos[1], inc_face) < 2)
        return;
    if (clip_face(side_plane_normal, infos[2], inc_face) < 2)
        return;
    m->normal = flip ? pe_vec2f_opposite(ref_face_normal) : ref_face_normal;
    fill_manifold(m, inc_face, infos[0], ref_face_normal);
}

char pe_manifold_fill_polygon_polygon(pe_manifold_t *m)
{
    int faces[2];
    float penetrations[2] = {find_axis_least_penetration(&faces[0], \
        m->af, m->bf), 0};

    if (penetrations[0] >= 0)
        return 0;
    penetrations[1] = find_axis_least_penetration(&faces[1], m->bf, m->af);
    if (penetrations[1] >= 0)
        return 0;
    if (penetrations[0] >= penetrations[1]) {
        handle_collide(m, faces[0], 0);
    } else {
        pe_manifold_swap_bodies(m);
        handle_collide(m, faces[1], 1);
        pe_manifold_swap_bodies(m);
    }
    return 1;
}