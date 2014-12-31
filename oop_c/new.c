#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "new.h"

void* new(const void* type, ...)
{
  const size_t size = *(const size_t*)type;
  printf("size:[%d]\n",(int)size);
  void * p = calloc(1, size);

  assert(p);

  return p;
}


void delete(void* _item)
{
  free(_item);
}





