/*
** EPITECH PROJECT, 2020
** My Physics
** File description:
** Debug draw main header
*/

#ifndef PHYSICS_DEBUG_HEAD_H
#define PHYSICS_DEBUG_HEAD_H

#define M_TO_PX 32

#include <SFML/Graphics.h>
#include "./body_draw.h"
#include "../Physics/physics.h"

#define PE_TO_SF(vec) ((sfVector2f){vec.x, vec.y})
#define SF_TO_PE(vec) ((pe_vec2f_t){vec.x, vec.y})

#endif /* !PHYSICS_DEBUG_HEAD_H */