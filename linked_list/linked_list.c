#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hash.h"

#define NO_ELEMENTS 7

struct node
{
  int data;
  // int data2;
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

// void gfg_q1(struct node** headRef);
void gfg_q4(struct node** headRef);
void gfg_q6(struct node** headRef1, struct node** headRef2);
void gfg_q8(struct node** headRef, int M, int N);

int main(int argc, char const *argv[])
{
  struct node *head = NULL;
  // struct node *head2 = NULL;
  // struct node *head_front = NULL;
  // struct node *head_back = NULL;
  // int retval = 0;

  // head1 = create_linked_list();
  // head2 = create_linked_list();
  Push(&head, 10);
  Push(&head, 9);
  Push(&head, 8);
  Push(&head, 7);
  Push(&head, 6);
  Push(&head, 5);
  Push(&head, 4);
  Push(&head, 3);
  Push(&head, 2);
  Push(&head, 1);

  // Push(&head2, 12);
  // Push(&head2, 10);
  // Push(&head2, 2);
  // Push(&head2, 4);
  // Push(&head2, 6);

  // Push(&head_back, 10);
  // Push(&head_back, 8);
  // Push(&head_back, 1);

  // retval = Pop(&head);
  // printf("[%d]\n",retval);

  print_linked_list("main", &head);
  // print_linked_list("head_back", &head_back);

  // FrontBackSplit(head, &head_front, &head_back);
  // head = ShuffleMerge(head_back, head_front);
  // head = SortedMerge(head_back, head_front);
  // head = SortedIntersect(head_front, head_back);
  MergeSort(&head);
  // RecursiveReverse(&head);
  // gfg_q8(&head, 2, 3);
  // gfg_q1(&head);
  // gfg_q4(&head);
  print_linked_list("main", &head);
  // print_linked_list("head2", &head2);
  // gfg_q6(&head1, &head2);
  // print_linked_list("head1", &head1);
  // print_linked_list("head2", &head2);

  // AlternatingSplit(head,&head_front, &head_back);
  // free_linked_list(head_front);
  // free_linked_list(head_back);
  free_linked_list(head);
  // free_linked_list(head2);

  return 0;
}

void gfg_q8(struct node** headRef, int M, int N)
{
  struct node on_stack;
  struct node *current = &on_stack;
  on_stack.next = *headRef;
  struct node *temp = NULL;
  int m = M;
  int n = N;

  if(current == NULL) return;

  while(current != NULL)
  {
    if(m > 0)
    {
      current = current->next;
      m--;
    }
    else if(n > 0)
    {
      temp = current->next;
      if(temp != NULL)
      {
        current->next = temp->next;
        free(temp);
        temp = NULL;
        n--;
      }
      else
      {
        break;
      }
    }
    else
    {
      n = N;
      m = M;
    }
  }



}

void gfg_q6(struct node** headRef1, struct node** headRef2)
{
  struct node *fast = *headRef1;
  struct node *slow = *headRef1;
  struct node *list2 = *headRef2;
  struct node *temp = NULL;

  while(slow != NULL)
  {
    fast = slow->next;

    if(list2 == NULL)
    {
      break;
    }

    temp = list2;
    list2 = list2->next;
    slow->next = temp;
    temp->next = fast;
    slow = fast;
  }
  *headRef2 = list2;
}


void gfg_q4(struct node** headRef)
{
  struct node *fast = *headRef;
  struct node *slow = *headRef;
  struct node *temp = NULL;

  if(slow == NULL) return;
  if(slow->next == NULL) return;

  fast = slow->next;
  temp = fast->next;

  fast->next = slow;
  slow->next = temp;
  *headRef = fast;

  print_linked_list("g4g_q4", headRef);

  while(slow != NULL && slow->next != NULL)
  {
    if(slow->next->next == NULL)
    {
      break;
    }

    fast = slow->next->next;
    temp = fast->next;
    slow->next->next = temp;
    fast->next = slow->next;
    slow->next = fast;
    slow= slow->next->next;
    print_linked_list("g4g_q4_iter", headRef);
  }
}


// void gfg_q1(struct node** headRef)
// {
//   struct node *fast = *headRef;
//   struct node *slow = *headRef;

//   if(fast == NULL) return;
//   if(fast->next == NULL) return;
//   if(fast->next->next == NULL) return;

//   fast = fast->next;

//   while(fast->next != NULL)
//   {
//     if((fast->next->data == slow->data) || (fast->next->data2 == slow->data2))
//     {
//       printf("same(%d,%d)\n",fast->next->data,fast->next->data2);
//       fast = fast->next;
//       if(fast->next == NULL)
//       {
//         slow->next = fast;
//       }
//     }
//     else
//     {
//       printf("notsame(%d,%d)\n",fast->next->data,fast->next->data2);
//       slow->next = fast;
//       slow = fast;
//       fast = fast->next;
//     }
//   }
//   ;
// }

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
  // (0,10)-> (1,10)-> (3,10)-> (10,10)-> (10,8)-> (10,5)-> (20,5)-> (40,5)
  int element[NO_ELEMENTS] = {1,2,3,4,5,6,7};
  // int element2[NO_ELEMENTS] ={10,10,10,10, 8, 5, 5, 5};

  struct node* head_ptr;
  struct node *new_node;
  struct node *temp_node;

  head_ptr = malloc(sizeof(struct node));
  temp_node = head_ptr;
  head_ptr->next = NULL;
  head_ptr->data = element[0];
  // head_ptr->data2 = element2[0];

  for(i = 1; i < NO_ELEMENTS; i++)
  {
    new_node = malloc(sizeof(struct node));
    temp_node->next = new_node;
    new_node->data = element[i];
    // new_node->data2 = element2[i];
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