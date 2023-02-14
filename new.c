/*
** EPITECH PROJECT, 2023
** new header rush2
** File description:
** new
*/

#include "new.h"

Object *new(const Class *class, ...)
{
    Object *ptr = NULL;
    va_list ap;

    if (!class)
        raise("Out of memory");
    va_start(ap, class);
    ptr = va_new(class, &ap);
    va_end(ap);
    return ptr;
}

void delete(Object *ptr)
{
    if (!ptr)
        raise ("Out of memory");
    if (((Class *)ptr))
        ((Class *)ptr)->__dtor__(ptr);
    free(ptr);
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *ptr = NULL;

    if (!class)
        raise("Out of memory");
    ptr = malloc(class->__size__);
    if (!ptr)
        raise("Out of memory");
    memcpy(ptr, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(ptr, ap);
    return ptr;
}
