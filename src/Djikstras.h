#pragma once

#include <string>
#include <vector>
#include <algorithm>
#pragma once


#include "utils.h"
//#include "BFS.h"

using std::vector;
using std::string;

class Djikstras {
    public:
        // constructors
        /**
         * @brief Default constructor
         * 
         */
        Djikstras();
        
        /**
         * @brief Construct a new Djikstras Warshall object
         * 
         * @param size number of vertex
         * @param graph each index is its weight of graph. 
         *      EX: graph[source][destination] = weight from source to destination. (INF for no edges)
         * @param source index of source airpot
         */
        Djikstras(unsigned size, const vector<vector<double>>& graph, int source);

        // seter

        /**
         * @brief Set the Source to new airport
         * 
         * @param source index of source airpot
         */
        void setSource(int source);

        // getter

        /**
         * @brief Find the Shortest Path from `source` to `destination`, with no other stops
         * 
         * @param destination index of destination airpot
         * 
         * @return index of airports need to go through (in order)
         */
        vector<int> getShortestPath(int destination);
    private:
        // Define infinite
        int INF = 1e8;

        // variables
        unsigned size_;
        int source_;
        
        vector<int> prev_;
        vector<int> dist_;
        vector<vector<double>> graph_;


        // helper function
        void initialise(const vector<vector<double>>& graph, int source);
};

