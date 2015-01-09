#include <iostream>
#include <cstring>
#include "extra.h"

using namespace std;


String operator+(const String& a, const String& b)
{
  String temp;
  temp.assign(a.s);

  temp.len = a.len + b.len;

  if(temp.len < max_len)
  {
    strcat(temp.s, b.s);
  }
  else
  {
    cout << "Max Length exceeded in strcat" << endl;
  }

  return temp;
}

void print(const char* c)
{
  cout << "Awesome!" << endl;
  cout << c << "\nLength: " << strlen(c) << endl;
}
