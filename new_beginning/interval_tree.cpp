#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// template <class type>

struct node
{
  int min;
  int max;
  int max_below;
  node *parent;
  node *left;
  node *right;
};


class interval_tree
{
private:
  node* root;
  void insert(int min, int max, node *leaf);
  node *search(int min, int max, node *leaf);
  void destroy_tree(node *leaf);
public:
  interval_tree();
  ~interval_tree();
  void destroy_tree();
  void insert(int min, int max);
  node *search_it(int min, int max);
};


interval_tree::interval_tree()
{
  root = NULL;
}


interval_tree::~interval_tree()
{
  destroy_tree();
}

void interval_tree::destroy_tree(node *leaf)
{
  if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}


void interval_tree::insert(int min, int max, node *leaf)
{
  if(key < leaf -> key_value)
  {
    if(leaf->left!=NULL)
     insert(key, leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->key_value=key;
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }
  }
  else if(key>=leaf->key_value)
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->key_value=key;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
}