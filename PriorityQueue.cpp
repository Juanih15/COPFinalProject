#include "PriorityQueue.hpp"
#include <algorithm>

PriorityQueue::PriorityQueue() {}

// Insert or update
void PriorityQueue::push(Vertex *v, unsigned long dist)
{
    // If vertex already exists, decrease the key
    if (pos.count(v))
    {
        decreaseKey(v, dist);
        return;
    }

    heap.push_back({v, dist});
    int index = heap.size() - 1;
    pos[v] = index;

    heapifyUp(index);
}

bool PriorityQueue::empty() const
{
    return heap.empty();
}

// Remove and return the vertex with minimum distance
Vertex *PriorityQueue::pop()
{
    if (heap.empty())
        return nullptr;

    Vertex *minV = heap[0].v;

    // Remove mapping for the extracted root
    pos.erase(minV);

    // Move the last element to root
    if (!heap.empty())
    {
        heap[0] = heap.back();
        heap.pop_back();
    }

    // Fix the pos map and heap
    if (!heap.empty())
    {
        pos[heap[0].v] = 0;
        heapifyDown(0);
    }

    return minV;
}

void PriorityQueue::decreaseKey(Vertex *v, unsigned long newDist)
{
    if (!pos.count(v))
        return;

    int i = pos[v];
    if (newDist >= heap[i].dist)
        return;

    heap[i].dist = newDist;
    heapifyUp(i);
}

unsigned long PriorityQueue::getDistance(Vertex *v) const
{
    if (!pos.count(v))
        return ULONG_MAX;
    return heap[pos.at(v)].dist;
}

//
void PriorityQueue::swapNodes(int i, int j)
{
    std::swap(heap[i], heap[j]);
    pos[heap[i].v] = i;
    pos[heap[j].v] = j;
}

void PriorityQueue::heapifyUp(int i)
{
    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if (heap[i].dist < heap[parent].dist)
        {
            swapNodes(i, parent);
            i = parent;
        }
        else
        {
            break;
        }
    }
}

void PriorityQueue::heapifyDown(int i)
{
    int n = heap.size();

    while (true)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < n && heap[left].dist < heap[smallest].dist)
            smallest = left;

        if (right < n && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest != i)
        {
            swapNodes(i, smallest);
            i = smallest;
        }
        else
        {
            break;
        }
    }
}
