#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char hashTable[10][6] = {" ", " ", "2abc", "3def", "4ghi", "5jkl",
                               "6mno", "7pqrs", "8tuv", "9wxyz"};

int Cannonball(int height);
int RaiseIntToPower(int n, int k);
int GCD(int x, int y);
int Fib(int n);
int CountFib1(int n);
int DigitSum(int n);
int DigitalRoot(int n);
int Combinations(int x, int y);
void printWords(void);
void printWordsUtil(int number[], int curr_digit, char output[], int n);

/**
 * [main description]
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, char const *argv[])
{
  /* code */
  printf("Cannonball(5):[%d]\n",Cannonball(5));
  printf("RaiseIntToPower(1,12345):[%d]\n",RaiseIntToPower(1,12345));
  printf("GCD(39,13):[%d]\n",GCD(39, 13));
  printf("Fib(6):[%d]\n",Fib(6));
  printf("DigitSum(1234):[%d]\n",DigitSum(1234));
  printf("DigitalRoot(65536):[%d]\n",DigitalRoot(65536));
  printf("Combinations(6,2):[%d]\n",Combinations(6,2));

  char* given1 = "ABC";
  char *input1 = malloc(strlen(given1)+1*sizeof(char));
  strcpy(input1,given1);
  printWords();

  // printf("Reverse(input1):[%d]\n",Reverse(input1));
  return 0;
}


void printWords(void)
{
  int number[] = {2, 0, 2, 2};
  int n = sizeof(number)/sizeof(number[0]);
  // printWords(number, n);
  char result[n+1];
  result[n] ='\0';
  printWordsUtil(number, 0, result, n);
}



void printWordsUtil(int number[], int curr_digit, char output[], int n)
{
  // printf("recursive\n");
  // Base case, if current output word is prepared
  int i;
  if (curr_digit == n)
  {
    char* temp = output;
    while(*temp != '\0')
    {
      if(*temp != ' ')
      {
        printf("%c", *temp);
      }
      temp++;
    }
    printf("\n");
    // printf("%s\n", output);
    return;
  }

  // Try all 4 possible characters for current digir in number[]
  // and recur for remaining digits
  // if(number[curr_digit] == 0 || number[curr_digit] == 1)
  // {
  //   printWordsUtil(number, curr_digit+1, output, n);
  //   return;
  // }

  for (i=0; i<strlen(hashTable[number[curr_digit]]); i++)
  {
    output[curr_digit] = hashTable[number[curr_digit]][i];
    printWordsUtil(number, curr_digit+1, output, n);
  }
}


/**
 * [Cannonball description]
 * @param  height [description]
 * @return        [description]
 */
int Cannonball(int height)
{
  if(height == 0)
  {
    return 0;
  }
  else
  {
    return (height + Cannonball(height - 1));
  }
}

/**
 * [RaiseIntToPower description]
 * @param  n [description]
 * @param  k [description]
 * @return   [description]
 */
int RaiseIntToPower(int n, int k)
{
  if(k == 0)
  {
    return 1;
  }
  else
  {
    return n*RaiseIntToPower(n,k-1);
  }
}

/**
 * [GCD description]
 * @param  x [description]
 * @param  y [description]
 * @return   [description]
 */
int GCD(int x, int y)
{
  if(x % y == 0)
  {
    return y;
  }
  else
  {
    return GCD(y , x%y);
  }
}


/**
 * [Fib description]
 * @param  n [description]
 * @return   [description]
 */
int Fib(int n)
{
  int tn_minus_1 = 1;
  int tn_minus_2 = 0;
  int tn = 0;
  int i = 0;

  if(n == 0 || n == 1)
  {
    return 0;
  }

  for(i = 2; i <= n; i++)
  {
    tn = tn_minus_1 + tn_minus_2;
    tn_minus_2 = tn_minus_1;
    tn_minus_1 = tn;
  }

  return tn;
}


/**
 * [Fib_r recursive]
 * @param  n [description]
 * @return   [description]
 */
int CountFib1(int n)
{
  if (n < 2)
  {
    return n;
  }
  else
  {
    return Fib(n - 1) + Fib(n - 2);
  }
}

/**
 * [DigitSum description]
 * @param  n [description]
 * @return   [description]
 */
int DigitSum(int n)
{
  if(n % 10 == 0)
  {
    return 0;
  }
  else
  {
    return ((n%10) + DigitSum(n/10));
  }
}


/**
 * [DigitalRoot description]
 * @param  n [description]
 * @return   [description]
 */
int DigitalRoot(int n)
{
  if((n/10) == 0)
  {
    return n;
  }
  else
  {
    return DigitalRoot(DigitSum(n));
  }
}


/**
 * [Combinations description]
 * @param  x [description]
 * @param  y [description]
 * @return   [description]
 */
int Combinations(int x, int y)
{
  // printf("Combinations(%d, %d)\n",x,y);
  if(x == y || y == 0)
  {
    // printf("Combinations(%d, %d) -> 1\n",x,y);
    return 1;
  }
  else
  {
    return Combinations(x-1, y-1) + Combinations(x-1, y);
  }
}

// void Reverse(char* str)
// {
//   if(str == NULL || )
//   {
//     return;
//   }
//   return;
// }













