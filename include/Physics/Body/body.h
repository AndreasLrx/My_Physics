/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - Body
*/

#ifndef PHYSICS_BODY_H
#define PHYSICS_BODY_H

#include <stddef.h>
#include "../Utils/utils.h"
#include "../Shapes/aabb_shape.h"

enum BODY_TYPE {STATIC, DYNAMIC};

struct pe_move_t;
struct pe_fixture_t;

/*
** Units :
** Velocity
**    - linear m/s
**    - angular rad/s
** Pos
**    - meter
** Angle
**    - rad
** Mass
**    - kg
**
** Factors :
** Damping
**    -> [0, 1]
*/
typedef struct pe_body_t {
    char body_type;
    pe_vec2f_t pos;
    pe_vec2f_t velocity;
    pe_vec2f_t force;
    pe_aabb_t aabb;
    float linear_damping;
    float angle;
    float angular_velocity;
    float angular_damping;
    float mass;
    float inv_mass;
    size_t datas;
    char fixed_rotation;
    char enabled;
    struct pe_fixture_t **fixtures;
    struct pe_move_t **moves;
    int id;
} pe_body_t;

pe_body_t *pe_body_init(char body_type, int fixture_init_capacity, \
int moves_init_capacity);
void pe_body_add_fixture(pe_body_t *body, struct pe_fixture_t *fixture);
void pe_body_destroy(pe_body_t *body);

void pe_body_compute_aabb(pe_body_t *body);
void pe_body_compute_mass(pe_body_t *body, float add_mass, char compute_all);
void pe_body_compute_mass_inv(pe_body_t *body);
void pe_body_update(pe_body_t *body, float dt);
void pe_body_move(pe_body_t *body, pe_vec2f_t move);

void pe_body_clear_force(pe_body_t *body);
void pe_body_apply_force(pe_body_t *body, pe_vec2f_t force);

#endif /* !PHYSICS_BODY_H */