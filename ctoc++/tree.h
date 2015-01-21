#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

void printVerticalOrder(Node* root);
struct Node* newNode(int key);


#endif