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

static bool bfs_adj_array(int r_graph[VER][VER], int s, int d, int parent[]);

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


void Graph::DFS(int v) // DFS utility
{
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	DFSUtil(v, visited);
}

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";
	list<int>:: iterator i;

	for(i = adj[v].begin(); i != adj[v].end(); i++)
	{
		if(!visited[*i])
		{
			DFSUtil(*i, visited);
		}
	}
}



void Graph::BFS(int v) // DFS utility
{
	bool *visited = new bool[V];
	list <int> queue;

	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	visited[v] = true;
	queue.push_back(v);

	list<int>:: iterator i;

	while(!queue.empty())
	{
		print_queue(queue);
		v = queue.front();
		cout << v << " ";
		queue.pop_front();

		for(i = adj[v].begin(); i != adj[v].end(); i++)
		{
			if(!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}

	}
}


void Graph::print_queue(list<int> queue) // prints the rec_stack
{
	cout << endl;
	list<int>::iterator i;
	cout << "queue -> ";
	for(i = queue.begin(); i != queue.end(); i++)
	{
		cout << *i << " ";
	}

	cout << endl;
}



void Graph::print_all_path(int s, int d)
{
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	list<int> path;

	// path.push_back(s);
	// visited[s] = true;

	list<int>:: iterator i;

	print_all_path_util(s,d,visited,path);

}

void Graph::print_all_path_util(int s, int d, bool visited[], list<int> path)
{
	// print_queue(path);

	visited[s] = true;
	path.push_back(s);

	if(s == d)
	{
		cout << "found path : ";
		print_queue(path);
	}
	else
	{

		list<int>:: iterator i;

		for(i = adj[s].begin(); i != adj[s].end(); i++)
		{
			if(!visited[*i])
			{
				print_all_path_util(*i,d,visited,path);
			}
		}

	}

	path.remove(s);
	visited[s] = false;

}

static void print_parent(int parent[], int size)
{
	cout << "parent -> ";
	for(int i = 1; i < size; i++)
	{
		cout << parent[i] << " ";
	}
	cout << endl;
}


int fordFulkerson(int graph[VER][VER], int s, int t)
{
	cout << "\n";
	int u, v;
	int r_graph[VER][VER];

	for(int i = 0; i < VER; i++)
		for(int j = 0; j < VER; j++)
			r_graph[i][j] = graph[i][j];

	int parent[VER];
	memset(parent, 0, VER);

	int max_flow = 0;

	while(bfs_adj_array(r_graph,s,t,parent))
	{
		print_parent(parent, VER);
		int path_flow = INT_MAX;

		for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, r_graph[u][v]);
        }
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            r_graph[u][v] -= path_flow;
            r_graph[v][u] += path_flow;
        }

        max_flow += path_flow;
		memset(parent, 0, VER);

	}

	return max_flow;
}

static bool bfs_adj_array(int r_graph[VER][VER], int s, int d, int parent[])
{
	bool *visited = new bool[VER];
	list <int> queue;

	for(int i = 0; i < VER; i++)
		visited[i] = 0;

	queue.push_back(s);
	visited[s] = 1;

	// start wokring on FIFO queue
	while(!queue.empty())
	{
		// keep popping
		int vertex = queue.front();
		queue.pop_front();
		for(int i = 0; i < VER; i++)
		{
			// if not visited and edge exist, add to the queue
			if(!visited[i] && r_graph[vertex][i] > 0)
			{
				queue.push_back(i);
				parent[i] = vertex;
				visited[i] = true;
			}
		}
	}

	// did path exist?
	return (visited[d] == true);
}

