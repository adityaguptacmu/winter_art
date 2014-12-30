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

  void* P_s = new(Set);
  void* P_a = add(P_s, new(Object));
  void* P_b = add(P_s, new(Object));
  void* P_c = new(Object);
  add(P_s, P_c);

  printf("Hello World!\n");
  if (contains(P_s, P_a) && contains(P_s, P_b))
    puts("ok");

  printf("Hello World!\n");
  if (contains(P_s, P_c))
    puts("contains?");

  printf("Hello World!\n");
  if (differ(P_a, add(P_s, P_a)))
    puts("differ?");

  printf("Hello World!\n");
  if (contains(P_s, drop(P_s, P_a)))
    puts("drop?");

  printf("Hello World!\n");
  delete(drop(P_s, P_b));
  delete(drop(P_s, P_c));

  return 0;
}