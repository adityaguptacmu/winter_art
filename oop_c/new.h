#ifndef NEW_H
#define NEW_H

#include "Object.h"
#include "Set.h"

struct Class
{
  size_t size;
  void * (* ctor) (void * self, va_list * app);
  void * (* dtor) (void * self);
  void * (* clone) (const void * self);
  int (* differ) (const void * self, const void * b);
};

static const struct Class _String = {
  sizeof(struct String),
  String_ctor,
  String_dtor,
  String_clone,
  String_differ
};

static const size_t _Set = sizeof(struct Set);
static const size_t _Object = sizeof(struct Object);

static const void* Set = & _Set;
static const void* Object = & _Object;
static const void* String = & _String;


void* new(const void * type, ...);
void delete(void * _item);

#endif