#include "BFS.h"

BFS::BFS(Graph& graph, int start) {
    graph_ = graph;
    start_ = start;
    queue_.push(graph_.getAirport(start));

    visited.resize(graph_.getSize(), false);
    visited[start] = true;
}

GraphTraversal::Iterator BFS::begin() {
    GraphTraversal* bfs = new BFS(graph_, start_);
    return GraphTraversal::Iterator(bfs, start_, graph_);
}

GraphTraversal::Iterator BFS::end() {
    return GraphTraversal::Iterator();
}

void BFS::add(int idx) {
    Airport airport = graph_.getAirport(idx);
    visited[idx] = true;
    queue_.push(airport);
}

Airport BFS::pop() {
    Airport temp = peek();
    /**
     * @todo Not sure whether airport is treated as visited after pushing to queue or popping from queue.
    */
    queue_.pop();
    return temp;
}

Airport BFS::peek() const {
    return queue_.front();
}

bool BFS::empty() const {
    return queue_.empty();
}

bool BFS::isVisited(int idx) {
    return visited[idx];
}