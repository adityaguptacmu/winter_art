#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"



#define MAX(a,b) a>b ? a:b


void diagonal_sum_main(struct node* node, int left, int *array);
void level_order_main(struct node* node, struct DLLHead_q **head_q);


static inline struct node* NewNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
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
// struct node* insert(struct node* node, int data)
// {
//   if(node == NULL)
//   {
//     return (NewNode(data));
//   }
//   else
//   {
//     if(data <= node->data)
//     {
//       node->left = insert(node->left, data);
//     }
//     else
//     {
//       node->right = insert(node->right, data);
//     }
//     return node;
//   }
// }

struct node* insert(struct node* node, int data)
{
  // printf("Adding [%d]\n", data);

  struct node* parent = NULL;
  struct node* current = NULL;
  if(node == NULL)
  {
    // printf("first node\n");
    current = NewNode(data);
    current->parent = NULL;
    return current;
  }
  else
  {
    parent = NULL;
    current = node;

    while(current!=NULL)
    {
      current->parent = parent;
      parent = current;
      current = (data>current->data)?current->right:current->left;
    }

    if(data > parent->data)
    {
      // printf("Adding to right of [%d]\n", parent->data);
      parent->right = NewNode(data);
      parent->right->parent = parent;
    }
    else
    {
      // printf("Adding to left of [%d]\n", parent->data);
      parent->left = NewNode(data);
      parent->left->parent = parent;
    }
  }

  return node;
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

/**
 * [minValue description]
 * @param  node [description]
 * @return      [description]
 */
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

/**
 * [maxValue description]
 * @param  node [description]
 * @return      [description]
 */
int maxValue(struct node* node)
{
  if(node == NULL)
  {
    return 0;
  }

  if(node->right == NULL)
  {
    return node->data;
  }
  else
  {
    return maxValue(node->right);
  }
}

/**
 * [printTree description]
 * @param node [description]
 */
void printTree(struct node* node)
{
  if(node == NULL)
  {
    return;
  }
  else
  {
    printf("[%d]",node->data);
    printTree(node->left);
    printTree(node->right);
  }
}

/**
 * [printPostorder description]
 * @param node [description]
 */
void printPostorder(struct node* node)
{
  if(node == NULL)
  {
    return;
  }
  else
  {
    printPostorder(node->left);
    printPostorder(node->right);
    printf("[%d]",node->data);
  }
}

/**
 * [printPostorder description]
 * @param node [description]
 */
void printInOrder(struct node* node)
{
  if(node == NULL)
  {
    return;
  }
  else
  {
    printInOrder(node->left);
    printf("[%d]",node->data);
    printInOrder(node->right);
  }
}

/**
 * [printPostorder description]
 * @param node [description]
 */
void printPreOrder(struct node* node)
{
  if(node == NULL)
  {
    return;
  }
  else
  {
    printf("[%d]",node->data);
    printPreOrder(node->left);
    printPreOrder(node->right);
  }
}

/**
 * [hasPathSum description]
 * @param  node [description]
 * @param  sum  [description]
 * @return      [description]
 */
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

/**
 * [printPaths description]
 * @param node [description]
 */
void printPaths(struct node* node)
{
  int path[1000];
  printPathsRecur(node, path, 0);
}

/**
 * [printPathsRecur description]
 * @param node    [description]
 * @param path    [description]
 * @param pathLen [description]
 */
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

/**
 * [printArray description]
 * @param ints [description]
 * @param len  [description]
 */
void printArray(int ints[], int len)
{
  int i;
  for (i=0; i<len; i++)
  {
    printf("[%d]",ints[i]);
  }
  printf("\n");
}

/**
 * [mirror description]
 * @param node [description]
 */
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

/**
 * [doubleTree description]
 * @param node [description]
 */
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

/**
 * [sameTree description]
 * @param  a [description]
 * @param  b [description]
 * @return   [description]
 */
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

/**
 * [countTrees description]
 * @param  numKeys [description]
 * @return         [description]
 */
int countTrees(int numKeys)
{
  return 1;
}

/**
 * [isBST description]
 * @param  node [description]
 * @return      [description]
 */
int isBST(struct node* node)
{
  if(node == NULL)
  {
    return 1;
  }
  else
  {
    if((node->left != NULL) && (minValue(node->left) > node->data))
    {
      return 0;
    }

    if((node->right != NULL) && (maxValue(node->right) <= node->data))
    {
      return 0;
    }

    if(!isBST(node->left) || !isBST(node->right))
    {
      return 0;
    }

    return 1;
  }
}


int diagonal_sum(struct node* node)
{
  if(node == NULL) return 0;
  int i = 0;
  int left = 0;
  // int right = 0;
  int array[20];
  for(i = 0; i< 20; i++)
  {
    array[i] = 0;
  }

  diagonal_sum_main(node, left, array);

  for(i = 0; i< 20; i++)
  {
    printf("(%d)[%d]\n",i, array[i]);
  }

  return 0;
}



void diagonal_sum_main(struct node* node, int left, int *array)
{
  if(node == NULL) return;
  int left_b = left + 1;
  diagonal_sum_main(node->left, left_b, array);
  diagonal_sum_main(node->right, left, array);
  printf("left:[%d], data:[%d]\n", left, node->data);
  array[left] += node->data;
}


void level_order(struct node* node)
{
  // printf("level_order\n");
  struct DLLHead_q *head_q = NULL;
  head_q = create_new_queue();
  level_order_main(node, &head_q);
}

void level_order_main(struct node* node, struct DLLHead_q **head_q)
{
  if(node == NULL)
  {
    return;
  }
  struct node* next_node = NULL;
  printf("[%d]", node->data);

  if(node->left)
  {
    q_push(head_q, (data_t)node->left);
  }
  if(node->right)
  {
    q_push(head_q, (data_t)node->right);
  }

  next_node = (struct node*)q_pop(head_q);

  level_order_main(next_node, head_q);
}


void node_addr(struct node* node, int data, struct node** ret_node)
{
  if(node == NULL)
  {
    return;
  }

  if(node->data == data)
  {
    *ret_node = node;
  }
  else
  {
    node_addr(node->left, data, ret_node);
    node_addr(node->right, data, ret_node);
  }
}

// under construction
int delete_node(struct node* node)
{
  assert(node!=NULL);
  struct node *temp = NULL;
  struct node *current = node;
  struct node *before = NULL;
  int data = 0;

  if(node->left == NULL)
  {
    temp = node->right;
  }
  else if(node->right == NULL)
  {
    temp = node->left;
  }
  else
  {
    while(current->left != NULL)
    {
      before = current;
      current = current->left;
    }




  }

  if(node->parent->left == node)
  {
    node->parent->left = temp;
  }
  else
  {
    node->parent->right = temp;
  }
  temp->parent = node->parent;
  data = node->data;
  free(node);
  return data;
}















