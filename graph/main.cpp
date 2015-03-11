#include <iostream>
#include <cassert>
#include <string>
#include "graph.h"

using namespace std;



int main(int argc, char const *argv[])
{
  std::cout << "undirected graph testing code" << std::endl;
  Graph g(5);
  cout<< sizeof(g) << endl;

  g.addEdge(0, 0);
  g.addEdge(0, 2);
  g.addEdge(2, 0);
  g.addEdge(0, 3);
  g.addEdge(3, 4);

  g.isCyclic()? cout << "Graph contains cycle\n":
                     cout << "Graph doesn't contain cycle\n";

  // g.addEdge_directed(0, 1);
  // g.addEdge_directed(0, 2);
  // g.addEdge_directed(1, 2);
  // g.addEdge_directed(2, 0);
  // g.addEdge_directed(2, 3);
  // g.addEdge_directed(3, 3);

  // g.addEdge_directed(0, 2);
  // g.addEdge_directed(2, 0);
  // g.addEdge_directed(2, 1);
  // g.addEdge_directed(0, 1);
  // g.addEdge_directed(1, 3);
  // g.addEdge_directed(0, 3);

  // g.addEdge_directed(0, 2);
  // g.addEdge_directed(2, 0);
  // g.addEdge_directed(2, 1);
  // g.addEdge_directed(0, 1);
  // g.addEdge_directed(1, 3);
  // g.addEdge_directed(0, 3);

  // cout<< sizeof(g) << endl;

  // g.isCyclic_directed()? cout << "Graph contains cycle\n":
                     // cout << "Graph doesn't contain cycle\n";

  // g.DFS(2);

  // cout << endl;

  // g.BFS(2);
  // cout << endl;
  // cout << endl;


  // g.print_all_path(2,3);


  int graph[VER][VER] = {{0, 16, 13,  0,  0,  0},
                         {0,  0, 10, 12,  0,  0},
                         {0,  4,  0,  0, 14,  0},
                         {0,  0,  9,  0,  0, 20},
                         {0,  0,  0,  7,  0,  4},
                         {0,  0,  0,  0,  0,  0}};

   cout << "\n";
  cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5) << endl;

  return 0;
}