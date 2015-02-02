#include <iostream>
#include <cassert>
#include <string>
using namespace std;

void KMPSearch(char* pat, char* txt);
void computeLPSArray(char *pat, int M, int *lps);
void printArray(int *lps, int len);

int main(int argc, char const *argv[])
{
  string txt = "ABABDABACDABABCABAB";
  string pat = "AAAAAA";
  KMPSearch((char *)pat.c_str(), (char*)txt.c_str());
  return 0;
  return 0;
}

void KMPSearch(char* pat, char* txt)
{
  cout << pat << endl << txt << endl;
  int pat_len = strlen(pat);
  int txt_len = strlen(txt);

  int *lps = (int*)calloc(txt_len, sizeof(int));
  computeLPSArray(pat, pat_len, lps);

  printArray(lps, pat_len);

}


// from geeksforgeeks
void computeLPSArray(char *pat, int M, int *lps)
{
  int len = 0;  // lenght of the previous longest prefix suffix
  int i;

  lps[0] = 0; // lps[0] is always 0
  i = 1;

  // the loop calculates lps[i] for i = 1 to M-1
  while (i < M)
  {
   if (pat[i] == pat[len])
   {
     len++;
     lps[i] = len;
     i++;
   }
   else // (pat[i] != pat[len])
   {
     if (len != 0)
     {
       // This is tricky. Consider the example AAACAAAA and i = 7.
       len = lps[len-1];

       // Also, note that we do not increment i here
     }
     else // if (len == 0)
     {
       lps[i] = 0;
       i++;
     }
   }
  }
}


void printArray(int *lps, int len)
{
  for(int i = 0; i < len; i++)
  {
    cout<< "[" << lps[i] << "]";
  }
  cout << endl;
}











