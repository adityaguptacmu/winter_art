#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>

#include "new.h"
#include "Set.h"
#include "Object.h"

int main(int argc, char const *argv[])
{
  printf("Hello World!\n");

  void * s = new(Set);
  void * a = add(s, new(Object));
  void * b = add(s, new(Object));
  void * c = new(Object);

  if (contains(s, a) && contains(s, b))
    puts("ok");

  if (contains(s, c))
    puts("contains?");

  if (differ(a, add(s, a)))
    puts("differ?");

  if (contains(s, drop(s, a)))
    puts("drop?");

  delete(drop(s, b));
  delete(drop(s, c));

  return 0;
}