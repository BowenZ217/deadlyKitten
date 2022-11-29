#include "BFS.h"

/**
 * Initializes a breadth-first ImageTraversal on a given graph, starting at `start`
 * 
 * @param graph The graph this BFS is going to traverse
 * @param start The start index of this BFS
 */
BFS::BFS(Graph* graph, int start) {
    graph_ = graph;
    start_ = start;

    queue_.push(start);

    visited_.resize(graph_->getSize(), false);
    visited_[start] = true;
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
GraphTraversal::Iterator BFS::begin() {
    return GraphTraversal::Iterator(this, start_, graph_);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
GraphTraversal::Iterator BFS::end() {
    return GraphTraversal::Iterator();
}

/**
 * Adds a index for the traversal to visit in the future.
 */
void BFS::add(int idx) {
    if (visited_[idx]) return;

    queue_.push(idx);
    visited_[idx] = true;
}

/**
 * Removes and returns the current index in the traversal.
 */
int BFS::pop() {
    int temp = peek();

    queue_.pop();

    return temp;
}

/**
 * Returns the current index in the traversal.
 *  (-1 for NULL)
 */
int BFS::peek() const {
    if (queue_.empty()) return -1;
    return queue_.front();
}

/**
 * Returns true if the traversal is empty.
 */
bool BFS::empty() const {
    return queue_.empty();
}

/**
 * Return true if index is visited
 * 
 * @param idx the index to check
 */
bool BFS::isVisited(int idx) {
    return visited_[idx];
}
