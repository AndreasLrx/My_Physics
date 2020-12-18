/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - collision btwn 2 polygons
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

float find_axis_least_penetration(int *face_id, \
pe_fixture_t *a, pe_fixture_t *b)
{
    pe_polygon_shape_t *poly_a = &a->shape.shape.polygon;
    pe_polygon_shape_t *poly_b = &b->shape.shape.polygon;
    float bestDistance = -FLT_MAX;
    int bestIndex;
    pe_vec2f_t normal;
    pe_vec2f_t support;
    pe_vec2f_t vertex_world;
    pe_mat22_t mat;
    float penetration_dist;

    pe_mat22_transpose(&b->shape.mat_rot, &mat);
    for (int i = 0; i < poly_a->count; ++i) {
        normal = pe_mat22_get_rotated_point(&mat, \
        pe_mat22_get_rotated_point(&a->shape.mat_rot, poly_a->normals[i]));
        support = get_support_point(pe_vec2f_opposite(normal), \
        poly_b->vertices, poly_b->count);
        vertex_world = VEC2F_SUB(VEC2F_ADD(SHAPE_POS(a), \
        pe_mat22_get_rotated_point(&a->shape.mat_rot, \
        poly_a->vertices[i])), SHAPE_POS(b));
        pe_mat22_rotate_point(&mat, &vertex_world);
        penetration_dist = pe_vec2f_dot_product(normal, \
        VEC2F_SUB(support, vertex_world));
        if (penetration_dist > bestDistance) {
            bestDistance = penetration_dist;
            bestIndex = i;
        }
    }
    *face_id = bestIndex;
    return bestDistance;
}

static void find_incident_angle(pe_vec2f_t *face_vertices, \
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
    face_vertices[0] = VEC2F_ADD(pe_mat22_get_rotated_point(\
    &inc->shape.mat_rot, inc->shape.shape.polygon.vertices[inc_face]), \
    SHAPE_POS(inc));
    inc_face = \
    ((inc_face + 1) >= inc->shape.shape.polygon.count) ? 0 : inc_face + 1;
    face_vertices[1] = VEC2F_ADD(pe_mat22_get_rotated_point(\
    &inc->shape.mat_rot, inc->shape.shape.polygon.vertices[inc_face]), \
    SHAPE_POS(inc));
}

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

static void handle_collide(pe_manifold_t *m, int ref_id, int flip)
{
    pe_shape_t *poly_a = &m->af->shape;
    pe_vec2f_t inc_face[2];
    pe_vec2f_t ref_face[2];
    pe_vec2f_t side_plane_normal;
    pe_vec2f_t ref_face_normal;
    float ref_c;
    float neg_side;
    float pos_side;
    int cp;
    float separation;
    int ref = ref_id;

    find_incident_angle(inc_face, m->af, m->bf, ref);
    ref_face[0] = VEC2F_ADD(pe_mat22_get_rotated_point(&poly_a->mat_rot, \
    poly_a->shape.polygon.vertices[ref]), SHAPE_POS(m->af));
    ref = (ref + 1 >= poly_a->shape.polygon.count) ? 0 : ref + 1;
    ref_face[1] = VEC2F_ADD(pe_mat22_get_rotated_point(&poly_a->mat_rot, \
    poly_a->shape.polygon.vertices[ref]), SHAPE_POS(m->af));
    side_plane_normal = VEC2F_SUB(ref_face[1], ref_face[0]);
    pe_vec2f_normalize(&side_plane_normal);
    ref_face_normal = VEC2F(side_plane_normal.y, - side_plane_normal.x);
    ref_c = pe_vec2f_dot_product(ref_face_normal, ref_face[0]);
    neg_side = -pe_vec2f_dot_product(side_plane_normal, ref_face[0]);
    pos_side = pe_vec2f_dot_product(side_plane_normal, ref_face[1]);
    if (clip_face(pe_vec2f_opposite(side_plane_normal), neg_side, inc_face) < 2)
        return;
    if (clip_face(side_plane_normal, pos_side, inc_face) < 2)
        return;
    m->normal = flip ? pe_vec2f_opposite(ref_face_normal) : ref_face_normal;
    cp = 0;
    separation = pe_vec2f_dot_product(ref_face_normal, inc_face[0]) - ref_c;
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