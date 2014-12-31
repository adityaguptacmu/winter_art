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
  printf("*Set:[%d]\n",*(const size_t*)Set);
  printf("*Object:[%d]\n",*(const size_t*)Object);
  printf("void* P_s = new(Set);\n");
  void* P_s = new(Set);
  printf("void* P_a = add(P_s, new(Object));\n");
  void* P_a = add(P_s, new(Object));
  printf("void* P_b = add(P_s, new(Object));\n");
  void* P_b = add(P_s, new(Object));
  printf("void* P_c = new(Object);\n");
  void* P_c = new(Object);

  add(P_s, P_c);
  // void* P_z = new(Set);
  // void* P_x = add(P_z, new(Object));

  if(contains(P_s, P_a) && contains(P_s, P_b))
    puts("ok");

  if(contains(P_s, P_c))
    puts("contains?");

  if(differ(P_a, add(P_s, P_a)))
    puts("differ?");

  if(contains(P_s, drop(P_s, P_a)))
    puts("drop?");

  delete(drop(P_s, P_b));
  delete(drop(P_s, P_c));

  return 0;
}