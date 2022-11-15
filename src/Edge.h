#pragma once

class Edge
{
public:
    // constructor of Edge
    Edge();

    Edge(double weights, int num);

    void setWeights(double weights);

    // return the weights of the edge
    double weights();

    // return number of edges it includes
    int edgeNum();

    void addEdge();
    void addEdge(int num);

    void deleteEdge();
    void deleteEdge(int num);

private:
    double weights;
    int num;
}