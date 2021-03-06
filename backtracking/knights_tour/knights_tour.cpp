#include <iostream>

using namespace std;

#define SIZE 5
#define initial_x 0
#define initial_y 0
#define initial_turn 1
#define NOT_VISITED -1

void knight_path(void);
int calculate_possible_path(int pos_x, int pos_y, int turn, int board[SIZE][SIZE], int x_move[SIZE], int y_move[SIZE]);
int is_safe(int pos_x, int pos_y, int board[SIZE][SIZE]);
void print_sol(int board[SIZE][SIZE]);

int main(int argc, char const *argv[])
{
  cout << "simple Knight's Tour problem" << endl;

  knight_path();

  return 0;
}


void knight_path(void)
{
  int board[SIZE][SIZE];
  // int x_move[8] = {-2,-2,-1, 1, 2, 2,-1, 1};
  // int y_move[8] = { 1,-1, 2, 2, 1,-1,-2,-2};

  // int x_move[8] = {1, 2,-2,-2,-1, 2,-1, 1};
  // int y_move[8] = {2, 1, 1,-1, 2,-1,-2,-2};

  int x_move[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
  int y_move[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

  int retval = 0;

  for(int i = 0; i < SIZE; i++)
  {
    for(int j = 0; j < SIZE; j++)
    {
      board[i][j] = NOT_VISITED;
    }
  }

  board[0][0] = initial_y;

  retval = calculate_possible_path(initial_x, initial_y, initial_turn, board, x_move, y_move);

  if(retval)
  {
    print_sol(board);
    return;
  }

  cout << "No Solutions Found" << endl;

}


int calculate_possible_path(int pos_x, int pos_y, int turn, int board[SIZE][SIZE], int x_move[SIZE], int y_move[SIZE])
{
  int current_x = 0;
  int current_y = 0;

  if(turn == SIZE*SIZE)
  {
    return 1;
  }

  for(int i = 0; i < SIZE; i++)
  {
    current_x = pos_x + x_move[i];
    current_y = pos_y + y_move[i];

    if(is_safe(current_x, current_y, board))
    {

      board[current_x][current_y] = turn;
      if(calculate_possible_path(current_x, current_y, turn+1, board, x_move, y_move) == 1)
      {
        return 1;
      }
      else
      {
        board[current_x][current_y] = NOT_VISITED;
      }
    }
  }
  return 0;
}

int is_safe(int pos_x, int pos_y, int board[SIZE][SIZE])
{

  // x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1

  if((pos_x < SIZE) && (pos_y < SIZE) && (pos_y >= 0) && (pos_x >= 0) && (board[pos_x][pos_y] == -1))
  {
    return 1;
  }

  return 0;
}

void print_sol(int board[SIZE][SIZE])
{
  for(int i = 0; i < SIZE; i++)
  {
    for(int j = 0; j < SIZE; j++)
    {
      cout << board[i][j] << "\t";
    }

    cout << endl;
    cout << endl;
  }
}



