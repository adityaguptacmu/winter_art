#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hello
{
	int a;
	int b;
}hell;

int main(int argc, char const *argv[])
{
	/* code */
	printf("Code fro testing hash table\n");


	char one[20];
	// memeset((void*)one, 0, 20);
	char two[20];
	// memeset((void*)two, 0, 20);
	char three[20];
	// memeset((void*)two, 0, 20);
	char four[20];
	char five[20];
	char six[20];
	char seven[20];

	hell hello1 = {1,2};
	hell hello2 = {3,4};
	hell hello3 = {4,5};
	hell hello4 = {6,7};
	hell hello5 = {8,9};
	hell hello6 = {9,0};
	hell hello7 = {0,1};

	hell hello11;
	hell hello22;
	hell hello33;
	hell hello44;
	hell hello55;
	hell hello66;
	hell hello77;

	h_t *hashtable = NULL;

	hashtable = hash_table_create(10);
	if(hashtable == NULL)
	{
	  printf("creation of hashtable failed\n");
	}
	else
	{
	  print_hash_table(hashtable);
	}

	// void ht_add(h_t *hashtable, char *key, char *value, char* flag, int location)
	ht_add(hashtable, "/key1", "/name", "john", strlen("john"), PERMANENT);
	ht_add(hashtable, "/key1", "/number", "1234567890", strlen("1234567890"), PERMANENT);
	ht_add(hashtable, "/key1", "/address", "something apt 1", strlen("something apt 1"), PERMANENT);
	ht_add(hashtable, "/key1", "/hell", (char*)&hello1, sizeof(hell), PERMANENT);

	ht_add(hashtable, "/key2", "/name", "kris", strlen("kris"), PERMANENT);
	ht_add(hashtable, "/key2", "/number", "0987654321", strlen("0987654321"), PERMANENT);
	ht_add(hashtable, "/key2", "/address", "something apt 2", strlen("something apt 2"), PERMANENT);
	ht_add(hashtable, "/key2", "/hell", (char*)&hello2, sizeof(hell), PERMANENT);

	ht_add(hashtable, "/key3", "/hell", (char*)&hello3, sizeof(hell), PERMANENT);
	ht_add(hashtable, "/key4", "/hell", (char*)&hello4, sizeof(hell), PERMANENT);
	ht_add(hashtable, "/key5", "/hell", (char*)&hello5, sizeof(hell), PERMANENT);
	ht_add(hashtable, "/key6", "/hell", (char*)&hello6, sizeof(hell), PERMANENT);
	ht_add(hashtable, "/key7", "/hell", (char*)&hello7, sizeof(hell), PERMANENT);

	ht_add(hashtable, "/key4", "/address", "mike", strlen("mike"), PERMANENT);
	ht_add(hashtable, "/lollll", "/name", "helo", strlen("helo"), TEMPORARY);



	ht_get(hashtable, "/lollll", "/name", one, strlen("helo"));
	ht_get(hashtable, "/key2", "/name", two, strlen("kris"));
	ht_get(hashtable, "/key2", "/number", three, strlen("0987654321"));
	ht_get(hashtable, "/key2", "/address", four, strlen("something apt 2"));
	ht_get(hashtable, "/key1", "/name", five, strlen("john"));
	ht_get(hashtable, "/key1", "/number", six, strlen("1234567890"));
	ht_get(hashtable, "/key1", "/address", seven, strlen("something apt 1"));



	ht_get(hashtable, "/key1", "/hell", (char*)&hello11, sizeof(hell));
	ht_get(hashtable, "/key2", "/hell", (char*)&hello22, sizeof(hell));
	ht_get(hashtable, "/key3", "/hell", (char*)&hello33, sizeof(hell));
	ht_get(hashtable, "/key4", "/hell", (char*)&hello44, sizeof(hell));
	ht_get(hashtable, "/key5", "/hell", (char*)&hello55, sizeof(hell));
	ht_get(hashtable, "/key6", "/hell", (char*)&hello66, sizeof(hell));
	ht_get(hashtable, "/key7", "/hell", (char*)&hello77, sizeof(hell));

	printf("1.%s\n",one);
	printf("2.%s\n",two);
	printf("3.%s\n",three);
	printf("4.%s\n",four);
	printf("5.%s\n",five);
	printf("6.%s\n",six);
	printf("7.%s\n",seven);

	printf("hello11:[%d][%d]\n", hello11.a,hello11.b);
	printf("hello22:[%d][%d]\n", hello22.a,hello22.b);
	printf("hello33:[%d][%d]\n", hello33.a,hello33.b);
	printf("hello44:[%d][%d]\n", hello44.a,hello44.b);
	printf("hello55:[%d][%d]\n", hello55.a,hello55.b);
	printf("hello66:[%d][%d]\n", hello66.a,hello66.b);
	printf("hello77:[%d][%d]\n", hello77.a,hello77.b);

	print_hash_table(hashtable);

	ht_remove(hashtable,"/key2", "/name");
	ht_remove(hashtable, "/key1", "/name");

	print_hash_table(hashtable);
	free_hash_table(hashtable);

	return 0;
}

