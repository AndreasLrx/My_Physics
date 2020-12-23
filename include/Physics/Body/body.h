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
#include "../MassData/mass_data.h"

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
    float torque;
    float angular_velocity;
    float angular_damping;
    pe_mass_data_t mass;
    size_t datas;
    char fixed_rotation;
    char enabled;
    char is_awake;
    char can_sleep;
    float motion;
    struct pe_fixture_t **fixtures;
    int id;
} pe_body_t;

pe_body_t *pe_body_init(char body_type, int fixture_init_capacity, \
int moves_init_capacity);
void pe_body_add_fixture(pe_body_t *body, struct pe_fixture_t *fixture);
void pe_body_destroy(pe_body_t *body);

void pe_body_compute_aabb(pe_body_t *body);
void pe_body_compute_mass_datas(pe_body_t *body);
pe_vec2f_t pe_body_com(pe_body_t *body, int to_world);
void pe_body_update(pe_body_t *body, float dt);

void pe_body_set_pos(pe_body_t *body, pe_vec2f_t pos);
void pe_body_move(pe_body_t *body, pe_vec2f_t move);

void pe_body_set_angle(pe_body_t *body, float rad_angle);
void pe_body_rotate(pe_body_t *body, float rad_angle);

void pe_body_integrate_forces(pe_body_t *body, float dt);
void pe_body_clear_forces(pe_body_t *body, int torque, int force, int all);
void pe_body_add_force(pe_body_t *body, pe_vec2f_t force);
void pe_body_add_torque(pe_body_t *body, float torque);

void pe_body_apply_impulse(pe_body_t *body, pe_vec2f_t impulse);
void pe_body_apply_impulse_on_point(pe_body_t *body, \
pe_vec2f_t impulse, pe_vec2f_t point);

void pe_body_try_sleep(pe_body_t *body, float dt);
void pe_body_set_awake(pe_body_t *body, char awake);

#endif /* !PHYSICS_BODY_H */