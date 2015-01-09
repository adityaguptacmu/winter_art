#ifndef EXTRA_H
#define EXTRA_H

#include <iostream>
#include <cstring>
using namespace std;

const int max_len = 255;
void print(const char* c);

class String
{
  public:
    void assign(const char* st) {strcpy(s,st); len = strlen(st);}
    int length(void){return (len);}
    void print(void){ cout << s << "\nLength: " << len << endl;}
    friend String operator+(const String& a, const String& b);
  private:
    char s[max_len];
    int len;
};


#endif