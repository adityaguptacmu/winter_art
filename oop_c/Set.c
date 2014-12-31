#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "new.h"
#include "Set.h"

void* add(void* _set, const void* _element)
{
  struct Set * set = _set;
  struct Object * element = (void *) _element;

  assert(set);
  assert(element);

  if (!element->in)
    element->in = set;
  else
    assert(element->in == set);

  ++element->count, ++set->count;

  printf("set->count:[%d]\n",set->count);
  printf("element->count:[%d]\n",element->count);
  return element;
}


void * find(const void * _set, const void * _element)
{
  const struct Object * element = _element;
  assert(_set);
  assert(element);
  return (element -> in == _set ? (void *) element : 0);
}

int contains(const void * _set, const void * _element)
{
  return find(_set, _element) != 0;
}

void * drop(void * _set, const void * _element)
{
  struct Set * set = _set;
  struct Object * element = find(set, _element);
  if(element)
  {
    if(--element->count == 0)
    {
      element->in = 0;
      --set->count;
    }
  }

  return element;
}

int differ(const void * a, const void * b)
{
  return a != b;
}

unsigned count(const void * _set)
{
  const struct Set * set = _set;
  assert(set);
  return set -> count;
}








