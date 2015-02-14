#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <string>
#include <cassert>


class Graph
{
  private:
    class Edge;
    class Vertex;

    class Vertex
    {
    public:
      Vertex(std::string id)
      {
        name = id;
      };


      void add_edge(Vertex *v, int distance)
      {
        Edge newEdge(this, v, distance);
        edges.push_back(newEdge);
      };

      std::string getName() {return name;};
      std::vector<Edge> getEdges() {return edges;};

      void printEdges()
      {
        std::cout << name << ":" << std::endl;
        for (int i = 0; i < edges.size(); i++)
        {
        Edge e = edges[i];
        std::cout << e.getDestination()->getName() <<
            " - " << e.getDistance() << std::endl;
        }
        std::cout << std::endl;
      }

    private:
      std::string name;
      std::vector<Edge> edges;
    };


    class Edge
    {
    public:
        Edge(Vertex *org, Vertex *dest, int dist)
        {
            assert(org!=NULL);
            assert(dest!=NULL);
            origin = org;
            destination = dest;
            distance = dist;
        };

        Vertex* getOrigin() {return origin;};
        Vertex* getDestination() {return destination;};
        int getDistance() {return distance;};

    private:
        Vertex* origin;
        Vertex* destination;
        int distance;
    };


    std::vector<Vertex*> vertices;

  public:
    Graph() {};
    void insert_vertex(std::string name)
    {
      vertices.push_back(new Vertex(name));
    }

    void insert_edge(std::string V1, std::string V2, int distance)
    {
      int flag1 = 0, flag2 = 0;
      for (int i = 0; i < vertices.size(); i++)
      {
          if(!flag1 && !(vertices[i]->getName().compare(V1)))
          {
            vertices[i]->add_edge(Edge(Vertex *org, Vertex *dest, int dist))
            flag1 = 1;
          }

          if(!flag2 && !(vertices[i]->getName().compare(V2)))
          {
            flag2 = 1;
          }

          if(flag1 && flag2)
          {
            break;
          }
      }

      if(flag1 && flag2)
      {

      }
    }

    void printGraph()
    {
      for (int i = 0; i < vertices.size(); i++)
      {
          vertices[i]->printEdges();
      }
    }
};

#endif