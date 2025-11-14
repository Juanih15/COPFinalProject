
#include "Graph.hpp"
#include <string>
void Graph::addVertex(std::string label){
    Vertex* v = new Vertex(label);
    vertexList.push_back(v);
}
void Graph::removeVertex(std::string label){
    for(Vertex* v: vertexList){
        if(v->getLabel() == label)
            for(Edge* e : v->getAdjList())
    }
    for(Vertex* v : vertexList){
        

        else{
            for(Edge* e : v->getAdjList()){
                if(e->getv1()->getLabel() == label)
                    delete e;
                if(e->getv2()->getLabel() == label)
                    delete e;
            }
        }
    }
}
void Graph::addEdge(std::string label1, std::string label2, unsigned long weight){

}
void Graph::removeEdge(std::string label1, std::string label2){

}
        
// virtual unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path){
    // Map for shortest distance so far <vert, vertexInfoStruct, ifVisited>
    // vertexInfoStruct: shortestDist, prevNode
    // 

    // For each v in V
        // If vert = startVert
            // Add <vert, (0, NULL) to map
        // Else
            // Add <vert, (inf, NULL) to map
        // Add the k=dist, v=vert entry to PQ

    // While PQ not empty
        // Pop from PQ
        // Access v's adjacent list
        // For each vert in v's adjacent list
            // If not visited
                // Compare (dist in adj list + v's dist) w/ that in map
                // If less than, 
                    // replace map dist with ()
                    // in map put v as the adjv's prev node
                    // Add k=dist, v=node to PQ
        // Mark v as visited
    
    // Search map for endVert 
        // Fill return vector with route by back tracing using the vert's prevNodes
        // Return the vert's distance as the shortest distance

