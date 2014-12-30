#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#if !defined MANY || MANY < 1
#define MANY 10
#endif

static int heap[MANY];

void * new(const void * type, ...)
{
  int * p; /* & heap[1..] */

  for (p = heap + 1; p < heap + MANY; ++p)
  {
    if (! * p)
    {
      break;
    }
  }
  assert(p < heap + MANY);

  * p = MANY;

  return p;
}


void delete (void * _item)
{
  int * item = _item;

  if (item)
  {
    assert(item > heap && item < heap + MANY);
    * item = 0;
  }

}