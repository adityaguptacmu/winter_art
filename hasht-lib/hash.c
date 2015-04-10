// hash.c
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <dirent.h>
#include "hash.h"
#include <fcntl.h>
#include <assert.h>
#include <sys/stat.h>


#define SLASH_ASCII 47


const char *path_metadata_folder = "/Users/AdityaGupta/Dropbox/CMU Study/Winter 14/winter_art/hasht-lib/.h_t_metadata";

const char *path_metadata_file = "/Users/AdityaGupta/Dropbox/CMU Study/Winter 14/winter_art/hasht-lib/.h_t_metadata/setup.txt";

static h_t *ht_create(int size);


char *strdup(const char *str)
{
    int n = strlen(str) + 1;
    char *dup = malloc(n);
    if(dup)
    {
        strcpy(dup, str);
    }
    return dup;
}

/**
 * [string_append - Appends String S2 at the end of String S1]
 * @param  s1 [String 1]
 * @param  s2 [String 2]
 * @return    [Appended String]
 */
static char* string_append(const char *s1, const char *s2)
{
  char* temp_string = NULL;
  char *appended_string = NULL;

  appended_string = malloc(strlen(s1)+strlen(s2)+1);

  if(appended_string == NULL)
  {
    printf("Malloc Error!\n");
    return 0;
  }

  memset(appended_string,0,strlen(s1)+strlen(s2)+1);
  temp_string = appended_string;

  strcpy(appended_string, s1);
  temp_string += strlen(s1) - 1;

  if(*temp_string == SLASH_ASCII)
  {
    strcpy(temp_string, s2);
  }
  else
  {
    strcat(temp_string, s2);
  }

  return appended_string;
}


static unsigned long ht_hash(char *str, h_t *hashtable)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % hashtable->size;
}


