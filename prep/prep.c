#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hash.h"

#define ARR_SIZE 256
#define NO_ELEMENTS 6

char *per_20 = "\%20";

struct linked_list
{
  int data;
  struct linked_list *next;
};


int check_unique_atring(char* given);
int reverse_string(char* given);
int reverse_words(char* given);
int permutation_string(char *input1, char *input2);
int per_20_string(char *input1);
int string_compression(char *input1);
int shift_string_left(char* string_input, int number);
int create_linked_list(void);
int free_linked_list(void);
int remove_duplicate_linked_list(void);
int remove_element_linked_list(struct linked_list *prev_node, struct linked_list *cur_node);
struct linked_list *kth_last_element_linked_list(int number);
void delete_node(struct linked_list *node);
void print_linked_list();
void partition_linked_list();
void palindrome_linked_list();
bool isPalindrome(char *input);
bool IsEven(unsigned int n);
bool IsOdd(unsigned int n);
int KMP_test(void);
bool isRepeat(char* str);
void computeLPSArray(char* str, int M, int* lps);

struct linked_list *head_ptr = NULL;

int main(int argc, char const *argv[])
{
  /* code */

  int b = -5;
  int a;

  while((a = b++))
  {
    printf("IN a:[%d], b:[%d]\n", a, b);
  }
  printf("OUT a:[%d], b:[%d]\n", a, b);



  // char* given1 = "aaaabbbbcaaahhgh";
  // char* given2 = "      ABC";
  // h_t *hashtable = NULL;
  // struct linked_list *return_link;
  // bool retval_bool;

  // char *input1 = malloc(strlen(given1)+1*sizeof(char));
  // strcpy(input1,given1);

  // char *input2 = malloc(strlen(given2)+1*sizeof(char));
  // strcpy(input2,given2);

  // check_unique_atring("hello world");
  // reverse_string(input);
  // reverse_words(input);
  // permutation_string(input1, input2);
  // per_20_string(input1);
  // string_compression(input1);
  // create_linked_list();
  // remove_duplicate_linked_list();
  // return_link = kth_last_element_linked_list(4);

  // if(return_link != NULL)
  // {
  //   printf("return_link->data = [%d]\n" ,return_link->data);
  //   delete_node(return_link);
  // }

  // partition_linked_list();
  // print_linked_list("main");
  // palindrome_linked_list();
  // printf("free_linked_list\n");
  // free_linked_list();
  // retval_bool = IsOdd(5);
  // printf("retval_bool - [%d]\n", retval_bool);
  // KMP_test();
  // hashtable = ht_create(10);
  // if(hashtable == NULL)
  // {
  //   printf("creation of hashtable failed\n");
  // }
  // else
  // {
  //   print_hash_table(hashtable);
  // }

  // ht_add(hashtable, "key1", "john");
  // ht_add(hashtable, "key2", "kris");
  // ht_add(hashtable, "key4", "mike");
  // ht_add(hashtable, "lollll", "helo");

  // printf("%s\n",ht_get(hashtable, "key4"));

  // print_hash_table(hashtable);
  // free_hash_table(hashtable);
  // free(input1);
  // free(input2);
  return 0;
}

bool IsEven(unsigned int n)
{
  if (n == 0)
  {
    printf("if (n == 0)\n");
    return true;
  }
  else
  {
    printf("IsOdd(%d)\n",(n-1));
    return IsOdd(n - 1);
  }
}


bool IsOdd(unsigned int n)
{
  printf("!IsEven(%d)\n",(n));
  return !IsEven(n);
}

bool isPalindrome(char *input)
{
  if(strlen(input) < 2)
  {
    return 1;
  }
  else
  {

  }
  return 1;
}

void palindrome_linked_list()
{
  struct linked_list *tort_node = NULL;
  struct linked_list *hare_node = NULL;
  tort_node = head_ptr;
  hare_node = head_ptr;

  while(hare_node != NULL)
  {
    printf("H-[%d]\n",hare_node->data);
    printf("T-[%d]\n",tort_node->data);
    hare_node = hare_node->next;
    hare_node = hare_node->next;
    tort_node = tort_node->next;
  }

  if(hare_node!=NULL)
    printf("palindrome_linked_list - hare_node [%d]\n",hare_node->data);
  if(tort_node!=NULL)
    printf("palindrome_linked_list - tort_node [%d]\n",tort_node->data);
}

