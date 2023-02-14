/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdlib.h>
#include "point.h"
#include "new.h"

typedef struct {
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg((*args), int);
    this->y = va_arg((*args), int);
}

static void Point_dtor(PointClass *this)
{
    this->x = 0;
    this->y = 0;
    return;
}

static char *Point_str(PointClass *this)
{
    char *str = malloc(sizeof(char) * 15 + (10 * 2));

    snprintf(str, (15 + (10 * 2)),
        "<Point (%d, %d)>", this->x, this->y);
    return str;
}

static Object *Point_add(PointClass *p1, PointClass *p2)
{
    Object *ptr = NULL;

    if (!p1 || !p2)
        return NULL;
    ptr = new(Point, p1->x + p2->x, p1->y + p2->y);
    return (ptr);
}

static Object *Point_sub(PointClass *p1, PointClass *p2)
{
    Object *ptr = NULL;

    if (!p1 || !p2)
        return NULL;
    ptr = new(Point, p1->x - p2->x, p1->y - p2->y);
    return (ptr);
}

static const PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
