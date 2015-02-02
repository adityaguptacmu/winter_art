#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cassert>


class node
{
  int data;
  node* next;

public:
  node(void)
  {
    data = 0;
    next = 0;
  };

  void set_data(int value)
  {
    data = value;
  };

  void set_next(node* ptr)
  {
    next = (node*)(ptr);
  };

  int get_data(void)
  {
    return data;
  };

  node* get_next(void)
  {
    return next;
  }
};


class linked_list
{
  node* head;
  node* tail;
  int max;
  int present_elems;

public:
  linked_list(int max_elements)
  {
    head = 0;
    tail = 0;
    max = max_elements;
    present_elems = 0;
  }


  void set_head(node* head_ptr)
  {
    head = head_ptr;
  };

  node *get_head(void)
  {
    return head;
  };

  void set_tail(node* tail_ptr)
  {
    tail = tail_ptr;
  };

  node *get_tail(void)
  {
    return tail;
  };

  void set_max(int max_val)
  {
    max = max_val;
  };

  void inc_elem_count(int elem)
  {
    present_elems++;
  };

  int get_max(void)
  {
    return max;
  };

  int get_elem_count(void)
  {
    return present_elems;
  };

  void add_to_head(int value);
  void add_to_tail(int value);
  void print_ll(void);
  void clear_linked_list(void);

};

void linked_list::add_to_head(int value)
{
  if(present_elems == max)
  {
    std::cout << "linked_list is full" << std::endl;
    return;
  }
  node* new_node = new node;
  new_node->set_data(value);
  new_node->set_next(head);
  head = new_node;
  present_elems++;

  if(present_elems == 1)
  {
    tail = new_node;
  }
}

void linked_list::add_to_tail(int value)
{
  if(present_elems == max)
  {
    std::cout << "linked_list is full" << std::endl;
    return;
  }
  node* new_node = new node;
  new_node->set_data(value);
  new_node->set_next(NULL);

  if(present_elems == 0)
  {
    tail = new_node;
    head = new_node;
  }
  else
  {
    tail->set_next(new_node);
    tail = new_node;
  }

  present_elems++;

}

void linked_list::print_ll(void)
{
  assert(head!=0);
  node* current = head;
  while(current != NULL)
  {
    std::cout << "[" << current->get_data() << "]" << "->";
    current = current->get_next();
  }
  std::cout << "[NULL]" << std::endl;
}

void linked_list::clear_linked_list(void)
{
  node* current = head;
  node* temp = 0;
  while(current != NULL)
  {
    temp = current;
    current = current->get_next();
    delete temp;
  }
  head = NULL;
  tail = NULL;
}


#endif