// fucked up sorting
void partition_linked_list()
{
  struct linked_list *tort_node = NULL;
  struct linked_list *hare_node = NULL;
  int temp;

  tort_node = head_ptr;
  hare_node = head_ptr;

  while(tort_node != NULL)
  {

    if(tort_node->next != NULL)
      hare_node = tort_node->next;

    while(hare_node != NULL)
    {
      if(hare_node->data < tort_node->data)
      {
        temp = tort_node->data;
        tort_node->data = hare_node->data;
        hare_node->data = temp;
      }
      hare_node = hare_node->next;
    }
    tort_node = tort_node->next;
  }
}

void delete_node(struct linked_list *node)
{
  int temp;
  struct linked_list *prev_node;
  temp = node->data;

  prev_node = node;

  while(node != NULL)
  {
    if(node->next != NULL)
    {
      node->data = node->next->data;
      prev_node = node;
      node = node->next;
    }
    else
    {
      prev_node->next = NULL;
      node = node->next;
      free(node);
    }
    print_linked_list("delete_node");
  }
}

struct linked_list *kth_last_element_linked_list(int number)
{
  int i = number;
  struct linked_list *tort_node;
  struct linked_list *hare_node;

  if(head_ptr != NULL)
  {
    tort_node = head_ptr;
    hare_node = head_ptr;
  }
  else
  {
    return NULL;
  }

  while(hare_node != NULL)
  {
    hare_node = hare_node->next;
    if(i > 0)
    {
      i--;
    }
    else
    {
      tort_node = tort_node->next;
    }
  }

  return tort_node;
}

void print_linked_list(char *to_print)
{
  struct linked_list *temp_node = head_ptr;

  printf("%s->",to_print);
  while(temp_node!= NULL)
  {
    printf("[%d]", temp_node->data);
    temp_node = temp_node->next;
  }
  printf("\n");
}

int remove_element_linked_list(struct linked_list *prev_node, struct linked_list *cur_node)
{
  prev_node->next = cur_node->next;
  free(cur_node);
  print_linked_list("remove_element_linked_list");
  return 0;
}


int remove_duplicate_linked_list(void)
{
  struct linked_list *tort_node;
  struct linked_list *hare_node;
  struct linked_list *temp_node;
  struct linked_list *temp_hare_node;

  temp_node = head_ptr;
  tort_node = head_ptr;

  if(head_ptr == NULL)
  {
    return -1;
  }
  else
  {
    hare_node = head_ptr->next;
  }

  print_linked_list("remove_duplicate_linked_list - enter");

  while(tort_node != NULL)
  {
    temp_node = tort_node;

    // if(hare_node != NULL)
    //   printf("O-tort_node:%d, hare_node:%d\n",tort_node->data,hare_node->data);

    while(hare_node != NULL)
    {
      if(tort_node->data == hare_node->data)
      {
        // printf("[%d][%d]\n",tort_node->data, hare_node->data);
        temp_hare_node = hare_node;
        hare_node = hare_node->next;
        remove_element_linked_list(temp_node, temp_hare_node);
      }
      else
      {
        temp_node = hare_node;
        hare_node = hare_node->next;
      }


      // if(hare_node != NULL)
        // printf("I-tort_node:%d, hare_node:%d\n",tort_node->data,hare_node->data);
    }

    if(tort_node != NULL)
    {
      tort_node = tort_node->next;
    }

    if(tort_node != NULL)
    {
      hare_node = tort_node->next;
    }
  }

  print_linked_list("remove_duplicate_linked_list - returning");
  return 0;
}



int free_linked_list(void)
{
  struct linked_list *temp_node;
  temp_node = head_ptr;

  while(head_ptr != NULL)
  {
    head_ptr = temp_node->next;
    free(temp_node);
    temp_node = head_ptr;
  }
  return 1;
}

