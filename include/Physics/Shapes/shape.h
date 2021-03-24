/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - shape
*/

#ifndef PHYSICS_SHAPE_H
#define PHYSICS_SHAPE_H

#include "../Utils/utils.h"

#include "./circle_shape.h"
#include "./polygon_shape.h"
#include "./aabb_shape.h"

enum PE_SHAPE_TYPE {CIRCLE, POLYGON};

typedef union pe_shape_u{
    struct pe_circle_shape_t circle;
    struct pe_polygon_shape_t polygon;
} pe_shape_u;

/*
** Units :
** Area
**    - m²
** pos
**    - position (in meter) relative to top left of body
*/
typedef struct pe_shape_t {
    pe_mat22_t mat_rot;
    pe_shape_u shape;
    pe_vec2f_t pos;
    pe_vec2f_t *body_pos;
    int shape_type;
    float area;
    float inertia;
    pe_vec2f_t mass_center;
} pe_shape_t;

void pe_shape_init_default(pe_shape_t *shape);
float pe_shape_compute_mass_datas(pe_shape_t *shape, float density);
void pe_shape_reset(pe_shape_t *shape);


#endif /* !PHYSICS_SHAPE_H */