#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hash.h"

#define NO_ELEMENTS 5

struct node
{
  int data;
  struct node *next;
};

struct node *create_linked_list(void);
int free_linked_list(struct node* head_ptr);
void print_linked_list(char *to_print, struct node** head_ptr);
int Length(struct node *head);
void Push(struct node **head, int newData);
void sorted_insert(struct node **head, struct node *new_node);
void FrontBackSplit(struct node* source, struct node** forntRef, struct node** backRef);
void RemoveDuplicates(struct node* head);
int Pop(struct node** headRef);
void AlternatingSplit(struct node* source,struct node** aRef, struct node** bRef);
void MoveNode(struct node** destRef, struct node** sourceRef);
struct node* ShuffleMerge(struct node* a, struct node* b);
struct node* SortedMerge(struct node* a, struct node* b);
void MergeSort(struct node** headRef);
struct node* SortedIntersect(struct node* a, struct node* b);
void Reverse(struct node** headRef);
void RecursiveReverse(struct node** headRef);

int main(int argc, char const *argv[])
{
  struct node *head = NULL;
  // struct node *head_front = NULL;
  // struct node *head_back = NULL;
  // int retval = 0;

  head = create_linked_list();
  // Push(&head_front, 10);
  // Push(&head_front, 8);
  // Push(&head_front, 3);

  // Push(&head_back, 10);
  // Push(&head_back, 8);
  // Push(&head_back, 1);

  // retval = Pop(&head);
  // printf("[%d]\n",retval);

  // print_linked_list("head_front", &head_front);
  // print_linked_list("head_back", &head_back);

  // FrontBackSplit(head, &head_front, &head_back);
  // head = ShuffleMerge(head_back, head_front);
  // head = SortedMerge(head_back, head_front);
  // head = SortedIntersect(head_front, head_back);
  // MergeSort(&head);
  RecursiveReverse(&head);
  print_linked_list("head", &head);
  // AlternatingSplit(head,&head_front, &head_back);
  // free_linked_list(head_front);
  // free_linked_list(head_back);
  free_linked_list(head);

  return 0;
}


void RecursiveReverse(struct node** headRef)
{
  ;
}


void Reverse(struct node** headRef)
{
  struct node *result = NULL;
  struct node *current = *headRef;
  struct node *next = NULL;

  while(current != NULL)
  {
    next = current->next;
    current->next = result;
    result = current;
    current = next;
    print_linked_list("result", &result);
  }

  *headRef = result;
}

struct node* SortedIntersect(struct node* a, struct node* b)
{
  struct node dummy;
  struct node *head = &dummy;
  dummy.next = NULL;

  while(a != NULL && b != NULL)
  {
    if(a->data == b->data)
    {
      printf("a == b\n");
      Push(&head->next, a->data);
      b = b->next;
      a = a->next;
      head = head->next;
    }
    else if(a->data < b->data)
    {
      printf("a < b\n");
      a = a->next;
    }
    else
    {
      printf("a > b\n");
      b = b->next;
    }
  }

  return dummy.next;
}

void MergeSort(struct node** headRef)
{

  struct node *head = *headRef;
  struct node *head_front = NULL;
  struct node *head_back = NULL;

  if(head == NULL || head->next == NULL)
  {
    printf("return\n");
    return;
  }

  FrontBackSplit(head, &head_front, &head_back);


  print_linked_list("&head_front", &head_front);
  MergeSort(&head_front);
  print_linked_list("&head_back", &head_back);
  MergeSort(&head_back);

  *headRef = SortedMerge(head_front, head_back);

  print_linked_list("headRef", headRef);

}


struct node* SortedMerge(struct node* a, struct node* b)
{
  struct node dummy;
  struct node *head = &dummy;
  dummy.next = NULL;

  while(1)
  {
    print_linked_list("a",&a);
    print_linked_list("b",&b);
    print_linked_list("head",&dummy.next);
    if(a == NULL)
    {
      head->next = b;
      break;
    }

    if(b == NULL)
    {
      head->next = a;
      break;
    }

    if(a->data <= b->data)
    {
      printf("a <= b\n");
      MoveNode(&head->next, &a);
    }
    else
    {
      printf("a > b\n");
      MoveNode(&head->next, &b);
    }

    head = head->next;
  }
  return dummy.next;
}



