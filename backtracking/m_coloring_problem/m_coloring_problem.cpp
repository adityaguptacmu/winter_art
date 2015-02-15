#include <iostream>
#include <string>
#include <cassert>


using namespace std;
#define V 4
#define COLORS 3

void graph_coloring(int graph[V][V], int color);
int graphColoringUtil(int graph[V][V], int color, int *color_array, int node);
int isSafe (int v, bool graph[V][V], int color[], int c);

int main(int argc, char const *argv[])
{
  cout << "simple m Coloring Problem" << endl;
  int graph[V][V] = {{0, 1, 1, 1},
                     {1, 0, 1, 0},
                     {1, 1, 0, 1},
                     {1, 0, 1, 0}};

  graph_coloring(graph, COLORS);


  return 0;
}

void graph_coloring(int graph[V][V], int color)
{
  int* color_array = new int[4];
  for(int i = 0; i < V; i++)
  {
    color_array[i] = 0;
  }

  if(graphColoringUtil(graph, color, color_array, 0) == 0)
  {
    std::cout << "Solution does not exist" << endl;
  }
  else
  {
    printf("Solution exists");
    for (int i = 0; i < color; ++i)
    {
      std::cout << color_array[i] << " ";
    }
    cout << endl;
  }
}

int graphColoringUtil(int graph[V][V], int color, int *color_array, int node)
{
  std::cout << "ha ha ha" << endl;
  return 0;
}


int isSafe (int v, bool graph[V][V], int color[], int c)
{
  for (int i = 0; i < V; i++)
  {
    if (graph[v][i] && c == color[i])
    {
      return 0;
    }
  }

  return 1;
}