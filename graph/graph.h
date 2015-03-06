#ifndef GRAPH_H
#define GRAPH_H


#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Graph
{
  int V;              // No. of vertices
  list <int> *adj;    // Pointer to an array containing adjacency lists
  bool isCyclicUtil(int v, bool visited[], int parent);
  bool isCyclicUtil_directed(int v, bool visited[], bool rec_stack[]);
  void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
  Graph(int V);                 // Constructor
  void addEdge(int v, int w);   // to add an edge to graph
  void addEdge_directed(int v, int w);   // to add an edge to graph
  bool isCyclic();              // returns true if there is a cycle
  bool isCyclic_directed();              // returns true if there is a cycle
  void print_rec_stack(bool rec_stack[]); // prints the rec_stack
  void DFS(int v); // DFS utility
};

#endif