int create_linked_list(void)
{
  int i = 0;

//int element[NO_ELEMENTS] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  int element[NO_ELEMENTS] = {1,2,3,4,5,6};

  struct linked_list *new_node;
  struct linked_list *temp_node;

  head_ptr = malloc(sizeof(struct linked_list));
  temp_node = head_ptr;
  head_ptr->next = NULL;
  head_ptr->data = element[0];

  for(i = 1; i < NO_ELEMENTS; i++)
  {
    new_node = malloc(sizeof(struct linked_list));
    temp_node->next = new_node;
    new_node->data = element[i];
    new_node->next = NULL;
    temp_node = new_node;
  }

  print_linked_list("create_linked_list");

  return 1;
}



int shift_string_left(char* string_input, int number)
{
  char* copy = string_input;
  while(*copy != '\0')
  {
    *(copy - number) = *copy;
    copy++;
  }
  return 1;
}

/**
 * [string_compression 1.5]
 * @param  input1 [description]
 * @return        [description]
 */
int string_compression(char *input1)
{
  char* copy = input1;
  char* copy_temp = input1;
  int count = 0;
  char element;

  while(*copy != '\0')
  {
    element = *copy;
    while(*copy == element)
    {
      count++;
      copy++;
    }

    *copy_temp = element;
    copy_temp++;
    *copy_temp = count+48;
    copy_temp++;
    count = 0;

    if(*copy == '\0')
    {
      *copy_temp = '\0';
    }

  }
  printf("[%s]\n",input1);
  return 1;
}


/**
 * [per_20_string 1.4]
 * @param  input1 [description]
 * @return        [description]
 */
int per_20_string(char *input1)
{
  char *temp = calloc(strlen(input1), sizeof(char));
  char *copy = per_20;

  strcpy(temp,input1);
  char* temp_print = temp;
  while(*temp != '\0')
  {
    if(*input1 == ' ')
    {
      while(*copy != '\0')
      {
        *temp = *copy;
        temp++;
        copy++;
      }
      input1++;
      copy = per_20;
    }
    else
    {
      *temp = *input1;
      temp++;
      input1++;
    }
  }
  strcpy(input1,temp_print);
  printf("%s\n",input1);
  return 1;
}


int permutation_string(char *input1, char *input2)
{
  int *map = calloc(ARR_SIZE, sizeof(int));
  char* head1 = input1;
  char* head2 = input2;
  int flag = 0;
  int s1 = 0;
  int s2 = 0;
  int i = 0;


  while(1)
  {

    if(*head1 == ' ')
    {
      if(s1 != 1)
        head1++;
    }
    else
    {
      if(s1!=1)
      {
        map[(int)*head1] += 1;
        head1++;
      }
    }

    if(*head2 == ' ')
    {
      if(s2 != 1)
        head2++;
    }
    else
    {
      if(s2 != 1)
      {
        map[(int)*head2] -= 1;
        head2++;
      }
    }


    if(*head1 == '\0')
    {
      s1 = 1;
    }

    if(*head2 == '\0')
    {
      s2 = 1;
    }

    if(s1 && s2)
    {
      break;
    }

  }

  for(i = 0; i < ARR_SIZE; i++)
  {
    if(map[i] != 0)
    {
      printf("[%d(%c)]\n", map[i],(char)i);
      flag = 1;
    }
  }

  if(flag == 1)
  {
    printf("No permutation\n");
  }
  else
  {
    printf("Yes permutation\n");
  }
  free(map);
  return 0;
}

int reverse_words(char* given)
{
  char *input = given;
  char *hare = input;
  char *tort = input;
  char *head = input;
  char temp1;
  char temp2;

  reverse_string(input);

  printf("%s\n", input);

  // dlrow olleh
  hare = input;
  tort = input;
  head = input;
  char* space;

  while(1)
  {

    while(1)
    {
      if(*(hare+1) != ' ' && *(hare+1) != '\0')
        hare++;
      else
        break;
    }

    space = hare+1;

    while(1)
    {
      temp1 = (char)*head;
      temp2 = (char)*hare;

      *head = (char)temp2;
      *hare = (char)temp1;

      // printf("changing\n");
      head++;
      hare--;

      if(head == hare)
        break;
    }

    // printf("[%c]\n",*space);

    if(*space == '\0')
    {
      break;
    }
    else
    {
      while(1)
      {
        space++;
        if(*space != ' ' || space == '\0')
        {
          break;
        }
      }
    }

    head = space;
    // printf("[%c]\n",*head);

    hare = head;
  }


  printf("[%s]\n",input);
  return 0;
}




