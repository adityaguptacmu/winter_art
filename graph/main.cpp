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

  // g.addEdge(1, 0);
  // g.addEdge(0, 2);
  // g.addEdge(2, 0);
  // g.addEdge(0, 3);
  // g.addEdge(3, 4);

  g.addEdge_directed(0, 1);
  g.addEdge_directed(0, 2);
  g.addEdge_directed(1, 2);
  g.addEdge_directed(2, 0);
  g.addEdge_directed(2, 3);
  g.addEdge_directed(3, 3);


  cout<< sizeof(g) << endl;

  g.isCyclic_directed()? cout << "Graph contains cycle\n":
                     cout << "Graph doesn't contain cycle\n";

  g.DFS(2);

  cout << endl;

  g.BFS(2);

  return 0;
}