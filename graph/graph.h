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
  cout << "ENTERING v = " << v << "\tparent = "<< parent << endl;
  visited[v] = true;
  list<int>::iterator i;

  for(i = adj[v].begin(); i != adj[v].end(); i++)
  {
    cout << "ITERATOR i = " << *i << endl;
    if(!visited[*i])
    {
      cout << "recursing" << endl;
      if(isCyclicUtil(*i, visited, v))
      {

        cout << "return TRUE 1\t";
        cout << "v = " << v << "\tparent = "<< parent << endl;
        return true;
      }
    }
    else if(*i != parent)
    {
      cout << "return TRUE 2\t";
      cout << "v = " << v << "\tparent = "<< parent << endl;
      return true;
    }
  }
  cout << "returning FALSE\t";
  cout << "v = " << v << "\tparent = "<< parent << endl;
  return false;
}


#endif