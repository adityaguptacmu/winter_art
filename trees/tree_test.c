#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"

int main(int argc, char const *argv[])
{
  struct node* root = NULL;
  // struct node* root1 = NULL;
  // int retval = 0;

  root = insert(root, 6);
  root = insert(root, 5);
  root = insert(root, 7);

  // root1 = insert(root1, 6);
  // root1 = insert(root1, 5);
  // root1 = insert(root1, 7);
  root = insert(root, 3);
  // root1 = insert(root1, 3);
  root = insert(root, 4);
  root = insert(root, 8);
  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 3);
  root = insert(root, 3);
  root = insert(root, 3);
  root = insert(root, -1);
  root = insert(root, -5);
  root = insert(root, -8);
  root = insert(root, -2);
  root = insert(root, 5);

  printf("lookup(root, 6):[%d]\n",lookup(root, 6));
  printf("lookup(root, 1):[%d]\n",lookup(root, 1));
  printf("lookup(root, 8):[%d]\n",lookup(root, 8));
  printf("size(root):[%d]\n",size(root));
  printf("maxDepth(root):[%d]\n",maxDepth(root));
  printf("minValue(root):[%d]\n",minValue(root));
  printf("maxValue(root):[%d]\n",maxValue(root));
  printf("hasPathSum(root, 9):[%d]\n",hasPathSum(root, 9));
  // printf("sameTree(root,root1):[%d]\n",sameTree(root,root1));
  printf("isBST(root):[%d]\n",isBST(root));
  printTree(root);
  // printf("--------\n");
  // printTree(root1);
  // printPostorder(root);
  // print_tree(root);
  // printPaths(root);
  // mirror(root);
  // doubleTree(root);
  // printf("--------\n");
  // printPaths(root);
  // printTree(root);
  // printPostorder(root);
  // clean_up(node);
  return 0;
}