struct node* ShuffleMerge(struct node* a, struct node* b)
{

  struct node dummy;
  struct node *head = &dummy;
  dummy.next = NULL;

  while((a != NULL) || (b != NULL))
  {
    if(a != NULL)
    {
      MoveNode(&head->next, &a);
      head = head->next;
    }

    if(b != NULL)
    {
      MoveNode(&head->next, &b);
      head = head->next;
    }
  }

  return dummy.next;
}
void AlternatingSplit(struct node* source,struct node** aRef, struct node** bRef)
{
  while(source != NULL)
  {
      MoveNode(aRef, &source);

      if(source != NULL)
        MoveNode(bRef, &source);
  }
  print_linked_list("aRef", aRef);
  print_linked_list("bRef", bRef);
}

// from solution
int Pop(struct node** headRef)
{
   struct node* head;
   int result;
   head = *headRef;
   assert(head != NULL);
   result = head->data;
   *headRef = head->next;
   free(head);
   return(result);
}

// from solution
void MoveNode(struct node** destRef, struct node** sourceRef)
{
   struct node* newNode = *sourceRef;
   assert(newNode != NULL);
   *sourceRef = newNode->next;
   newNode->next = *destRef;
   *destRef = newNode;
}

void FrontBackSplit(struct node* source, struct node** forntRef, struct node** backRef)
{
  struct node* fast = NULL;
  struct node* slow = NULL;

  if(source == NULL || source->next == NULL)
  {
    *forntRef = source;
    *backRef = NULL;
  }
  else
  {
    slow = source;
    fast = source->next;

    while(fast != NULL)
    {
      fast = fast->next;
      if(fast != NULL)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }
  }

  *backRef = slow->next;
  *forntRef = source;
  slow->next = NULL;

  print_linked_list("FBS", forntRef);
  print_linked_list("BBS", backRef);
  // whiel()
}

int free_linked_list(struct node* head_ptr)
{
  struct node *temp_node;
  temp_node = head_ptr;

  while(head_ptr != NULL)
  {
    head_ptr = temp_node->next;
    free(temp_node);
    temp_node = head_ptr;
  }
  return 1;
}

struct node *create_linked_list()
{
  int i = 0;

//int element[NO_ELEMENTS] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  // int element[NO_ELEMENTS] = {1,2,3,4,5};
  int element[NO_ELEMENTS] = {5,4,3,2,1};

  struct node* head_ptr;
  struct node *new_node;
  struct node *temp_node;

  head_ptr = malloc(sizeof(struct node));
  temp_node = head_ptr;
  head_ptr->next = NULL;
  head_ptr->data = element[0];

  for(i = 1; i < NO_ELEMENTS; i++)
  {
    new_node = malloc(sizeof(struct node));
    temp_node->next = new_node;
    new_node->data = element[i];
    new_node->next = NULL;
    temp_node = new_node;
  }

  print_linked_list("create_linked_list", &head_ptr);

  return head_ptr;
}

void print_linked_list(char *to_print, struct node** head_ptr)
{
  struct node *temp_node = *head_ptr;

  printf("%s->",to_print);
  while(temp_node!= NULL)
  {
    printf("[%d]", temp_node->data);
    temp_node = temp_node->next;
  }
  printf("\n");
}

int Length(struct node *head)
{
  int count = 0;
  struct node *current = head;

  while(current != NULL)
  {
    count++;
    current = current->next;
  }

  return count;
}

void Push(struct node **head, int newData)
{
  struct node *new_node = NULL;
  if((new_node = malloc(sizeof(struct node))) == NULL)
  {
    printf("Malloc Failed\n");
  }

  new_node->data = newData;
  new_node->next = *head;
  *head = new_node;
}

void sorted_insert(struct node **head, struct node *new_node)
{
  struct node dummy;
  struct node *current = &dummy;
  dummy.next = *head;
  while(current->next != NULL && current->next->data<new_node->data)
  {
    current = current->next;
  }

  new_node->next = current->next;
  current = new_node;
  *head = dummy.next;
}