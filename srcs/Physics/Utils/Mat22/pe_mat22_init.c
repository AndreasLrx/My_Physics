/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - mat22 init
*/

#include "Physics/physics.h"

pe_mat22_t *pe_mat22_init(void)
{
    pe_mat22_t *mat = malloc(sizeof(pe_mat22_t));

    return mat;
}

pe_mat22_t *pe_mat22_init_from_angle(pe_mat22_t *matrix, float rad_angle)
{
    pe_mat22_t *mat = matrix;
    float cos_angle = cosf(rad_angle);
    float sin_angle = sinf(rad_angle);

    if (mat == NULL)
        mat = pe_mat22_init();
    mat->p00 = cos_angle;
    mat->p10 = -sin_angle;
    mat->p01 = sin_angle;
    mat->p11 = cos_angle;
    return mat;
}

pe_mat22_t *pe_mat22_init_from_vec2(pe_mat22_t *matrix, \
pe_vec2f_t x_row, pe_vec2f_t y_row)
{
    pe_mat22_t *mat = matrix;

    if (mat == NULL)
        mat = pe_mat22_init();
    mat->x_row = x_row;
    mat->y_row = y_row;
    return mat;
}

void pe_mat22_display(pe_mat22_t *mat)
{
    printf("Matrix 22 :\n%-5.4f  %-5.4f\n%-5.4f  %-5.4f\n", \
    mat->p00, mat->p10, mat->p01, mat->p11);
}