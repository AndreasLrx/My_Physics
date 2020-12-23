/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physiscs constants
*/

#ifndef PHYSICS_CONSTANTS_H
#define PHYSICS_CONSTANTS_H

#define MIN(a, b) (((a) <= (b)) ? (a) : (b))
#define MAX(a, b) (((a) >= (b)) ? (a) : (b))
#define CLAMP(a, min, max) (MIN(MAX((a), min), max))
#define SIGN(a) (((a) >= 0) ? 1 : -1)
#define TO_RAD(a) ((a) * (PE_PI / 180.f))
#define TO_DEG(a) ((a) * (180 / PE_PI))
#define SHAPE_POS(fix) (VEC2F_ADD(fix->body->pos, fix->shape.pos))

extern const double PE_PI;
extern const float PE_POS_CORRECT_RATIO;
extern const float PE_CORRECTION_SLOP;
extern const float PE_EPSILON;
extern const float PE_SLEEP_EPSILON;

#endif /* !PHYSICS_CONSTANTS_H */