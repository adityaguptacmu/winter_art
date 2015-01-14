#include "linked_list.h"


linked_list *init_linked_list(int number_of_elements)
{
  linked_list *new_head = NULL;
  if((new_head = (linked_list*)malloc(sizeof(linked_list))) == NULL)
  {
    printf("Malloc Failed\n");
    return NULL;
  }

  new_head->max_elements = number_of_elements;
  new_head->elements = 0;
  new_head->head = NULL;
  new_head->tail = NULL;

  return new_head;
}

void Push_tail(linked_list **head_ref, int newData)
{
  linked_list *head = *head_ref;
  node *new_node = NULL;
  if((new_node = (node*)malloc(sizeof(node))) == NULL)
  {
    printf("Malloc Failed\n");
    return;
  }
  head->elements++;
  new_node->data = newData;
  new_node->next = NULL;

  if(head->tail != NULL)
  {
    head->tail->next = new_node;
  }

  if(head->head == NULL)
  {
    head->head = new_node;
  }

  head->tail = new_node;
}

void Push(linked_list **head_ref, int newData)
{
  linked_list *head = *head_ref;
  head->elements++;
  node *new_node = NULL;
  if((new_node = (node*)malloc(sizeof(node))) == NULL)
  {
    printf("Malloc Failed\n");
    return;
  }

  if(head->tail == NULL)
  {
    head->tail = new_node;
  }

  new_node->data = newData;
  new_node->next = head->head;
  head->head = new_node;
}

void print_list(linked_list *head_ref)
{
  node *current = head_ref->head;
  while(current != NULL)
  {
    printf("[%d]->",current->data);
    current = current->next;
  }
  printf("NULL\n");
}


int elements_list(linked_list *head_ref)
{
  return (head_ref->elements);
}

void delete_list(linked_list **head_ref)
{
  node *current = (*head_ref)->head;
  node *temp = current;
  while(current != NULL)
  {
    temp = current;
    current = current->next;
    free(temp);
  }

  (*head_ref)->head = NULL;
  (*head_ref)->tail = NULL;
  (*head_ref)->elements = 0;

}

