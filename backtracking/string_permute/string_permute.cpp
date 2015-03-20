#include <iostream>
#include <cassert>

using namespace std;

void string_permute(char *str, int lo , int hi, int* count);
void swap(char* a, char* b);

int main(int argc, char const *argv[])
{
  const char* c_str();
  int count = 0;

  string my_string = "aab";

  char* str = (char*)calloc(my_string.length(), sizeof(char));

  strcpy(str,my_string.c_str());


  string_permute(str, 0 , my_string.length(), &count);
  cout << "Total Combinations Possible " << count << endl;
  free(str);
  return 0;
}

void string_permute(char *str, int lo , int hi, int* count)
{
  assert(str!=NULL);
  if(lo == hi-1){ cout << str << endl; (*count)++;}
  else
  {
    for(int i = lo; i < hi; i++)
    {
      swap(str+lo, str+i);
      string_permute(str, lo+1, hi, count);
      swap(str+lo, str+i);
    }
  }
}

void swap(char* a, char* b)
{
  char temp = *a;
  *a = *b;
  *b = temp;
}





