// hash.h

#ifndef __HASH_H__
#define __HASH_H__

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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
    char* flag;
    int location;
    int data_size;
    struct hash_table_entry *next;
};


typedef struct hash_table_entry h_t_e;

#define MAX_ENTRY 100000

// location of data
#define TEMPORARY 1
#define PERMANENT 2


// const char *C_TIME = "user.st_ctime";
// const char *STAT_BUF = "user.stat";
// const char *IN_CLOUD = "user.cloud";

unsigned long hash(char *str, h_t *hashtable);
void print_hash_table(h_t *hashtable);
h_t *hash_table_create(int size);
int ht_add(h_t *hashtable, char *key, char* flag, char *value, int data_size, int location);
h_t_e *ht_new_entry(char *key, char* value, char* flag, int location, int data_size);
int ht_remove(h_t *hashtable, char *key, char* flag);
int ht_get(h_t *hashtable, char *key, char *flag, char* ret_buf, int ret_size);
void free_hash_table(h_t *hashtable);
int ht_data_exist(h_t *hashtable, char *key, char* flag);


#endif