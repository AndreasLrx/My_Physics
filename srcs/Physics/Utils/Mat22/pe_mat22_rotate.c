/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - Rotate point/vec from matrix
*/

#include "Physics/physics.h"

void pe_mat22_rotate(pe_mat22_t *mat, float rad_angle)
{
    float angle_cos = cosf(rad_angle);
    float angle_sin = sinf(rad_angle);
    float tempo = angle_cos;

    if (mat == NULL)
        return;
    angle_cos = mat->p00 * angle_cos - mat->p01 * angle_sin;
    angle_sin = mat->p01 * tempo + mat->p00 * angle_sin;
    mat->p00 = angle_cos;
    mat->p10 = -angle_sin;
    mat->p01 = angle_sin;
    mat->p11 = angle_cos;
}

void pe_mat22_rotate_point(pe_mat22_t *mat, pe_vec2f_t *point)
{
    float x_back;

    if (mat == NULL)
        return;
    x_back = point->x;
    point->x = mat->p00 * point->x + mat->p01 * point->y;
    point->y = mat->p10 * x_back + mat->p11 * point->y;
}

pe_vec2f_t pe_mat22_get_rotated_point(pe_mat22_t *mat, pe_vec2f_t point)
{
    pe_vec2f_t rotated_point = point;

    pe_mat22_rotate_point(mat, &rotated_point);
    return rotated_point;
}