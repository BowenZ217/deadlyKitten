#pragma once

#include <vector>
#include <string>

#include "utils.h"

using std::vector;
using std::string;

class FloydWarshall {
    public:
        // constructors
        /**
         * @brief Default constructor
         * 
         */
        FloydWarshall();

        /**
         * @brief Construct a new Floyd Warshall using a file
         * 
         * @param fileName name of file which contains the data save before
         */
        FloydWarshall(const string& fileName);
        
        /**
         * @brief Construct a new Floyd Warshall object
         * 
         * @param size number of vertex
         * @param graph each index is its weight of graph. 
         *      EX: graph[source][destination] = weight from source to destination. (INF for no edges)
         */
        FloydWarshall(unsigned size, const vector<vector<double>>& graph);

        // getter

        /**
         * @brief Find the Shortest Path from `source` to `destination`, with no other stops
         * 
         * @param source index of source airpot
         * @param destination index of destination airpot
         * 
         * @return index of airports need to go through (in order)
         */
        vector<int> getShortestPath(int source, int destination);
    private:
        // Define infinite
        int INF = 1e8;

        // variables
        unsigned size_;
        vector<vector<int>> next_;

        // helper function
        void initialise(const vector<vector<double>>& graph);
};
