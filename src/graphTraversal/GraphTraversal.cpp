#include "GraphTraversal.h"

GraphTraversal::Iterator::Iterator() {
    // empty, which is the end
    traversal_ = NULL;
    graph_ = NULL;
}

GraphTraversal::Iterator::Iterator(GraphTraversal* traversal, int start, Graph* graph) {
    traversal_ = traversal;
    start_ = start;
    graph_ = graph;

    // initialize the current iterator to top Node of the stack
    current_ = traversal_->peek();
}

GraphTraversal::Iterator & GraphTraversal::Iterator::operator++() {
    // check if it is the end
    if (traversal_ != NULL && !traversal_->empty()) {
        // if not
        current_ = traversal_->pop();
        // try add next vertexs
        addNext(current_);
        // after added, update the current point
        if (!traversal_->empty()) current_ = traversal_->peek();
    }
    // reach the end
    else
        traversal_ = NULL;
    
    return *this;
}

Airport* GraphTraversal::Iterator::operator*() {
    if (current_ == -1) return NULL;
    return graph_->getAirport(current_);
}

bool GraphTraversal::Iterator::operator!=(const GraphTraversal::Iterator &other) {
    // init , which needs to check if either is empty
    bool thisEmpty = false; 
    bool otherEmpty = false;

    if (traversal_ == NULL) 
        thisEmpty = true;
    if (other.traversal_ == NULL) 
        otherEmpty = true;

    if (!thisEmpty) 
        thisEmpty = traversal_->empty();
    if (!otherEmpty) 
        otherEmpty = other.traversal_->empty();

    // both empty then the traversals are equal, return false
    if (thisEmpty && otherEmpty) 
        return false; 
    // both not empty then compare the traversals
    if ((!thisEmpty) && (!otherEmpty)) 
        return (traversal_ != other.traversal_);
    // one is empty while the other is not, return true
    return true;
}

// helper function
void GraphTraversal::Iterator::addNext(int index) {
    // init
    vector<Airport*> data = graph_->getNeighbors(index);
    vector<pair<long double, Airport*>> neighbors;

    // add data to sort, shortest first
    for (const auto& curr : data)
        neighbors.push_back(pair<long double, Airport*>(graph_->_calcWeight(index, curr->index_), curr));
    
    std::sort(neighbors.begin(), neighbors.end(), [](pair<long double, Airport*> a, pair<long double, Airport*> b) {
        return a.first < b.first;
    });

    for (const auto& curr : neighbors) {
        traversal_->add(curr.second->index_);
    }
}
