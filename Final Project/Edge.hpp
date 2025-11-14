#ifndef EDGE_H
#define EDGE_H

#include "Vertex.hpp"
#include <string>
class Edge{
    public:
        Edge(Vertex* v, Vertex* u, int weight) : v1(v), v2(u), weight(weight){}
        // Destructor
        int getWeight(){
            return weight;
        }
        Vertex* vertOpposite(Vertex* v){
            if(v == v1) return v2;
            if(v == v2) return v1;
            return nullptr;
        }
        Vertex* getv1(){
            return v1;
        }
        Vertex* getv2(){
            return v2;
        }
    private:
        int weight;
        Vertex* v1;
        Vertex* v2; 
};

#endif 
