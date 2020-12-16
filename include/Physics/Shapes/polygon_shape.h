/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - polygon shape
*/

#ifndef PHYSICS_POLYGON_SHAPE_H
#define PHYSICS_POLYGON_SHAPE_H

#include "../Utils/utils.h"

struct pe_shape_t;

/*
** Units :
** Vertices
**    - position (in meter) relative to the top left of the body
*/
typedef struct pe_polygon_shape_t {
    int count;
    pe_vec2f_t *vertices;
    pe_vec2f_t *normals;
} pe_polygon_shape_t;

void pe_shape_init_polygon(struct pe_shape_t *shape, pe_vec2f_t pos, \
pe_vec2f_t *vertices, int nb_vertices);
void pe_shape_init_rect(struct pe_shape_t *shape, \
pe_vec2f_t pos, pe_vec2f_t size);

#endif /* !PHYSICS_POLYGON_SHAPE_H */