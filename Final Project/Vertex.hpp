#ifndef VERTEX_H
#define VERTEX_H

#include "Edge.hpp"
#include <string>
#include <list> 
class Vertex{
    public:
        Vertex() : label("\0"), adjList(NULL){}
        Vertex(std::string label) : label(label){}
        std::string getLabel(){
            return label;
        }
        std::list<Edge*> getAdjList(){
            return adjList;
        }
        // destructor
    private:
        std::string label;
        std::list<Edge*> adjList;
};

#endif