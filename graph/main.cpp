#include <iostream>
#include <cassert>
#include <string>
#include "graph.h"


int main(int argc, char const *argv[])
{
  std::cout << "graph testing code" << std::endl;
  Graph g;

  g.insert_vertex("A");
  g.insert_vertex("B");
  g.insert_vertex("C");
  g.insert_vertex("D");
  g.insert_vertex("E");
  g.insert_vertex("F");


  g.printGraph();

  return 0;
}