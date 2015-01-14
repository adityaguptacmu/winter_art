#include <stdio.h>
#include <stdlib.h>

#include "sort.h"
#include "linked_list.h"

int main(int argc, char const *argv[])
{
  /* code */
  linked_list *head = NULL;
  head = init_linked_list(100);

  Push_tail(&head,1);
  Push_tail(&head,2);
  Push_tail(&head,3);
  Push_tail(&head,4);

  print_list(head);
  printf("[%d]\n",elements_list(head));
  delete_list(&head);
  printf("[%d]\n",elements_list(head));
  print_list(head);

  return 0;

}