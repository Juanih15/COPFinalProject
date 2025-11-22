#include "Graph.hpp"
#include "GraphBase.hpp"
#include "Vertex.hpp"
#include <iostream>
int main(){
    Graph g;
    std::vector<std::string> vertices1 = { "1", "2", "3", "4", "5", "6" };      // Vertex List
    std::vector<std::tuple<std::string, std::string, unsigned long>> edges1 = { // Edge List
        {"1", "2", 7}, {"1", "3", 9}, {"1", "6", 14}, {"2", "3",10}, {"2", "4", 15}, 
        {"3", "4", 11}, {"3", "6", 2}, {"4", "5", 6}, {"5", "6", 9} };
    for(std::string v: vertices1){                  // Add vertices to graph
        g.addVertex(v);
    }
    for (auto& [start, end, weight] : edges1) {     // Add edges to graph
        g.addEdge(start, end, weight);
    }       
    std::vector<std::string> path;      // Store shorest path
    std::cout << "Distance: " << g.shortestPath("1", "5", path) << std::endl;
    std::cout << "Shortest Path: ";
    for(std::string s: path){
        std::cout << s << "  ";
    }
    std::cout << std::endl;
    return 0; 
}