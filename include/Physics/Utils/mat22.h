/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - Rotation Matrix 2-2
*/

#ifndef PHYSICS_MATRIX_22_h
#define PHYSICS_MATRIX_22_h

#include "./vec2.h"

typedef struct pe_mat22_t {
    union {
        struct {
            float p00;
            float p01;
            float p10;
            float p11;
        };
        struct {
            pe_vec2f_t x_row;
            pe_vec2f_t y_row;
        };
    };
} pe_mat22_t;

pe_mat22_t *pe_mat22_init(void);
pe_mat22_t *pe_mat22_init_from_angle(pe_mat22_t *matrix, float rad_angle);
pe_mat22_t *pe_mat22_init_from_vec2(pe_mat22_t *matrix, \
pe_vec2f_t x_row, pe_vec2f_t y_row);

void pe_mat22_rotate(pe_mat22_t *mat, float rad_angle);
void pe_mat22_rotate_point(pe_mat22_t *mat, pe_vec2f_t *point);
pe_vec2f_t pe_mat22_get_rotated_point(pe_mat22_t *mat, pe_vec2f_t point);

pe_mat22_t *pe_mat22_transpose(pe_mat22_t *src, pe_mat22_t *dest);

void pe_mat22_display(pe_mat22_t *mat);

#endif /* !PHYSICS_MATRIX_22_h */