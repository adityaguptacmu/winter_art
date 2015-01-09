#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstring>
#include "extra.h"
using namespace std;

template <class TYPE>

class stack
{
  public:
    stack(int size = 1000) : max_len(size)
    {
      s = new TYPE[size];
      top = EMPTY;
    }
    ~stack(){ delete []s;}
    void reset() { top = EMPTY;}
    void push(TYPE c) {s[++top] = c;}
    TYPE pop() {return (s[top--]);}
    TYPE top_of() {return (s[top]);}
    bool empty() {return bool(top == EMPTY);}
    bool full() {return bool(top == max_len - 1);}

  private:
    enum {EMPTY = -1};
    TYPE* s;
    int max_len;
    int top;
};

#endif