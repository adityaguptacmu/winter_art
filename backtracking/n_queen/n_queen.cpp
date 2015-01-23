#include <iostream>
#include <string>

using namespace std;

#define SIZE 24

void solve_n_queen(void);
void print_sol(int board[SIZE][SIZE]);
int compute_positions(int queens, int board[SIZE][SIZE]);
int is_safe(int pos_x, int pos_y, int board[SIZE][SIZE]);


int main(int argc, char const *argv[])
{
  /* code */
  cout << "simple n-queen problem solution" << endl;
  solve_n_queen();
  return 0;
}

void solve_n_queen(void)
{
  int retval = 0;
  int board[SIZE][SIZE];

  for(int i = 0; i < SIZE; i++)
  {
    for(int j = 0; j < SIZE; j++)
    {
      board[i][j] = 0;
    }
  }

  retval = compute_positions(0,board);

  if(retval)
  {
    print_sol(board);
  }
  else
  {
    cout << "No solution exist" << endl;
  }
}

int compute_positions(int queens, int board[SIZE][SIZE])
{
  if(queens == SIZE)
  {
    return 1;
  }

  for(int i = 0; i < SIZE; i++)
  {
    int p_x = queens;
    int p_y = i;
    if(is_safe(p_x,p_y,board))
    {
      board[p_x][p_y] = 1;
      if(compute_positions(queens+1, board))
      {
        return 1;
      }
      board[p_x][p_y] = 0;
    }
  }
  return 0;
}

int is_safe(int pos_x, int pos_y, int board[SIZE][SIZE])
{

  int i, j;

  for(i = 0; i < SIZE; i++)
  {
    if(board[i][pos_y] == 1)
    {
      return 0;
    }
  }

  for(i = pos_x, j = pos_y; i >= 0 && j >= 0; i--, j--)
  {
    if(board[i][j] == 1)
    {
      return 0;
    }
  }

  for(i = pos_x, j = pos_y; i >= 0 && j < SIZE; i--, j++)
  {
    if(board[i][j] == 1)
    {
      return 0;
    }
  }

  return 1;
}

void print_sol(int board[SIZE][SIZE])
{
  cout << "-----------------------------------" << endl;
  for(int i = 0; i < SIZE; i++)
  {
    for(int j = 0; j < SIZE; j++)
    {
      cout << board[i][j] << "\t";
    }

    cout << endl;
    cout << endl;
  }
  cout << "-----------------------------------" << endl;
}

