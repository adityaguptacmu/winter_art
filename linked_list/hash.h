// hash.h

#ifndef __HASH_H__
#define __HASH_H__

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

struct hash_table {
    int max;
    int size;
    struct hash_table_entry **table;
};

typedef struct hash_table h_t;

struct hash_table_entry{
    char* key;
    char* value;
    struct hash_table_entry *next;
};

typedef struct hash_table_entry h_t_e;

#define MAX_ENTRY 100

unsigned long hash(char *str, h_t *hashtable);
void print_hash_table(h_t *hashtable);
h_t *ht_create(int size);
void ht_add(h_t *hashtable, char *key, char *value);
h_t_e *ht_new_entry(char *key, char *value);
int ht_remove(h_t *hashtable, char *key);
char *ht_get(h_t *hashtable, char *key);
void free_hash_table(h_t *hashtable);


#endif