#ifndef SET_H
#define SET_H

#include "new.h"
#include "Object.h"

struct Set
{
  const void * class; /* must be first */
  unsigned count;
};

void * add(void * _set, const void * _element);
void * drop(void * _set, const void * _element);
int contains(const void * _set, const void * _element);
int differ(const void * a, const void * b);
unsigned count(const void * _set);
size_t sizeOf(const void * self);

#endif