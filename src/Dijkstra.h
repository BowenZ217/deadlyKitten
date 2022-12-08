#pragma once

#include <string>
#include <vector>
#include <algorithm>
#pragma once


#include "utils.h"
//#include "BFS.h"

using std::vector;
using std::string;

class Dijkstra {
    public:
        // constructors
        /**
         * @brief Default constructor
         * 
         */
        Dijkstra();
        
        /**
         * @brief Construct a new Dijkstra Warshall object
         * 
         * @param size number of vertex
         * @param graph each index is its weight of graph. 
         *      EX: graph[source][destination] = weight from source to destination. (INF for no edges)
         * @param source index of source airpot
         */
        Dijkstra(unsigned size, const vector<vector<double>>& graph, int source);

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
        
        void ShortestPath(int source);
        vector<int> getShortestPath(int destination);
        vector<double> getShortestDistance();
        double getShortestDistance(int destination);
    private:
        // Define infinite
        int INF = 1e8;

        // variables
        unsigned size_;
        int source_;
        
        vector<int> prev_;
        vector<double> dist_;
        vector<vector<double>> graph_;
        vector<vector<std::pair<int, double>>> adjAirport;
        


        // helper function
        void initialise(const vector<vector<double>>& graph, int source);
};

