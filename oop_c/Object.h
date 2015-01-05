#ifndef OBJECT_H
#define OBJECT_H

#include "new.h"
#include "Set.h"

static void * String_ctor(void * _self, va_list * app);
static void * String_dtor(void * _self);
static void * String_clone(const void * _self);
static int String_differ(const void * _self, const void * _b);

struct Object
{
  unsigned count;
  struct Set *in;
};

struct String
{
  const void* class; /* must be first */
  char* text;
};

#endif