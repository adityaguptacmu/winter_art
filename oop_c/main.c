#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>

#include "new.h"
#include "Set.h"
#include "Object.h"

typedef struct __test
{
   char c;
}test;


int main(int argc, char const *argv[])
{
  test new_test;
  printf("Hello World!\n");
  printf("%lu\n",sizeof(test));
  // printf("*Set:[%d]\n",*(const size_t*)Set);
  // printf("*Object:[%d]\n",*(const size_t*)Object);
  // printf("void* P_s = new(Set);\n");
  // void* P_s = new(Set);
  // printf("void* P_a = add(P_s, new(Object));\n");
  // void* P_a = add(P_s, new(Object));
  // printf("void* P_b = add(P_s, new(Object));\n");
  // void* P_b = add(P_s, new(Object));
  // printf("void* P_c = new(Object);\n");
  // void* P_c = new(Object);

  // add(P_s, P_c);
  // // void* P_z = new(Set);
  // // void* P_x = add(P_z, new(Object));

  // if(contains(P_s, P_a) && contains(P_s, P_b))
  //   puts("ok");

  // if(contains(P_s, P_c))
  //   puts("contains?");

  // if(differ(P_a, add(P_s, P_a)))
  //   puts("differ?");

  // if(contains(P_s, drop(P_s, P_a)))
  //   puts("drop?");

  // delete(drop(P_s, P_b));
  // delete(drop(P_s, P_c));

  void * a = new(String, "a"), * aa = clone(a);
  void * b = new(String, "b");
  printf("sizeOf(a) == %u\n", sizeof(a));
  if (differ(a, b))
    puts("ok");

  if (differ(a, aa)) puts("differ?");

  if (a == aa) puts("clone?");

  delete(a), delete(aa), delete(b);
  return 0;
}