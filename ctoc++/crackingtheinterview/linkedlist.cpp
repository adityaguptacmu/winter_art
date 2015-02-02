#include <iostream>
#include <string>
#include "linkedlist.h"

using namespace std;
node* reverse_ll_rec(node *node, linked_list *list);


int main(int argc, char const *argv[])
{
  linked_list *list = new linked_list(100);
  list->set_max(100);
  cout << list->get_max() << endl;
  // list->add_to_head(1);
  // list->add_to_head(2);
  // list->add_to_head(3);
  // list->add_to_head(4);
  list->add_to_tail(1);
  list->add_to_tail(2);
  list->add_to_tail(3);
  list->add_to_tail(4);
  list->print_ll();
  // list->clear_linked_list();
  // list->print_ll();
  // cout << "2"<< endl;
  if(list->get_head()!=0)
  {
    // cout << "3"<< endl;
    reverse_ll_rec(list->get_head(), list)->set_next(NULL);
    // cout << "1"<< endl;
  }
  list->print_ll();
  list->add_to_tail(5);
  list->add_to_head(6);
  list->print_ll();
  delete list;
  return 0;
}

node *reverse_ll_rec(node *node, linked_list* list)
{
  cout << node->get_data() << endl;
  if(node->get_next() == NULL)
  {
    cout << "changing head" << endl;
    list->set_head(node);
  }
  else
  {
    reverse_ll_rec(node->get_next(), list);
    (node->get_next())->set_next(node);
    list->set_tail(node);
    return node;
  }
}
