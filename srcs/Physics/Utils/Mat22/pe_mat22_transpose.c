/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - matrix transposition
*/

#include "Physics/physics.h"

pe_mat22_t *pe_mat22_transpose(pe_mat22_t *src, pe_mat22_t *dest)
{
    pe_mat22_t *mat = dest;

    if (mat == NULL)
        mat = pe_mat22_init();
    mat->p00 = src->p00;
    mat->p01 = src->p10;
    mat->p10 = src->p01;
    mat->p11 = src->p11;
    return mat;
}