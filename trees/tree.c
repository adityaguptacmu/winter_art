#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"

#define MAX(a,b) a>b ? a:b

static inline struct node* NewNode(int data)
{
  struct node* node = malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}

/**
 * [insert description]
 * @param  node [description]
 * @param  data [description]
 * @return      [description]
 */
struct node* insert(struct node* node, int data)
{
  if(node == NULL)
  {
    return (NewNode(data));
  }
  else
  {
    if(data < node->data)
    {
      node->left = insert(node->left, data);
    }
    else
    {
      node->right = insert(node->right, data);
    }

    return node;
  }
}

/**
 * [lookup description]
 * @param  node   [description]
 * @param  target [description]
 * @return        [description]
 */
int lookup(struct node* node, int target)
{
  if(node == NULL)
  {
    return 0;
  }
  else
  {
    if(node->data == target)
    {
      return 1;
    }
    else
    {
      if(target < node->data)
        return lookup(node->left, target);
      else
        return lookup(node->right, target);
    }
  }
}

/**
 * [print_tree description]
 * @param node [description]
 */
void print_tree(struct node* node)
{
  if(node == NULL)
  {
    return;
  }
  else
  {
    printf("NODE:[left %p][data %d][right %p]\n", node->left, node->data, node->right);
    print_tree(node->left);
    print_tree(node->right);
  }
}

/**
 * [size description]
 * @param  node [description]
 * @return      [description]
 */
int size(struct node* node)
{
  if(node == NULL)
  {
    return 0;
  }
  else if(node->left == NULL && node->right == NULL)
  {
    return 1;
  }
  else
  {
    return size(node->left) + size(node->right) + 1;
  }
}

/**
 * [maxDepth description]
 * @param  node [description]
 * @return      [description]
 */
int maxDepth(struct node* node)
{
  int retval_left = 0;
  int retval_right = 0;
  if(node == NULL)
  {
    return 0;
  }
  else
  {
    retval_left = maxDepth(node->left) + 1;
    retval_right = maxDepth(node->right) + 1;

    if(retval_right > retval_left)
      return retval_right;
    else
      return retval_left;
  }
}

int minValue(struct node* node)
{
  if(node == NULL)
  {
    return 0;
  }

  if(node->left == NULL)
  {
    return node->data;
  }
  else
  {
    return minValue(node->left);
  }

}

void printTree(struct node* node)
{
  if(node == NULL)
  {
    return;
  }
  else
  {
    printTree(node->left);
    printf("[%d]\n",node->data);
    printTree(node->right);
  }
}


void printPostorder(struct node* node)
{
  if(node == NULL)
  {
    return;
  }
  else
  {
    printTree(node->left);
    printTree(node->right);
    printf("[%d]\n",node->data);
  }
}

int hasPathSum(struct node* node, int sum)
{
  int temp = 0;
  if(node == NULL)
  {
    return 0;
  }
  else
  {
    temp = sum - (node->data);
    if(temp == 0)
    {
      return 1;
    }
    else
    {
      if(hasPathSum(node->left, temp) == 1)
        return 1;
      if(hasPathSum(node->right, temp) == 1)
        return 1;
    }
  }
  return 0;
}

void printPaths(struct node* node)
{
  int path[1000];
  printPathsRecur(node, path, 0);
}

void printPathsRecur(struct node* node, int path[], int pathLen)
{
  if (node==NULL)
  {
    return;
  }

  path[pathLen] = node->data;
  pathLen++;

  if (node->left==NULL && node->right==NULL)
  {
    printArray(path, pathLen);
  }
  else
  {
    printPathsRecur(node->left, path, pathLen);
    printPathsRecur(node->right, path, pathLen);
  }
}

void printArray(int ints[], int len)
{
  int i;
  for (i=0; i<len; i++)
  {
    printf("[%d]",ints[i]);
  }
  printf("\n");
}

void mirror(struct node* node)
{
  struct node* temp;
  if(node == NULL)
  {
    return;
  }
  else
  {
    mirror(node->left);
    mirror(node->right);

    temp = node->left;
    node->left = node->right;
    node->right = temp;
  }

}

void doubleTree(struct node* node)
{
  if(node == NULL)
  {
    return;
  }
  else
  {
    doubleTree(node->left);
    doubleTree(node->right);

    struct node* new_node =  NewNode(node->data);
    new_node->left = node->left;
    new_node->right = NULL;
    node->left = new_node;
  }

  return;
}

int sameTree(struct node* a, struct node* b)
{
  // int retval_left = 0;
  // int retval_right = 0;

  if(a == NULL && b == NULL)
  {
    return 1;
  }
  else if(a == NULL || b == NULL)
  {
    return 0;
  }
  else
  {
    if(a->data == b->data)
    {
      return 1 && sameTree(a->left,b->left) && sameTree(a->right,b->right);
    }
    else
    {
      return 0;
    }
  }
}

int countTrees(int numKeys)
{
  return 1;
}





















