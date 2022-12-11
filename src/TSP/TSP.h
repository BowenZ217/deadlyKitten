#pragma once

#include <vector>
#include <string>

#include "UndirectedFullGraph.h"
#include "GA.h"

using std::vector;
using std::string;

class TSP {
    public:
        TSP();
        TSP(Graph* g, const vector<string>& vertexes);

        // seter
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
        // 机场数量
        int vertex_num_;
        // 个体数
        int individual_num_;
        // 迭代轮数
        int gen_num_;
        // 变异概率
        double mutate_prob_;

        Graph* g_;
        UndirectedFullGraph un_f_g_;
};
