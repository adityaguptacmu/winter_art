#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct sll_node
{
  int data;
  struct sll_node *next;

}node;

typedef struct head_node
{
  int elements;
  node *head;
  node *tail;
  int max_elements;

}linked_list;


linked_list *init_linked_list(int number_of_elements);
void Push(linked_list **head, int newData);
void print_list(linked_list *head_ref);
void Push_tail(linked_list **head_ref, int newData);
int elements_list(linked_list *head_ref);
void delete_list(linked_list **head_ref);


#endif