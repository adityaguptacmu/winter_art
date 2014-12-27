// hash.c
#include "hash.h"
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <limits.h>


unsigned long hash(char *str, h_t *hashtable)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % hashtable->size;
}

// create head of hash table
h_t *ht_create(int size)
{
  printf("ht_create\n");

  h_t *hashtable = NULL;

  int i;

  if(size < 1)
    return NULL;

  if((hashtable = malloc(sizeof(h_t))) == NULL)
  {
    return NULL;
  }

  if((hashtable->table = malloc(sizeof(h_t_e)*size)) == NULL)
  {
    return NULL;
  }

  for(i = 0; i < size; i++ )
  {
    hashtable->table[i] = NULL;
  }

  hashtable->size = size;
  hashtable->max = MAX_ENTRY;

  return hashtable;
}


h_t_e *ht_new_entry(char *key, char *value)
{
  h_t_e *new_entry = NULL;

  if((new_entry = malloc(sizeof(h_t_e))) == NULL)
  {
    return NULL;
  }

  if((new_entry->key = strdup(key)) == NULL)
  {
    return NULL;
  }

  if((new_entry->value = strdup(value)) == NULL)
  {
    return NULL;
  }

  new_entry->next = NULL;

  return new_entry;
}

void ht_add(h_t *hashtable, char *key, char *value)
{
  int bin = 0;
  h_t_e *new_entry = NULL;
  h_t_e *next = NULL;
  h_t_e *last = NULL;

  bin = (int)hash(key,hashtable);

  printf("ht_add: bin-[%d]\n",bin);

  next = hashtable->table[bin];
  printf("1\n");

  while(next != NULL && next->key != NULL && strcmp(key,next->key) > 0)
  {
    last = next;
    next = next->next;
  }

  if(next != NULL && next->key != NULL && strcmp(key, next->key) == 0)
  {
    printf("2\n");
    free(next->value);
    next->value = strdup(value);
  }
  else
  {
    printf("3\n");
    new_entry = ht_new_entry(key, value);
    if(new_entry == NULL)
    {
      printf("new_entry == NULL\n");
      return;
    }

    if(next == hashtable->table[bin])
    {
      printf("4\n");
      new_entry->next = next;
      printf("4.1\n");
      hashtable->table[bin] = new_entry;
      printf("4.2\n");
    }
    else if (next == NULL)
    {
      printf("5\n");
      last->next = new_entry;
    }
    else
    {
      printf("6\n");
      new_entry->next = next;
      last->next = new_entry;
    }
  }
  printf("7\n");
}

char *ht_get(h_t *hashtable, char *key)
{
  int bin = 0;
  h_t_e *pair;


  bin = (int)hash(key,hashtable);

  pair = hashtable->table[bin];

  while(pair != NULL && pair->key != NULL && strcmp( key, pair->key ) > 0)
  {
    pair = pair->next;
  }

  if(pair == NULL || pair->key == NULL || strcmp( key, pair->key ) != 0)
  {
    return NULL;
  }
  else
  {
    return pair->value;
  }
}

int ht_remove(h_t *hashtable, char *key)
{
  int bin = 0;
  h_t_e *next = NULL;
  h_t_e *last = NULL;

  bin = (int)hash(key,hashtable);

  next = hashtable->table[bin];

  while(next != NULL && next->key != NULL && strcmp(key,next->key) > 0)
  {
    last = next;
    next = next->next;
  }

  if(next != NULL && next->key != NULL && strcmp(key, next->key) == 0)
  {
   free(next->value);
   free(next->key);
   last->next = next->next;
   free(next);
   return 1;
  }
  else
  {
    return 0;
  }
  return -1;
}

void print_hash_table(h_t *hashtable)
{
  int i = 0;
  int j = 0;
  h_t_e *next = NULL;

  if(hashtable == NULL)
  {
    printf("hashtable not initialised\n");
    return;
  }

  printf("-------HASTABLE BEGIN-------\n");
  printf("HASTABLE->max  = [%d]\n", hashtable->max);
  printf("HASTABLE->size = [%d]\n", hashtable->size);

  for(i = 0; i < hashtable->size; i++ )
  {
    j = 0;
    next = hashtable->table[i];
    if(next != NULL)
    {
      while(next != NULL && next->key != NULL)
      {
        printf("[%d] - (%d) - key   = [%s]\n",i,j, next->key);
        printf("[%d] - (%d) - value = [%s]\n",i,j, next->value);
        next = next->next;
        j++;
      }
    }
    else
    {
      printf("[%d] - (NULL) - --- = [NULL]\n",i);
    }
  }
  printf("-------HASTABLE END---------\n");
}


void free_hash_table(h_t *hashtable)
{
  int i = 0;
  h_t_e *next = NULL;
  h_t_e *last = NULL;

  if(hashtable == NULL)
  {
    printf("hashtable not initialised\n");
    return;
  }

  for(i = 0; i < hashtable->size; i++ )
  {
    next = hashtable->table[i];
    if(next != NULL)
    {
      while(next != NULL && next->key != NULL)
      {
        last = next;
        free(last->value);
        free(last->key);
        free(last);
        next = next->next;
      }
    }
  }
  free(hashtable->table);
  free(hashtable);
}
