#ifndef STACK_QUEUE_H
#define STACK_QUEUE_H

struct DLLNode
{
  struct DLLNode *next;
  int data;
  struct DLLNode *prev;
};

struct DLLHead
{
  struct DLLNode *head;
  struct DLLNode *mid;
  struct DLLNode *tail;
  int count;
};

struct DLLHead * create_new_stack(void);
void print_list(char *to_print, struct DLLHead **stack_head);
void push(struct DLLHead **stack_head, int data);
int mid_element(struct DLLHead *stack_head);
int pop(struct DLLHead **stack_head);
int delete_middle(struct DLLHead **stack_head);



#endif