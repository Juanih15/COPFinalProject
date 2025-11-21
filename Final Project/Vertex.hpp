#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include <list> 
#include <utility>
class Vertex{
    public:
        Vertex() : label("\0"), adjList(){}         // Constructor
        Vertex(std::string label) : label(label){}  // Constructor
        std::string getLabel(){                     // Get label
            return label;
        }
        std::list<std::pair<Vertex*, int>>& getAdjList(){    // Get adjacency list
            return adjList;
        }
        void addEdge(Vertex* v, int weight){
            adjList.push_back(std::make_pair(v, weight));
        }
        void removeEdge(Vertex* v){
            adjList.remove_if([v](const std::pair<Vertex*, int>& edge){
                return edge.first == v;
            });
        }
    private:
        std::string label;
        std::list<std::pair<Vertex*, int>> adjList; // <adjacent vertex, edge weight>
};

#endif