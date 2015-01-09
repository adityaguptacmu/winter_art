// Aditya Gupta learning process

#include <iostream>
#include "extra.h"

using namespace std;

int main(int argc, char const *argv[])
{
  cout << "Hello World!" << endl;

  String one, two, both;

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
  return 0;
}