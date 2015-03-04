#include <iostream>
#include <string>
#include <cassert>
using namespace std;




class Base1
{
  public:

  virtual int virt1() { return 100; }

  int data1;
};

class Derived : public Base1
{
  public:

  virtual int virt1() { return data1; }

  int derivedData;
};

int Global1( Base1 * b1 )
{
  return b1->virt1();
}


int main()
{
  Derived * d = new Derived;

  printf("%d\n", sizeof(Derived));  // 16
  printf("%d\n", sizeof(Base1));  // 16

  printf( "%d %d\n", d->virt1(), Global1( d )); // 150 150
}

/*
class Base2
{
  public:

  virtual int virt2() { return 200; }

  int data2;
};

class MultipleDerived : public Base1, public Base2
{
  public:

  virtual int virt1() { return 150; }
  virtual int virt2() { return 250; }

  int derivedData;
};

int Global2( Base2 * b2 )
{
  return b2->virt2();
}

int main()
{
  MultipleDerived * md = new MultipleDerived;

  printf("%d\n", sizeof(Base2));  // 16
  printf("%d\n", sizeof(MultipleDerived));  // 32
  printf( "%d %d %d %d\n",
    md->virt1(), Global1( md ), md->virt2(), Global2( md )); // 150 150 250 250
}
*/