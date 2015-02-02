#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <assert.h>
#include "stack_queue.h"


int main(int argc, char const *argv[])
{
  /* code */
  struct DLLHead *head = NULL;
  struct DLLHead_q *head_q = NULL;

  head = create_new_stack();
  head_q = create_new_queue();
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int e = 0;

  push(&head, &a);
  q_push(&head_q, &a);
  // printf("mid_element:[%d]\n",mid_element(head));
  push(&head, &b);
  q_push(&head_q, &b);
  // printf("mid_element:[%d]\n",mid_element(head));
  push(&head, &c);
  q_push(&head_q, &c);

  push(&head, &d);
  q_push(&head_q, &d);
  // printf("mid_element:[%d]\n",mid_element(head));
  push(&head, &e);
  q_push(&head_q, &e);
  // print_list("main", &head);
  // printf("mid_element:[%d]\n",mid_element(head));
  // printf("pop:[%d]\n",pop(&head));
  // printf("mid_element:[%d]\n",mid_element(head));
  // printf("pop:[%d]\n",pop(&head));
  // printf("mid_element:[%d]\n",mid_element(head));
  // printf("pop:[%d]\n",pop(&head));
  // printf("mid_element:[%d]\n",mid_element(head));
  // print_list("main2", &head);
  // printf("pop:[%d]\n",pop(&head));
  // printf("mid_element:[%d]\n",mid_element(head));
  // printf("pop:[%d]\n",pop(&head));
  // printf("pop_q:[%d]\n",q_pop(&head_q));
  // printf("pop_q:[%d]\n",q_pop(&head_q));
  // printf("pop_q:[%d]\n",q_pop(&head_q));
  // printf("pop_q:[%d]\n",q_pop(&head_q));
  // printf("pop_q:[%d]\n",q_pop(&head_q));
  // printf("pop_q:[%d]\n",q_pop(&head_q));
  // printf("mid_element:[%d]\n",mid_element(head));
  // printf("pop:[%d]\n",pop(&head));

  // printf("delete_middle:[%d]\n",delete_middle(&head));
  // printf("mid_element:[%d]\n",mid_element(head));
  print_list("main_s", &head);
  print_list_q("main_q", &head_q);

  return 0;
}

