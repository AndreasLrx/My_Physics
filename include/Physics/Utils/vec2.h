/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - vec2
*/

#ifndef PHYSICS_VEC2_H
#define PHYSICS_VEC2_H

#include <stdint.h>
#include <stddef.h>

enum OPERATIONS {ADD, SUBSTRACT, MULTIPLY, DIVIDE, MODULO};

#define VEC2F(x, y) (pe_vec2f_t){x, y}
#define VEC2F_ADD(a, b) pe_vec2f_operate(a, b, ADD)
#define VEC2F_SUB(a, b) pe_vec2f_operate(a, b, SUBSTRACT)
#define VEC2F_MUL(a, b) pe_vec2f_operate(a, b, MULTIPLY)
#define VEC2F_DIV(a, b) pe_vec2f_operate(a, b, DIVIDE)
#define VEC2F_MOD(a, b) pe_vec2f_operate(a, b, MODULO)
#define VEC2F_ADD1(a, b) pe_vec2f_operate_one(a, b, ADD)
#define VEC2F_SUB1(a, b) pe_vec2f_operate_one(a, b, SUBSTRACT)
#define VEC2F_MUL1(a, b) pe_vec2f_operate_one(a, b, MULTIPLY)
#define VEC2F_DIV1(a, b) pe_vec2f_operate_one(a, b, DIVIDE)
#define VEC2F_MOD1(a, b) pe_vec2f_operate_one(a, b, MODULO)

typedef struct pe_vec2f_t {
    float x;
    float y;
} pe_vec2f_t;

typedef struct pe_vec2i_t {
    int32_t x;
    int32_t y;
} pe_vec2i_t;

typedef struct pe_vec2u_t {
    unsigned int x;
    unsigned int y;
} pe_vec2u_t;

int pe_vec2f_cmp(pe_vec2f_t v1, pe_vec2f_t v2);
int pe_vec2i_cmp(pe_vec2i_t v1, pe_vec2i_t v2);
int pe_vec2u_cmp(pe_vec2u_t v1, pe_vec2u_t v2);

float pe_vec2f_dot_product(pe_vec2f_t v1, pe_vec2f_t v2);
int pe_vec2i_dot_product(pe_vec2i_t v1, pe_vec2i_t v2);
unsigned int pe_vec2u_dot_product(pe_vec2u_t v1, pe_vec2u_t v2);

float pe_vec2f_cross_product_vec_vec(pe_vec2f_t v1, pe_vec2f_t v2);
pe_vec2f_t pe_vec2f_cross_product_vec_scalar(pe_vec2f_t v, float scalar);
pe_vec2f_t pe_vec2f_cross_product_scalar_vec(float scalar, pe_vec2f_t v);

pe_vec2f_t pe_vec2f_opposite(pe_vec2f_t v);
pe_vec2i_t pe_vec2i_opposite(pe_vec2i_t v);
pe_vec2u_t pe_vec2u_opposite(pe_vec2u_t v);

pe_vec2f_t pe_vec2f_operate(pe_vec2f_t v1, pe_vec2f_t v2, char operation);
pe_vec2i_t pe_vec2i_operate(pe_vec2i_t v1, pe_vec2i_t v2, char operation);
pe_vec2u_t pe_vec2u_operate(pe_vec2u_t v1, pe_vec2u_t v2, char operation);

pe_vec2f_t pe_vec2f_operate_one(pe_vec2f_t v1, float v, char operation);
pe_vec2i_t pe_vec2i_operate_one(pe_vec2i_t v1, int v, char operation);
pe_vec2u_t pe_vec2u_operate_one(pe_vec2u_t v1, unsigned int v, char operation);

float pe_vec2f_length_squared(pe_vec2f_t v);
int pe_vec2i_length_squared(pe_vec2i_t v);
unsigned int pe_vec2u_length_squared(pe_vec2u_t v);

float pe_vec2f_length(pe_vec2f_t v);
float pe_vec2i_length(pe_vec2i_t v);
float pe_vec2u_length(pe_vec2u_t v);

pe_vec2f_t *pe_vec2f_normalize(pe_vec2f_t *v);
pe_vec2i_t *pe_vec2i_normalize(pe_vec2i_t *v);
pe_vec2u_t *pe_vec2u_normalize(pe_vec2u_t *v);

long pe_vec2i_tol(pe_vec2i_t vec);

int pe_vec2i_map_cmp(size_t v1, size_t v2);

#endif /* !PHYSICS_VEC2_H */