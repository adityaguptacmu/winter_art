#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "new.h"

int heap[MANY];

static void print_heap(void);

void* new(const void * type, ...)
{
  int* p; /* & heap[1..] --> our imaginary heap */

  // check for empty heap
  for(p = heap + 1; p < heap + MANY; ++p)
  {
    // if it is empty, break out
    if(!*p)
    {
      break;
    }
  }

  // make sure it is within heap
  assert(p < heap + MANY);
  assert(p > heap);

  *p = MANY;
  // print_heap();
  return p;
}


void delete(void* _item)
{
  int* item = _item;

  if(item)
  {
    assert(item > heap && item < heap + MANY);
    *item = 0;
  }

}

static void print_heap(void)
{
  int i = 0;
  for(i = 0; i<MANY; i++)
  {
    printf("[%p] - heap[%d]:[%d]\n",&heap[i],i,heap[i]);
  }
}









