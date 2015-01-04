#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <assert.h>
#include "stack_queue.h"

struct DLLHead *create_new_stack(void)
{
  struct DLLHead * new_stack = NULL;
  new_stack = (struct DLLHead *)calloc(1,sizeof(struct DLLHead));
  new_stack->head = NULL;
  new_stack->mid = NULL;
  new_stack->tail = NULL;
  new_stack->count = 0;
  return new_stack;
}

int pop(struct DLLHead **stack_head)
{
  struct DLLHead *stack = *stack_head;
  struct DLLNode *temp = NULL;
  int data = 0;
  assert(stack_head != NULL);

  if(stack->head == NULL) return -1;

  temp = stack->head;
  stack->head = temp->next;
  stack->count -= 1;

  if(stack->count != 0)
  {
    if((stack->count%2 != 0) && (stack->mid->next != NULL))
    {
      stack->mid = stack->mid->next;
    }
  }
  else
  {
    stack->mid = NULL;
    stack->head = NULL;
    stack->tail = NULL;
  }

  data = temp->data;
  free(temp);
  assert(stack->count >= 0);
  return data;
}

void push(struct DLLHead **stack_head, int data)
{
  struct DLLHead *stack = *stack_head;

  // check if passed pointer is valid
  assert(stack != NULL);

  struct DLLNode * new_node = NULL;

  new_node = (struct DLLNode *)calloc(1, sizeof(struct DLLNode));

  // check if newly created pointer is valid
  assert(new_node != NULL);

  // add to the beginning
  new_node->next = stack->head;
  new_node->prev = NULL;
  new_node->data = data;

  if(new_node->next != NULL)
    stack->head->prev = new_node;

  stack->head = new_node;
  stack->count += 1;

  if(stack->count == 1)
  {
    stack->mid = new_node;
    stack->tail = new_node;
  }
  else
  {
    if((stack->count % 2 == 0) && (stack->mid != NULL))
    {
      stack->mid = stack->mid->prev;
    }
  }
}

int mid_element(struct DLLHead *stack_head)
{
  assert(stack_head != NULL);

  struct DLLNode *temp_node = NULL;
  if(stack_head->count > 0)
  {
    temp_node = stack_head->mid;
    return (int)temp_node->data;
  }
  else
  {
    printf("Stack is empty\n");
  }

  return -1;
}

void print_list(char *to_print, struct DLLHead **stack_head)
{
  struct DLLHead *head_node = *stack_head;
  struct DLLNode *temp_node = head_node->head;

  printf("%s->",to_print);
  while(temp_node!= NULL)
  {
    printf("[%d]", temp_node->data);
    temp_node = temp_node->next;
  }
  printf("\n");
}
