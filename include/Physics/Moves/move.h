/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - force
*/

#ifndef PHYSICS_MOVE_H
#define PHYSICS_MOVE_H

#include "../Utils/utils.h"

enum MOVE_TYPE {FORCE, TORQUE, LINEAR_IMPULSE, ANGULAR_IMPULSE};

/*
** Units :
** Vec
**    - Force vector in N
**
** Point
**    - application point relative to top_left of body
** Steps left
**    - World step of the force effect
*/
typedef struct pe_force_t {
    pe_vec2f_t point;
    pe_vec2f_t vec;
    int steps_left;
} pe_force_t;

/*
** Units :
** Torque
**    - torque value in N.m
**
** Point
**    - application point relative to top_left of body
** Steps left
**    - World step of the force effect
*/
typedef struct pe_torque_t {
    float torque;
    int steps_left;
} pe_torque_t;

/*
** Units :
** Vec
**    - Impulse vector in N.s
**
** Point
**    - application point relative to top_left of body
*/
typedef struct pe_linear_impulse_t {
    pe_vec2f_t point;
    pe_vec2f_t vec;
} pe_linear_impulse_t;

/*
** Units :
** Impulse
**    - Impulse torque in N.m
*/
typedef struct pe_angular_impulse_t {
    float impulse;
} pe_angular_impulse_t;

typedef union pe_move_u {
    pe_force_t force;
    pe_torque_t torque;
    pe_linear_impulse_t linear_impulse;
    pe_angular_impulse_t angular_impulse;
} pe_move_u;

typedef struct pe_move_t {
    pe_move_u move;
    char move_type;
} pe_move_t;

#endif /* !PHYSICS_MOVE_H */