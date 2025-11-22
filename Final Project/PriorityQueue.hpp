#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <vector>
#include <unordered_map>
#include <limits>
#include "Vertex.hpp"

class PriorityQueue
{
public:
    PriorityQueue();

    void push(Vertex *v, unsigned long dist);
    Vertex *pop();
    bool empty() const;

    void decreaseKey(Vertex *v, unsigned long newDist);
    unsigned long getDistance(Vertex *v) const;

private:
    struct Node
    {
        Vertex *v;
        unsigned long dist;
    };

    std::vector<Node> heap;                // Binary heap container
    std::unordered_map<Vertex *, int> pos; // Map vertex to heap index

    void heapifyUp(int i);
    void heapifyDown(int i);
    void swapNodes(int i, int j);
};

#endif
