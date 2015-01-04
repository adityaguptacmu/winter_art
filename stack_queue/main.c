#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <assert.h>
#include "stack_queue.h"


int main(int argc, char const *argv[])
{
  /* code */
  struct DLLHead *head = NULL;
  head = create_new_stack();
  push(&head, 1);
  printf("mid_element:[%d]\n",mid_element(head));
  push(&head, 2);
  printf("mid_element:[%d]\n",mid_element(head));
  push(&head, 3);
  push(&head, 4);
  printf("mid_element:[%d]\n",mid_element(head));
  push(&head, 5);
  print_list("main", &head);
  printf("mid_element:[%d]\n",mid_element(head));


  printf("pop:[%d]\n",pop(&head));
  printf("mid_element:[%d]\n",mid_element(head));
  printf("pop:[%d]\n",pop(&head));
  printf("mid_element:[%d]\n",mid_element(head));
  printf("pop:[%d]\n",pop(&head));
  printf("mid_element:[%d]\n",mid_element(head));
  print_list("main2", &head);
  printf("pop:[%d]\n",pop(&head));
  printf("mid_element:[%d]\n",mid_element(head));
  printf("pop:[%d]\n",pop(&head));
  printf("mid_element:[%d]\n",mid_element(head));
  printf("pop:[%d]\n",pop(&head));



  return 0;
}

