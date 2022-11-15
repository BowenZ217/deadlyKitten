#pragma once

#include "Airport.h"
#include "Edge.h"

class Graph
{
public:
    Graph(bool weighted);

    Graph(bool weighted, bool directed);
    
    // Get a specific vertex
    Vertex getVertex(int idx);

    // Get a list of all vertices of the graph
    std::vector<Vertex> getAllVertices();

    // Get a list of vertices that is adjacent to the source vertex
    std::vector<Vertex> getAdjacent(Vertex source);

    // Get edge information from source vertex to destination vertex
    Edge getEdge(Vertex source, Vertex dest);

    // Get a list of all edges of the graph
    std::vector<Edge> getAllEdges();

    // Add an edge from source vertex to the destination edge
    bool addEdge(Vertex source, Vertex dest);
    
    // Delete certain number of edges from source to dest
    bool deleteEdge(Vertex source, Vertex dest, int num);

    // Delete a vertex. Need to modify the edges with its adjacent vertices.
    bool deleteVertex(int x);

private:
    bool weighted_;
    bool directed_;
    // 2-d matrix to store graph information. 
    std::vector<std::vector<Edge>> adjacency_matrix_;
    // Store vertex id and vertex
    // There is a problem with this design. As the system adds and deletes vertices, how to record the number of empty index?
    // Maybe need a stack to record?
    std::unordered_map<int, Vertex> vertexRecords_;
    std::stack<int> emptyPositions;
}
