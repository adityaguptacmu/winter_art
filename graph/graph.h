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
public:
  Graph(int V);                 // Constructor
  void addEdge(int v, int w);   // to add an edge to graph
  bool isCyclic();              // returns true if there is a cycle
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Add v to w’s list.
}



bool Graph::isCyclic(void)
{
  bool* is_visited = new bool[V];

  // initialise the array
  for(int i = 0; i < V; i++)
  {
    is_visited[i] = false;
  }

  for(int j = 0; j < V; j++)
  {
    if(is_visited[j] == false)
    {
      if(isCyclicUtil(j, is_visited, -1))
      {
        return true;
      }
    }
  }
  return false;
}


bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
  visited[v] = true;
  list<int>::iterator i;

  for(i = adj[v].begin(); i != adj[v].end(); i++)
  {
    if(!visited[*i])
    {
      if(isCyclicUtil(*i, visited, v))
        return true;
    }
    else if(*i != parent)
      return true;
  }
  return false;
}


#endif