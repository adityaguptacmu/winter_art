#ifndef EXTRA_H
#define EXTRA_H

#include <iostream>
#include <cstring>
#include "stack.h"
using namespace std;

const int max_len = 255;
void print(const char* c);
void reverse(char* str, int n);
enum support {ta,ra,fellowship,other};
enum year {fresh, soph, junior, senior, grad};

class String
{
  public:
    String(int n){s = new char[n + 1]; len = n; }
    String(void){s = new char[max_len]; len = max_len; }
    String(char *n){len = strlen(n); s = new char[len + 1]; strcpy(s,n);}
    ~String(){cout << "D---- " << s << endl; delete []s;}
    void assign(const char* st) {strcpy(s,st); len = strlen(st);}
    int length(void){return (len);}
    void print(void){ cout << s << "\nLength: " << len << endl;}
    friend String operator+(const String& a, const String& b);

  private:
    char* s;
    int len;
};

class student
{
  public:
    student(char* name, int id, double gpa, year x);
    void print();
  private:
    int student_id;
    double gpa;
    year y;
    char name[30];
};

class grad_student: public student
{
  public:
    grad_student(char* name, int id, double g, year x, support t, char* d, char* th);
    void print();

  private:
    support s;
    char dept[10];
    char thesis[80];
};


#endif