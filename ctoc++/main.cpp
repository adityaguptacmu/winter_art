// Aditya Gupta learning process

#include <iostream>
#include "extra.h"
#include "stack.h"

using namespace std;

int main(int argc, char const *argv[])
{
  cout << "Hello World!" << endl;

  String one(40), two(40), both(60), test("Ha ha this works");

  char three[40] = {"My Name is Aditya Gupta."};
  one.assign("My Name is Aditya Aditya Gupta.");
  two.assign(three);
  cout << three << endl;
  cout << "Length: " << strlen(three) << endl;

  if(one.length() <= two.length())
  {
    cout << "here" << endl;
    two.print();
  }
  else
    one.print();

  both = one + two;
  both.print();

  print("hello");

  test.print();

  reverse(three, strlen(three));
  cout << three << endl;

  return 0;
}


void reverse(char* str, int n)
{
  stack<char> stk(n);
  for(int i = 0; i < n; ++i)
  {
    stk.push(str[i]);
  }

  for(int i = 0; i < n; ++i)
  {
    str[i] = stk.pop();
  }
}








