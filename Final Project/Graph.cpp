
#include "Graph.hpp"
#include <string>
void Graph::addVertex(std::string label){
    for(Vertex* v: vertexList){
        if(v->getLabel() == label)  // Return if vertex already exists
            return;
    }
    Vertex* v = new Vertex(label);
    vertexList.push_back(v);
}

void Graph::removeVertex(std::string label){
    Vertex* targetVertex = nullptr;
    for(Vertex* v: vertexList){     // Look for the target vertex in vertex list
        if(v->getLabel() == label){
            targetVertex = v;
            break;
        }            
    }
    if(targetVertex == nullptr)
        return;             // Target not found
    auto adjCopy = targetVertex->getAdjList();
    for (auto& adj : adjCopy) {
        adj.first->removeEdge(targetVertex);
    }
    vertexList.erase(std::remove(vertexList.begin(), vertexList.end(), targetVertex), vertexList.end());   
    delete targetVertex;
}
void Graph::addEdge(std::string label1, std::string label2, unsigned long weight){
    if(label1 == label2)    // Vertex cannot have edge to itself
        return;
    Vertex* v1 = nullptr, *v2 = nullptr;
    for(Vertex* v: vertexList){     // Search for both vertices
        if(v->getLabel() == label1){
            v1 = v;
        }
        if(v->getLabel() == label2){
            v2 = v; 
        }
    }
    if(v1 == nullptr || v2 == nullptr)
        return;     // One or more of the vertices do not exist
    for(std::pair<Vertex*, int>& adj: v1->getAdjList()){     // Check if edge already exist
        if(adj.first == v2)
            return;     // Edge exists
    }
    v1->addEdge(v2, weight);
    v2->addEdge(v1, weight);
}
void Graph::removeEdge(std::string label1, std::string label2){
    Vertex* v1 = nullptr, *v2 = nullptr;
    for(Vertex* v: vertexList){     // Search for both vertices
        if(v->getLabel() == label1){
            v1 = v;
        }
        if(v->getLabel() == label2){
            v2 = v; 
        }
    }
    if(v1 == nullptr || v2 == nullptr)
        return;     // One or more of the vertices do not exist
    bool v1Found = false, v2Found = false;
    for(std::pair<Vertex*, int>& adj: v1->getAdjList()){     // Check if edge already exist
        if(adj.first == v2)
            v1Found = true;
    }
    for(std::pair<Vertex*, int>& adj: v2->getAdjList()){     // Check if edge already exist
        if(adj.first == v1)
            v2Found = true;
    }
    if(v1Found == false || v2Found == false) 
        return;     // Edge not exist
    v1->removeEdge(v2);
    v2->removeEdge(v1);
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

