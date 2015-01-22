#include <iostream>
#include <string>

using namespace std;
#define SIZE 4
void rat_maze(void);
int find_path(int pos_x, int pos_y, int turn, int map[SIZE][SIZE], int maze[SIZE][SIZE], int moves_x[SIZE], int moves_y[SIZE]);
int is_safe(int current_x, int current_y, int maze[SIZE][SIZE], int map[SIZE][SIZE]);
void print_sol(int map[SIZE][SIZE], int turn);

int main(int argc, char const *argv[])
{
  /* code */
  cout << "Simple program to find Rat's Path through a maze" << endl;
  rat_maze();
  return 0;
}


void rat_maze(void)
{
  int maze[SIZE][SIZE] = {{1, 0, 0 ,0},
                          {1, 1, 0 ,0},
                          {0, 1, 0 ,0},
                          {0, 1, 1, 1}};

  int map[SIZE][SIZE];

  int moves_x[4] = { 1,-1, 0, 0};
  int moves_y[4] = { 0, 0, 1,-1};
  int retval = 0;

  for(int i = 0; i < SIZE; i++)
  {
    for(int j = 0; j < SIZE; j++)
    {
      map[i][j] = -1;
    }
  }
  map[0][0] = 0;
  retval = find_path(0 ,0 ,1, map, maze, moves_x, moves_y);

  print_sol(map, 0);
  if(retval)
  {
    print_sol(map, 0);
  }
  else
  {
    cout << "Solution does not exist" << endl;
  }

}

int find_path(int pos_x, int pos_y, int turn, int map[SIZE][SIZE], int maze[SIZE][SIZE], int moves_x[SIZE], int moves_y[SIZE])
{
  print_sol(map, turn);

  if(pos_x == SIZE-1 && pos_y == SIZE-1)
  {
    return 1;
  }

  for(int i = 0; i < SIZE; i++)
  {
    int current_x = pos_x + moves_x[i];
    int current_y = pos_y + moves_y[i];

    if(is_safe(current_x , current_y, maze, map))
    {
      map[current_x][current_y] = turn;
      if(find_path(current_x, current_y, turn+1, map, maze, moves_x, moves_y))
      {
        return 1;
      }
      else
      {
        map[current_x][current_y] = -1;
      }
    }
  }

  return 0;
}

int is_safe(int current_x, int current_y, int maze[SIZE][SIZE], int map[SIZE][SIZE])
{
  if(map[current_x][current_y] == -1 && current_x >= 0 && current_x < SIZE && current_y >= 0 && current_y < SIZE && maze[current_x][current_y] != 0)
  {
    return 1;
  }

  return 0;
}

void print_sol(int map[SIZE][SIZE], int turn)
{
  cout << "---------------"<< turn <<"--------------------" << endl;
  for(int i = 0; i < SIZE; i++)
  {
    for(int j = 0; j < SIZE; j++)
    {
      cout << map[i][j] << "\t";
    }

    cout << endl;
    cout << endl;
  }
  cout << "-----------------------------------" << endl;
}