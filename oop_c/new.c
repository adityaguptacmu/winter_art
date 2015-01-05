#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "new.h"

// void* new(const void* type, ...)
// {
//   const size_t size = *(const size_t*)type;
//   printf("size:[%d]\n",(int)size);
//   void * p = calloc(1, size);

//   assert(p);

//   return p;
// }

void * new (const void * _class, ...)
{
  const struct Class * class = _class; void * p = calloc(1, class -> size);
  assert(p);
  * (const struct Class **) p = class;
  if (class -> ctor)
  {
    va_list ap;
    va_start(ap, _class);
    p = class -> ctor(p, & ap); va_end(ap);
  }
  return p;
}


// void delete(void* _item)
// {
//   free(_item);
// }

void delete (void * self)
{
  const struct Class ** cp = self;
  if (self && * cp && (* cp) -> dtor)
    self = (* cp) -> dtor(self);
  free(self);
}




