#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define N 3

void swap_in_place(int *A, int *B);
int winner_tic_tac(char board[N][N]);
int trailing_zero_factorial(int A);

int main(int argc, char const *argv[])
{
  printf("CTCI Moderate Problems\n\n");

  char board[3][3] = {{'1', '0', '0'},
                      {'1', '1', '0'},
                      {'0', '1', '1'}};


  printf("winner_tic_tac:[%d]\n", winner_tic_tac(board));
  printf("trailing_zero_factorial(25):[%d]\n", trailing_zero_factorial(25));

  /*
  int A = 9;
  int B = 10;
  swap_in_place(&A,&B);
  printf("A:[%d], B:[%d]\n",A,B);
*/


  return 0;
}

//172
int trailing_zero_factorial(int A)
{
  int count_5 = 0;
  int i = 0;

  for(i = 5; A/i > 0 ; i*=5)
  {
    printf("i:[%d], A/i:[%d]\n",i,A/i);
    count_5 += A/i;
  }

  return count_5;
}

// 443
// check the diagonal and all the rows and col
int winner_tic_tac(char board[N][N])
{
  int i = 0;
  int j = 0;
  int factor = 1;
  int sum = 0;

  for(i = 0; i < N; i++)
  {
    for(j = 0; i < N; i++)
    {
      int v = 0;
      if(board[i][j] == '1')
      {
        v = 1;
      }
      else if(board[i][j] == '0')
      {
        v = 2;
      }
      sum += v*factor;
      factor *= 3;
    }
  }

  return sum;
}


void swap_in_place(int *A, int *B)
{
  *A = *A ^ *B;
  *B = *A ^ *B;
  *A = *A ^ *B;
}