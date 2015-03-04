#include <iostream>
#include <cassert>
#include <string>
#include "graph.h"

using namespace std;

int main(int argc, char const *argv[])
{
  std::cout << "graph testing code" << std::endl;
  Graph g(5);
  cout<< sizeof(g) << endl;

  g.addEdge(1, 0);
  g.addEdge(0, 2);
  // g.addEdge(2, 0);
  g.addEdge(0, 3);
  g.addEdge(3, 4);

  cout<< sizeof(g) << endl;

  g.isCyclic()? cout << "Graph contains cycle\n":
                     cout << "Graph doesn't contain cycle\n";


  return 0;
}