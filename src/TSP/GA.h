#pragma once

#include <algorithm>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <unordered_map>
#include "Individual.h"
#include "TSP.h"

using std::unordered_map;

class GA {
    public:
        GA() { /* do nothing */ };

        GA(UndirectedFullGraph* g, int size, int individual_num, int gen_num, double mutate_prob);

        vector<Individual> cross();

        void mutate(vector<Individual> new_genes);

        void select();

        void rank(vector<Individual>& group);

        void next_gen();

        void train();

        // getter
        vector<int>& getLastResult();

        vector<vector<int>>& getResultList();

        vector<long double> getFitnessList();
    private:
        // 每一代的最佳个体
        Individual best_;
        // 每一代的个体列表
        vector<Individual> individual_list_;
        // 每一代对应的解
        vector<vector<int>> result_list_;
        // 每一代对应的适应度
        vector<long double> fitness_list_;

        // 个体数
        int individual_num_;
        // 迭代轮数
        int gen_num_;
        // 变异概率
        double mutate_prob_;

        int size_;
        UndirectedFullGraph* un_f_g_;

        // helper function
        void _clean();
};
