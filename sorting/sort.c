#include "sort.h"


void print_array(int* array);
void compare_exchg(int *A, int *B);

int static inline less(int A, int B)
{
  // printf("[%d,%d]\n",A,B);
  return (A<B?1:0);
}

void static inline exch(int* A, int* B)
{
  int temp;
  temp = *A;
  *A = *B;
  *B = temp;
}

void compare_exchg(int *A, int *B)
{
  if(less(*B, *A))
  {
    exch(A,B);
  }
}

void selection_sort_array(int a[], int lo, int hi)
{
  int iter1 = 0;
  int iter2 = 0;
  for(iter1 = lo+1; iter1 < hi; iter1++)
  {
    for(iter2 = iter1; iter2 > lo; iter2--)
    {
      compare_exchg(&a[iter2-1], &a[iter2]);
    }
  }
  ;
}

void selection_sort_llist(linked_list **head_ref)
{

  ;
}