int reverse_string(char* given)
{
  char *input = given;

  char *hare = input;
  char *head = input;
  char temp1;
  char temp2;

  while(1)
  {
    if(*(hare+1) != '\0')
      hare++;
    else
      break;
  }


  // printf("last element:[%c]\n",*hare);

  while(1)
  {
    temp1 = (char)*head;
    temp2 = (char)*hare;

    *head = (char)temp2;
    *hare = (char)temp1;

    // printf("changing\n");
    head++;
    hare--;

    if(head == hare)
      break;
  }

  printf("%s\n", input);
  return 0;
}






/**
 * [check_unique_atring description]
 * @param  given [description]
 * @return       [description]
 */
int check_unique_atring(char* given)
{
  char *input = given;
  int *map = calloc(256, sizeof(int));
  int count = 0;

  while(*input != '\0')
  {

    printf("input[%d]='%c(%d)'\n",count,*input,(int)*input);
    if((int)*input == 32)
    {
      count++;
      input++;
      continue;
    }

    if((int)*input <= 90 && (int)*input >= 65)
    {
      printf("to lower\n");
      // *input = *input + 32;

      if(map[(int)*input + 32] == 0)
      {
        printf("map[%d]\n", (int)*input+32);
        map[(int)*input + 32] = 1;
      }
      else
      {
        printf("Not Unique - 1!\n");
        return 0;
      }
      count++;
      input++;
      continue;
    }


    if(map[(int)*input] == 0)
    {
      printf("map[%d]\n", (int)*input);
      map[(int)*input] = 1;
    }
    else
    {
      printf("Not Unique - 2!\n");
      return 0;
    }

    count++;
    input++;
  }
  free(map);
  printf("Unique!\n");
  return 1;
}

int KMP_test(void)
{
  char txt[][100] = {"ABCAABCA", "AAAAB"};
  int n = sizeof(txt)/sizeof(txt[0]);

  for (int i=0; i<n; i++)
  {
    if(isRepeat(txt[i]) == 1)
    {
      printf("TRUE\n");
    }
    else
    {
      printf("FALSE\n");
    }
  }

  return 0;
}


bool isRepeat(char *str)
{
    // Find length of string and create an array to
    // store lps values used in KMP
    int n = strlen(str);
    int lps[n];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(str, n, lps);

    // Find length of longest suffix which is also
    // prefix of str.
    int len = lps[n-1];
    printf("len:[%d]\n",len);
    printf("retval:[%d]\n",(len > 0));
    printf("retval:[%d]\n",(n%(n-len)));
    printf("retval:[%d]\n",(n%(n-len) == 0));
    // If there exist a suffix which is also prefix AND
    // Length of the remaining substring divides total
    // length, then str[0..n-len-1] is the substring that
    // repeats n/(n-len) times (Readers can print substring
    // and value of n/(n-len) for more clarity.
    return (len > 0 && n%(n-len) == 0) ? 1:0;
}


void computeLPSArray(char* str, int M, int* lps)
{
  int len = 0; //lenght of the previous longest prefix suffix
  int i;

  lps[0] = 0; //lps[0] is always 0
  i = 1;

  // the loop calculates lps[i] for i = 1 to M-1
  while (i < M)
  {
    if (str[i] == str[len])
    {
      len++;
      lps[i] = len;
      i++;
    }
    else // (pat[i] != pat[len])
    {
      if (len != 0)
      {
        // This is tricky. Consider the example AAACAAAA and i = 7.
        len = lps[len-1];

        // Also, note that we do not increment i here
      }
      else // if (len == 0)
      {
        lps[i] = 0;
        i++;
      }
    }
  }
}