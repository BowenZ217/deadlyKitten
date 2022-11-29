#pragma once

#include "GraphTraversal.h"
#include "Graph.h"
#include "Airport.h"
#include <queue>
#include <iterator>


class BFS: public GraphTraversal 
{
    public:
    /**
     * @param graph The graph to be traversed
     * @param start The starting Airport's index
    */
        BFS(Graph& graph, int start);

        GraphTraversal::Iterator begin();
        GraphTraversal::Iterator end();

        void add(int idx);
        Airport pop();
        Airport peek() const;
        bool empty() const;

        /**
         * @param idx The index of Airport to be verified
        */
        bool isVisited(int idx);
        Airport get_start;

    private:
        Graph graph_;
        int start_;
        std::queue<Airport> queue_;
        std::vector<bool> visited;
};