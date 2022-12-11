#pragma once

#include <vector>
#include <string>

#include "UndirectedFullGraph.h"
#include "GA.h"

using std::vector;
using std::string;

/**
 * @brief Travelling salesman problem
 * 
 */
class TSP {
    public:
        /**
         * @brief Default constructor
         * 
         */
        TSP();

        /**
         * @brief Construct a new TSP object with Graph and vertexes
         * 
         * @param g graph, contains information
         * @param vertexes vertex need to go through
         */
        TSP(Graph* g, const vector<string>& vertexes);

        // seter
        /**
         * @brief reset current TSP object
         * 
         * @param g graph, contains information
         * @param vertexes vertex need to go through
         */
        void reset(Graph* g, const vector<string>& vertexes);

        /**
         * @brief Set Vertexes need to pass
         * 
         * @param vertexes Name of vertexes to pass through
         */
        void resetVertexes(const vector<string>& vertexes);

        // geter
        /**
         * @brief Find the Shortest Path pass through all airports
         * 
         * @return name of vertexes need to go through (in order)
         */
        vector<string> getShortestPath();
    private:
        // Number of vertexes
        int vertex_num_;
        // Number of Individuals
        int individual_num_;
        // Number of iteration rounds
        int gen_num_;
        // Mutation probability
        double mutate_prob_;

        Graph* g_;
        UndirectedFullGraph un_f_g_;
};
