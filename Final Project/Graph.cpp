#include "PriorityQueue.hpp"
#include <unordered_map>
#include <limits>
#include <algorithm>
#include "Graph.hpp"
#include <string>

void Graph::addVertex(std::string label)
{
    for (Vertex *v : vertexList)
    {
        if (v->getLabel() == label) // Return if vertex already exists
            return;
    }
    Vertex *v = new Vertex(label);
    vertexList.push_back(v);
}

void Graph::removeVertex(std::string label)
{
    Vertex *targetVertex = nullptr;
    for (Vertex *v : vertexList)
    { // Look for the target vertex in vertex list
        if (v->getLabel() == label)
        {
            targetVertex = v;
            break;
        }
    }
    if (targetVertex == nullptr)
        return; // Target not found
    auto adjCopy = targetVertex->getAdjList();
    for (auto &adj : adjCopy)
    {
        adj.first->removeEdge(targetVertex);
    }
    vertexList.erase(std::remove(vertexList.begin(), vertexList.end(), targetVertex), vertexList.end());
    delete targetVertex;
}
void Graph::addEdge(std::string label1, std::string label2, unsigned long weight)
{
    if (label1 == label2) // Vertex cannot have edge to itself
        return;
    Vertex *v1 = nullptr, *v2 = nullptr;
    for (Vertex *v : vertexList)
    { // Search for both vertices
        if (v->getLabel() == label1)
        {
            v1 = v;
        }
        if (v->getLabel() == label2)
        {
            v2 = v;
        }
    }
    if (v1 == nullptr || v2 == nullptr)
        return; // One or more of the vertices do not exist
    for (std::pair<Vertex *, int> &adj : v1->getAdjList())
    { // Check if edge already exist
        if (adj.first == v2)
            return; // Edge exists
    }
    v1->addEdge(v2, weight);
    v2->addEdge(v1, weight);
}
void Graph::removeEdge(std::string label1, std::string label2)
{
    Vertex *v1 = nullptr, *v2 = nullptr;
    for (Vertex *v : vertexList)
    { // Search for both vertices
        if (v->getLabel() == label1)
        {
            v1 = v;
        }
        if (v->getLabel() == label2)
        {
            v2 = v;
        }
    }
    if (v1 == nullptr || v2 == nullptr)
        return; // One or more of the vertices do not exist
    bool v1Found = false, v2Found = false;
    for (std::pair<Vertex *, int> &adj : v1->getAdjList())
    { // Check if edge already exist
        if (adj.first == v2)
            v1Found = true;
    }
    for (std::pair<Vertex *, int> &adj : v2->getAdjList())
    { // Check if edge already exist
        if (adj.first == v1)
            v2Found = true;
    }
    if (v1Found == false || v2Found == false)
        return; // Edge not exist
    v1->removeEdge(v2);
    v2->removeEdge(v1);
}

unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path)
{
    path.clear();

    // Locate start and end vertices
    Vertex *start = nullptr;
    Vertex *end = nullptr;

    for (Vertex *v : vertexList)
    {
        if (v->getLabel() == startLabel)
            start = v;
        if (v->getLabel() == endLabel)
            end = v;
    }

    if (!start || !end)
    {
        return ULONG_MAX; // invalid input
    }

    // Distance map and predecessor map
    std::unordered_map<Vertex *, unsigned long> dist;
    std::unordered_map<Vertex *, Vertex *> prev;

    for (Vertex *v : vertexList)
    {
        dist[v] = ULONG_MAX;
        prev[v] = nullptr;
    }

    dist[start] = 0;

    // Initialize Priority Queue
    PriorityQueue pq;
    for (Vertex *v : vertexList)
    {
        pq.push(v, dist[v]);
    }

    // Dijkstra’s Algorithm
    while (!pq.empty())
    {
        Vertex *u = pq.pop();
        if (!u)
            break;

        // Early exit optimization
        if (u == end)
            break;

        for (auto &adj : u->getAdjList())
        {
            Vertex *v = adj.first;
            unsigned long w = adj.second;

            // Relax edge u → v
            if (dist[u] != ULONG_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.decreaseKey(v, dist[v]);
            }
        }
    }

    // Reconstruct path using prev map
    if (dist[end] == ULONG_MAX)
    {
        return ULONG_MAX; // no path exists
    }

    std::vector<std::string> revPath;
    for (Vertex *v = end; v != nullptr; v = prev[v])
    {
        revPath.push_back(v->getLabel());
    }

    std::reverse(revPath.begin(), revPath.end());
    path = revPath;

    return dist[end];
}
