#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

int lookup(struct node* node, int target);
void clean_up(struct node* node);
void print_tree(struct node* node);
struct node* insert(struct node* node, int data);
int size(struct node* node);
int maxDepth(struct node* node);
int minValue(struct node* node);
void printTree(struct node* node);
void printPostorder(struct node* node);
int hasPathSum(struct node* node, int sum);

// copid from solution, did not solve
void printPaths(struct node* node);
void printPathsRecur(struct node* node, int path[], int pathLen);
void printArray(int ints[], int len);
//


void mirror(struct node* node);
void doubleTree(struct node* node);
int sameTree(struct node* a, struct node* b);
int countTrees(int numKeys);
