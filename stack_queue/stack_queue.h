#ifndef STACK_QUEUE_H
#define STACK_QUEUE_H

typedef void* data_t;

struct DLLNode
{
  struct DLLNode *next;
  data_t data;
  struct DLLNode *prev;
};

struct DLLHead
{
  struct DLLNode *head;
  struct DLLNode *mid;
  struct DLLNode *tail;
  int count;
};

struct DLLHead_q
{
  struct DLLNode *head;
  struct DLLNode *tail;
  int count;
};

struct DLLHead *create_new_stack(void);
struct DLLHead_q *create_new_queue(void);

void q_push(struct DLLHead_q **queue_head, data_t data);
void print_list_q(char *to_print, struct DLLHead_q **queue_head);
data_t q_pop(struct DLLHead_q **queue_head);

void print_list(char *to_print, struct DLLHead **stack_head);
void push(struct DLLHead **stack_head, data_t data);
data_t mid_element(struct DLLHead *stack_head);
data_t pop(struct DLLHead **stack_head);
data_t delete_middle(struct DLLHead **stack_head);


#endif