#include <stdio.h>
#include <stdlib.h>

#include "sort.h"
#include "linked_list.h"

#define SIZE 20
void print_array(int* array);

typedef struct
{
  short d;
   char c;
}test;


int main(int argc, char const *argv[])
{
  /* code */
  linked_list *head = NULL;
  head = init_linked_list(100);
  int i = 0;

  Push_tail(&head,1);
  Push_tail(&head,2);
  Push_tail(&head,3);
  Push_tail(&head,4);

  print_list(head);
  printf("[%d]\n",elements_list(head));
  delete_list(&head);
  printf("[%d]\n",elements_list(head));
  print_list(head);

  int *array = (int*)malloc(SIZE*sizeof(int));
  if(array == NULL){printf("Malloc Failed!\n"); exit(0);}

  int count = SIZE;
  for(i = 0; i < SIZE; i++)
  {
    array[i] = count;
    count--;
  }


  print_array(array);
  selection_sort_array(array, 0, SIZE);
  print_array(array);

  test new_test;
  printf("------------------%lu\n",sizeof(test));

  return 0;

}

void print_array(int* array)
{
  int i = 0;
  for(i = 0; i < SIZE; i++)
  {
    printf("[%d]-", array[i]);
  }
  printf("X\n");
}
