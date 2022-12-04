#pragma once
#include "Graph.h"
#include <algorithm>

class Centrality
{
    public:
        /**
         * The default constructor of Centrality.
        */
        Centrality();


        /**
         * @brief The constructor of Centrality.
         * @param graph the graph used to calculate the centrality of vertices.
        */
        Centrality(Graph graph);


        /**
         * @brief Fenerate all combination of two from the graph. One represents the source and the other
         * represents the destination.
        */
        std::vector<std::vector<int>> generate_combination();


        /**
         * @brief For each pair of souce and destination, find the shortest path using given algorithm and
         * record visited airports in frequency hash map
         * @param method algorithm chosen to find the shortest path between two vertices. Either it's
         * Dijkstra or FloydWarshall.
        */
        void calculate_centrality(std::string method);
   

    private:
        Graph* graph_;
        /**
         * Key represents the index of cities. Value represents the number of times a city has been 
         * visited in shortest paths. The central vertices have the highest frequencies.
        */ 
        std::unordered_map<int, int> frequency;
};