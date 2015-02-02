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

struct DLLHead_q *create_new_queue(void)
{
  struct DLLHead_q *new_queue = NULL;
  new_queue = (struct DLLHead_q *)calloc(1,sizeof(struct DLLHead_q));
  assert(new_queue != NULL);
  new_queue->head = NULL;
  new_queue->tail = NULL;
  new_queue->count = 0;
  return new_queue;
}

void q_push(struct DLLHead_q **queue_head, data_t data)
{
  // check for argument
  assert(queue_head != NULL);
  struct DLLHead_q *queue = *queue_head;
  // check for argument
  assert(queue != NULL);
  struct DLLNode *temp = NULL;

  // create new node
  struct DLLNode *new_node = NULL;
  new_node = (struct DLLNode *)calloc(1,sizeof(struct DLLNode));
  assert(new_node != NULL);

  new_node->next = NULL;
  new_node->data = data;

  // add it to the end
  if(queue->count == 0)
  {
    new_node->prev = NULL;
    queue->tail = new_node;
    queue->head = new_node;
  }
  else
  {
    temp = queue->tail;
    temp->next = new_node;
    new_node->prev = temp;
    queue->tail = new_node;
  }

  // update the queue count
  queue->count += 1;
}

data_t q_pop(struct DLLHead_q **queue_head)
{
  // check for argument
  assert(queue_head != NULL);
  struct DLLHead_q *queue = *queue_head;
  // check for argument
  assert(queue != NULL);
  struct DLLNode *temp = NULL;

  data_t data = 0;

  if(queue->count == 0) {return (data_t)0;}

  if(queue->count == 1)
  {
    temp = queue->head;
    queue->tail = NULL;
    queue->head = NULL;
    data = temp->data;
  }
  else
  {
    temp = queue->head;
    queue->head = temp->next;
    temp->next->prev = NULL;
    data = temp->data;
  }

  // update the queue count
  free(temp);
  queue->count -= 1;
  return data;
}


data_t delete_middle(struct DLLHead **stack_head)
{
  struct DLLHead *stack = *stack_head;
  struct DLLNode *temp = NULL;
  data_t data = 0;

  assert(stack != NULL);

  if(stack->count == 0) return (data_t)0;

  temp = stack->mid;


  if(temp->prev != NULL)
  {
    temp->prev->next = temp->next;
  }

  if(temp->next != NULL)
  {
    temp->next->prev = temp->prev;
  }

  stack->count -= 1;

  if(stack->count != 0)
  {
    if((stack->count%2 != 0))
    {
      stack->mid = stack->mid->next;
    }
    else
    {
      stack->mid = stack->mid->prev;
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

data_t pop(struct DLLHead **stack_head)
{
  struct DLLHead *stack = *stack_head;
  struct DLLNode *temp = NULL;
  data_t data = 0;
  assert(stack_head != NULL);

  if(stack->head == NULL) return (data_t)0;

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

void push(struct DLLHead **stack_head, data_t data)
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

data_t mid_element(struct DLLHead *stack_head)
{
  assert(stack_head != NULL);

  struct DLLNode *temp_node = NULL;
  if(stack_head->count > 0)
  {
    temp_node = stack_head->mid;
    return (data_t)temp_node->data;
  }
  else
  {
    printf("Stack is empty\n");
  }

  return (data_t)0;
}

void print_list(char *to_print, struct DLLHead **stack_head)
{
  struct DLLHead *head_node = *stack_head;
  struct DLLNode *temp_node = head_node->head;

  printf("%s->",to_print);
  while(temp_node!= NULL)
  {
    printf("[%p]", (data_t)temp_node->data);
    temp_node = temp_node->next;
  }
  printf("\n");
}

void print_list_q(char *to_print, struct DLLHead_q **queue_head)
{
  struct DLLHead_q *head_node = *queue_head;
  struct DLLNode *temp_node = head_node->head;

  printf("%s->",to_print);
  while(temp_node!= NULL)
  {
    printf("[%p]", (data_t)temp_node->data);
    temp_node = temp_node->next;
  }
  printf("\n");
}

