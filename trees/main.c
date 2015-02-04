#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"
#include "../stack_queue/stack_queue.h"

int main(int argc, char const *argv[])
{
  struct node* root = NULL;
  struct node* node_p = NULL;

  // root = insert(root, 5);
  // root = insert(root, 3);
  // root = insert(root, 7);
  // root = insert(root, 10);
  // root = insert(root, 1);
  // root = insert(root, 4);
  // root = insert(root, 15);
  // root = insert(root, 11);
  // root = insert(root, 2);
  // root = insert(root, 12);

  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 6);
  root = insert(root, 1);
  root = insert(root, 7);
  root = insert(root, 4);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 13);


  // root = insert(root, 4);
  // root = insert(root, 2);
  // root = insert(root, 5);
  // root = insert(root, 1);
  // root = insert(root, 3);
  // root = insert(root, 2);
  // root = insert(root, 3);
  // root = insert(root, 3);
  // root = insert(root, 3);
  // root = insert(root, -1);
  // root = insert(root, -5);
  // root = insert(root, -8);
  // root = insert(root, -2);
  // root = insert(root, 5);

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
  // printTree(root);

  // diagonal_sum(root);
  // printTree(root1);
  printf("\n-INORDER-\n");
  printInOrder(root);
  printf("\n-POSTORDER-\n");
  printPostorder(root);
  printf("\n-PREORDER-\n");
  printPreOrder(root);
  printf("\n-LEVELORDER-\n");
  level_order(root);
  printf("\n\n");
  node_addr(root, 6, &node_p);
  printf("[node_p->data = %d]\n",node_p->data);
  // print_tree(root);
  // printPaths(root);
  // mirror(root);
  // doubleTree(root);
  // printPaths(root);
  // printTree(root);
  // printPostorder(root);
  // clean_up(node);
  return 0;
}