#include "BFS.h"

BFS::BFS(Graph* graph, int start) {
    graph_ = graph;
    start_ = start;

    queue_.push(start);

    visited_.resize(graph_->getSize(), false);
    visited_[start] = true;
}

GraphTraversal::Iterator BFS::begin() {
    return GraphTraversal::Iterator(this, start_, graph_);
}

GraphTraversal::Iterator BFS::end() {
    return GraphTraversal::Iterator();
}

void BFS::add(int idx) {
    if (visited_[idx]) return;

    queue_.push(idx);
    visited_[idx] = true;
}

int BFS::pop() {
    int temp = peek();

    queue_.pop();
    
    return temp;
}

int BFS::peek() const {
    if (queue_.empty()) return -1;
    return queue_.front();
}

bool BFS::empty() const {
    return queue_.empty();
}

bool BFS::isVisited(int idx) {
    return visited_[idx];
}
