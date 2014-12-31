#ifndef NEW_H
#define NEW_H

#include "Object.h"
#include "Set.h"

static const size_t _Set = sizeof(struct Set);
static const size_t _Object = sizeof(struct Object);

static const void* Set = & _Set;
static const void* Object = & _Object;

void* new(const void * type, ...);
void delete(void * _item);

#endif