h_t *hash_table_create(int size)
{
  int res = 0;
  char buf[10];
  int asize = 0;
  FILE *setup = NULL;

  printf("path_metadata_folder:[%s]\n",path_metadata_folder);
  DIR* dir = opendir(path_metadata_folder);
  if (dir)
  {
    printf("Directory exist.\n");
    /* Directory exist. */
    setup = fopen(path_metadata_file, "r");
    if(fgets(buf, sizeof(int), setup) != NULL)
    {
      printf("Reading Setup File...\n");
      asize = atoi(buf);
      printf("Setup file contains - asize:[%d]\n",asize);
    }
    else
    {
      fscanf(setup, "%d", &asize);
      printf("Setup file contains - fscanf asize:[%d]\n",asize);
      printf("Could not read from the setup file\n");
      exit(0);
    }
    printf("Creating Temporary Storage Hash Table\n");
    return ht_create(asize);
  }
  else if (ENOENT == errno)
  {
    printf("Directory does not exist.\n");
    /* Directory does not exist. */
    printf("Making Directory.\n");
    res = mkdir(path_metadata_folder, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    printf("Making Setup File.\n");
    setup = fopen(path_metadata_file, "w+");
    assert(setup != NULL);
    printf("Setting up File\n");

    if(sprintf(buf, "%d", size) < 0)
    {
      printf("Could not write to the setup file\n");
      exit(0);
    }
    else
    {
      printf("int buffer:[%s]\n",buf);
    }

    fputs(buf, setup);
    fsync((unsigned long)setup);
    fclose(setup);
    printf("Creating Temporary Storage Hash Table\n");
    return ht_create(size);
  }
  else
  {
    /* opendir() failed for some other reason. */
    printf("opendir() failed for some other reason.\n");
    return NULL;
  }
}


// create head of hash table
static h_t *ht_create(int size)
{
  printf("ht_create\n");

  h_t *hashtable = NULL;

  int i;

  if(size < 1)
    return NULL;

  if((hashtable = (h_t *)malloc(sizeof(h_t))) == NULL)
  {
    return NULL;
  }

  if((hashtable->table = (h_t_e **)malloc(sizeof(h_t_e)*size)) == NULL)
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


h_t_e *ht_new_entry(char *key, char *value, char *flag, int location, int data_size)
{
  h_t_e *new_entry = NULL;

  if((new_entry = (h_t_e *)malloc(sizeof(h_t_e))) == NULL)
  {
    return NULL;
  }

  if((new_entry->key = strdup(key)) == NULL)
  {
    return NULL;
  }


  if((new_entry->value = malloc(data_size * sizeof(char))) == NULL)
  {
    return NULL;
  }
  else
  {
    // memcpy(void *dest, const void *src, size_t n);
    memcpy(new_entry->value, value, data_size);
    // strncpy(new_entry->value, value, data_size);
  }

  if((new_entry->flag = strdup(flag)) == NULL)
  {
    return NULL;
  }

  new_entry->location = location;
  new_entry->data_size = data_size;
  new_entry->next = NULL;

  return new_entry;
}

/**
 * [convert_slash_to_plus - helper function to replace '/' with '+']
 * @param path [path to file]
 */
void convert_slash_to_underscore(char* path)
{
  char* temp = path;
  while(*temp != '\0')
  {
    if(*temp == '/')
    {
      *temp = '_';
    }
    temp++;
  }
}

void add_to_persistent_storage(h_t *hashtable, char *key, char *value, char* flag, int data_size)
{
  int bin = 0;
  char bucket[10];
  int res = 0;
  FILE *setup = NULL;

  if(key[0] != '/')
  {
    printf("Key is wrong\n");
    return;
  }

  // if(value[0] != '/')
  // {
  //   printf("Value is wrong\n");
  //   return;
  // }

  if(flag[0] != '/')
  {
    printf("flag is wrong\n");
    return;
  }

  // check if key exist
  // char* key_for_hash = strdup(key);
  // convert_slash_to_underscore(key_for_hash);

  // get bucket number
  bin = (int)ht_hash(key,hashtable);

  // get bucket in string
  if(sprintf(bucket, "/%d", bin) < 0)
  {
    printf("Could not sprintf\n");
    exit(0);
  }

  // get path to bucket
  char* path_to_bucket = string_append(path_metadata_folder,bucket);
  printf("path_to_bucket->[%s]\n",path_to_bucket);

  // check if bucket exists, if not create one
  DIR* dir = opendir(path_to_bucket);
  if (dir)
  {
    /* Directory exist. */
    printf("Bucket Exist.\n");
    closedir(dir);
  }
  else if (ENOENT == errno)
  {
    /* Directory does not exist. */
    printf("Making Bucket.\n");
    res = mkdir(path_to_bucket, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  }
  else
  {
    /* opendir() failed for some other reason. */
    printf("opendir()->Bucket failed for some other reason.\n");
    exit(0);
  }


  // check if key exist in bucket
  char* path_to_key = string_append(path_to_bucket, key);
  printf("path_to_key->[%s]\n",path_to_key);

  // check if bucket exists, if not create one
  dir = opendir(path_to_key);
  if (dir)
  {
    /* Directory exist. */
    printf("Key Exists in Bucket.\n");
    closedir(dir);
  }
  else if (ENOENT == errno)
  {
    /* Directory does not exist. */
    printf("Making Key Directory.\n");
    res = mkdir(path_to_key, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  }
  else
  {
    /* opendir() failed for some other reason. */
    printf("opendir()->key failed for some other reason.\n");
    exit(0);
  }

  printf("Creating [file:%s] in [key_folder:%s] in [bucket:%s]\n",flag, key, bucket);
  char *path_to_attribute = string_append(path_to_key, flag);
  printf("path_to_attribute->[%s]\n",path_to_attribute);
  setup = fopen(path_to_attribute, "w+");
  assert(setup != NULL);

  fwrite((const void *)value, sizeof(char), data_size, setup);
  // fputs(value, setup);
  fsync((unsigned long)setup);

  fclose(setup);
  free(path_to_attribute);
  free(path_to_bucket);
  free(path_to_key);
}


int ht_add(h_t *hashtable, char *key, char* flag, char *value, int data_size, int location)
{
  int bin = 0;
  h_t_e *new_entry = NULL;
  h_t_e *next = NULL;
  h_t_e *last = NULL;

  bin = (int)ht_hash(key,hashtable);

  if(location == PERMANENT)
  {
    add_to_persistent_storage(hashtable,key,value,flag, data_size);
  }

  printf("ht_add: bin-[%d]\n",bin);
  next = hashtable->table[bin];
  printf("1\n");


  while(next != NULL && next->key != NULL)
  {
    if((strcmp(key,next->key) == 0))
    {
      if((strcmp(flag,next->flag) == 0))
      {
        break;
      }
    }

    last = next;
    next = next->next;
  }

  if(next != NULL && next->key != NULL && (strcmp(key, next->key) == 0) && (strcmp(flag,next->flag) == 0))
  {
    printf("2\n");
    // for int not required
    free(next->value);
    // next->value = strdup(value);
    if((new_entry->value = malloc(data_size * sizeof(char))) == NULL)
    {
      return -1;
    }
    else
    {
      memcpy(new_entry->value, value, data_size);
    }
    next->location = location;
    next->data_size = data_size;
  }
  else
  {
    printf("3\n");
    new_entry = ht_new_entry(key, value, flag, location, data_size);
    if(new_entry == NULL)
    {
      printf("new_entry == NULL\n");
      return -1;
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
  return 0;
}



static int exists_on_persistent_storage(h_t *hashtable, char *key, char *flag)
{
  // int status = 0;
  int bin = 0;
  char bucket[10];

  if(key[0] != '/')
  {
    printf("Key is wrong\n");
    return 0;
  }

  if(flag[0] != '/')
  {
    printf("flag is wrong\n");
    return 0;
  }

  // get bucket number
  bin = (int)ht_hash(key,hashtable);

  // get bucket in string
  if(sprintf(bucket, "/%d", bin) < 0)
  {
    printf("Could not sprintf\n");
    exit(0);
  }

  char* path_to_bucket = string_append(path_metadata_folder,bucket);
  char* path_to_key = string_append(path_to_bucket, key);
  char *path_to_attribute = string_append(path_to_key, flag);

  if(access(path_to_attribute, F_OK) != -1)
  {
    free(path_to_attribute);
    free(path_to_bucket);
    free(path_to_key);
    return 1;
  }

  free(path_to_attribute);
  free(path_to_bucket);
  free(path_to_key);
  return 0;
}

int ht_data_exist(h_t *hashtable, char *key, char* flag)
{
  int bin = 0;
  h_t_e *pair;

  bin = (int)ht_hash(key,hashtable);

  pair = hashtable->table[bin];

  while(pair != NULL && pair->key != NULL)
  {
    if((strcmp(key,pair->key) == 0))
    {
      if((strcmp(flag,pair->flag) == 0))
      {
        break;
      }
    }
    pair = pair->next;
  }

  // can be further optimised
  if(pair == NULL || pair->key == NULL || (strcmp(key, pair->key) != 0 && strcmp(flag, pair->flag) != 0))
  {
    return exists_on_persistent_storage(hashtable,key,flag);
    // return NULL;
  }
  else
  {
    return 1;
  }
}


int get_it_from_persistent_storage(h_t *hashtable, char *key, char* flag, char* ret_buffer, int ret_size)
{

  int bin = 0;
  char bucket[10];
  FILE* setup = NULL;
  struct stat st;
  int size = 0;

  if(key[0] != '/')
  {
    printf("Key is wrong\n");
    return 0;
  }

  if(flag[0] != '/')
  {
    printf("flag is wrong\n");
    return 0;
  }

  // get bucket number
  bin = (int)ht_hash(key,hashtable);

  // get bucket in string
  if(sprintf(bucket, "/%d", bin) < 0)
  {
    printf("Could not sprintf\n");
    exit(0);
  }

  char* path_to_bucket = string_append(path_metadata_folder,bucket);
  char* path_to_key = string_append(path_to_bucket, key);
  char *path_to_attribute = string_append(path_to_key, flag);


  if(access(path_to_attribute, F_OK) != -1)
  {
    // file exists
    printf("Key-Value-Flag Pair exists on SSD\n");
    stat(path_to_attribute, &st);
    size = st.st_size;
    // char* ret_buffer = (char*)calloc(size, sizeof(char));
    // if(ret_buffer == NULL) return 0;

    setup = fopen(path_to_attribute, "r");
    // fscanf(setup, "%s", ret_buffer);
    printf("size to be returned:[%d]\n", size);
    fread((void *)ret_buffer, sizeof(char), size, setup);
    // fscanf(setup,"%s",ret_buffer);
    // fgets(ret_buffer, ret_size, setup);
    fclose(setup);
    free(path_to_attribute);
    free(path_to_bucket);
    free(path_to_key);
    return 1;
  }
  else
  {
    printf("Key-Value-Flag Pair do not exist on SSD\n");

    fclose(setup);
    free(path_to_attribute);
    free(path_to_bucket);
    free(path_to_key);

    return 0;
  }
}

int ht_get(h_t *hashtable, char *key, char* flag, char* ret_buf, int ret_size)
{
  int bin = 0;
  h_t_e *pair;
  memset((void *)ret_buf, 0, ret_size);

  bin = (int)ht_hash(key,hashtable);

  pair = hashtable->table[bin];

  while(pair != NULL && pair->key != NULL)
  {
    if((strcmp(key,pair->key) == 0))
    {
      if((strcmp(flag,pair->flag) == 0))
      {
        break;
      }
    }
    pair = pair->next;
  }

  if(pair == NULL || pair->key == NULL || strcmp(key, pair->key) != 0 || strcmp(flag, pair->flag) != 0)
  {
    printf("return from get_it_from_persistent_storage\n");
    return get_it_from_persistent_storage(hashtable,key,flag, ret_buf, ret_size);
  }
  else
  {
    printf("return from hash_table\n");
    // strncpy(char *dest, const char *src, size_t n);
    memcpy(ret_buf, pair->value, pair->data_size);
    // strncpy(ret_buf, pair->value, strlen(pair->value));
    printf("buffer:%s\n", ret_buf);
    printf("hash:%s\n", pair->value);
    return 1;
  }
}

static void remove_from_persistent_storage(h_t *hashtable, char *key, char *flag)
{
  int status = 0;
  int bin = 0;
  char bucket[10];
  // FILE* setup = NULL;
  // struct stat st;
  // int size = 0;

  if(key[0] != '/')
  {
    printf("Key is wrong\n");
    return;
  }

  if(flag[0] != '/')
  {
    printf("flag is wrong\n");
    return;
  }

  // get bucket number
  bin = (int)ht_hash(key,hashtable);

  // get bucket in string
  if(sprintf(bucket, "/%d", bin) < 0)
  {
    printf("Could not sprintf\n");
    exit(0);
  }

  char* path_to_bucket = string_append(path_metadata_folder,bucket);
  char* path_to_key = string_append(path_to_bucket, key);
  char *path_to_attribute = string_append(path_to_key, flag);

  if(access(path_to_attribute, F_OK) != -1)
  {
    status = remove(path_to_attribute);
    if( status == 0 )
    {
      printf("Attribute Deleted:[%s]\n",path_to_attribute);
    }
    else
    {
      printf("Unable to delete Attribute\n");
    }
  }

  free(path_to_attribute);
  free(path_to_bucket);
  free(path_to_key);
}



int ht_remove(h_t *hashtable, char *key, char *flag)
{
  int bin = 0;
  h_t_e *next = NULL;
  h_t_e *last = NULL;

  bin = (int)ht_hash(key,hashtable);

  next = hashtable->table[bin];
  remove_from_persistent_storage(hashtable,key,flag);

  printf("removing from hashtable 1\n");
  while(next != NULL && next->key != NULL)
  {
    if((strcmp(key,next->key) == 0))
    {
      if((strcmp(flag,next->flag) == 0))
      {
        break;
      }
    }
    last = next;
    next = next->next;
  }

  printf("removing from hashtable 2\n");
  if(next != NULL && next->key != NULL && next->flag != NULL && (strcmp(key, next->key) == 0) && (strcmp(flag,next->flag) == 0))
  {
    free(next->value);
    free(next->flag);
    free(next->key);
    if(hashtable->table[bin] == next)
    {
      hashtable->table[bin] = next->next;
    }
    else
    {
      last->next = next->next;
    }
    free(next);
    printf("removing from hashtable 3\n");
    return 1;
  }
  else
  {
    printf("removing from hashtable 4\n");
    return 0;
  }
  printf("removing from hashtable 5\n");
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
        printf("[%d]-(%d)-[key][%s]-",i,j, next->key);
        printf("[value][%s]-",next->value);
        printf("[flag][%s]-",next->flag);
        printf("[location][%d]-",next->location);
        printf("[data_size][%d]\n",next->data_size);
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
        free(last->flag);
        free(last);
        next = next->next;
      }
    }
  }
  free(hashtable->table);
  free(hashtable);
}
