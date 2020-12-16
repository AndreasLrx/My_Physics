/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - vec2 operands
*/

#include "Physics/Utils/utils.h"

pe_vec2f_t pe_vec2f_operate_one(pe_vec2f_t v1, float v, char operation)
{
    switch (operation) {
    case ADD:
        return (pe_vec2f_t){v1.x + v, v1.y + v};
    case SUBSTRACT:
        return (pe_vec2f_t){v1.x - v, v1.y - v};
    case MULTIPLY:
        return (pe_vec2f_t){v1.x * v, v1.y * v};
    case DIVIDE:
        return (pe_vec2f_t){v1.x / v, v1.y / v};
    case MODULO:
        return (pe_vec2f_t){v1.x + v, v1.y + v};
    default:
        return (pe_vec2f_t){0, 0};
    }
}

pe_vec2i_t pe_vec2i_operate_one(pe_vec2i_t v1, int v, char operation)
{
    switch (operation) {
    case ADD:
        return (pe_vec2i_t){v1.x + v, v1.y + v};
    case SUBSTRACT:
        return (pe_vec2i_t){v1.x - v, v1.y - v};
    case MULTIPLY:
        return (pe_vec2i_t){v1.x * v, v1.y * v};
    case DIVIDE:
        return (pe_vec2i_t){v1.x / v, v1.y / v};
    case MODULO:
        return (pe_vec2i_t){v1.x + v, v1.y + v};
    default:
        return (pe_vec2i_t){0, 0};
    }
}

pe_vec2u_t pe_vec2u_operate_one(pe_vec2u_t v1, unsigned int v, char operation)
{
    switch (operation) {
    case ADD:
        return (pe_vec2u_t){v1.x + v, v1.y + v};
    case SUBSTRACT:
        return (pe_vec2u_t){v1.x - v, v1.y - v};
    case MULTIPLY:
        return (pe_vec2u_t){v1.x * v, v1.y * v};
    case DIVIDE:
        return (pe_vec2u_t){v1.x / v, v1.y / v};
    case MODULO:
        return (pe_vec2u_t){v1.x + v, v1.y + v};
    default:
        return (pe_vec2u_t){0, 0};
    }
}