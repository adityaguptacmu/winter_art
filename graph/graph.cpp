// #include "graph.h"
#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <cassert>
#include <list>
#include <limits.h>
#include "graph.h"

class Graph;

using namespace std;

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge_directed(int v, int w)
{
    adj[v].push_back(w);
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




bool Graph::isCyclic_directed(void)
{
  bool* is_visited = new bool[V];
  bool* rec_stack = new bool[V];

  // initialise the array
  for(int i = 0; i < V; i++)
  {
    is_visited[i] = false;
    rec_stack[i] = false;
  }

  for(int j = 0; j < V; j++)
  {
      if(isCyclicUtil_directed(j, is_visited, rec_stack))
      {
        return true;
      }
  }
  return false;
}


bool Graph::isCyclicUtil_directed(int v, bool visited[], bool rec_stack[])
{
    print_rec_stack(rec_stack);
    if(visited[v] == false)
    {
        visited[v] = true;
        rec_stack[v] = true;

        list<int>::iterator i;

        for(i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if(!visited[*i] && isCyclicUtil_directed(*i, visited, rec_stack))
            {
                return true;
            }
            else if(rec_stack[*i])
            {
                return true;
            }
        }
    }

    rec_stack[v] = false;
    return false;
}

void Graph::print_rec_stack(bool rec_stack[])
{
    for(int i = 0; i < V; i++)
    {
        cout << rec_stack[i] << " ";
    }
    cout << endl;
}



