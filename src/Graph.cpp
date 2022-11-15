#include "Graph.h"

Graph::Graph(bool weighted) {
    weighted_ = weighted;
}

Graph::Graph(bool weighted, bool directed) {
    weighted_ = weighted;
    directed_ = directed;
}

Vertex Graph::getVertex(int idx) {
    return vertexRecords_[idx];
}

// Iterate through the unordered map, and push all values in to the vector to return.
std::vector<Vertex> Graph::getAllVertices() {
    std::vector<Vertex> toReturn;
    for (auto it = vertexRecords_.begin(); it != vertexRecords_.end(); it++) {
        toReturn.push_back(it->second);
    }

    return toReturn;
}

// Iterate through the x-th row of adjacency matrix, if edge number is greater than 0, then push Edge to the vector to return.
std::vector<Vertex> Graph::getAdjacent(int x) {
    std::vector<Vertex> toReturn;
    for (int i = 0; i < vertexRecords_.size(); i++) {
        if (adjacency_matrix_[x][i].edgeNum > 0 && i != x) {
            toReturn.push_back(vertexRecords_.at[i]);
        }
    }

    return toReturn;
}

// Probably need an efficient way to find index using Verdex.
Edge Graph::getEdge(Vertex source, Vertex dest) {
    
}
