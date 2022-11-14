#pragma once

#include "Airport.h"
#include "Edge.h"

class Graph
{
public:
    Graph(bool weighted);

    Graph(bool weighted, bool directed);
    
    // Get a specific vertex
    Vertex getVertex(int x);

    // Get a list of all vertices of the graph
    std::vector<Vertex> getAllVertices();

    // Get a list of vertices that is adjacent to the source vertex
    std::vector<Vertex> getAdjacent(Vertex source);

    // Get a list of edges from source vertex to destination vertex
    std::vector<Edge> getEdges(Vertex source, Vertex dest);

    // Get a list of all edges of the graph
    std::vector<Edge> getAllEdges();

    // Add an edge from source vertex to the destination edge
    bool addEdge(Vertex source, Vertex dest);

    // Delete and return an edge by id
    Edge deleteEdge(std::string edgeId);
    
    // Delete and return an edge from source to the dest by id
    Edge deleteEdge(Vertex source, Vertex dest, std::string edgeId);

    // Delete and return an vertex. Need to modify the edges with its adjacent vertices.
    Vertex deleteVertex(int x);

private:
    bool weighted;
    bool directed;
    // 2-d matrix to store graph information. 
    std::vector<std::vector<Edge>> adjacency_matrix;
    // Store vertex id and vertex
    std::unordered_map<int, Vertex> vertexRecords;
}
