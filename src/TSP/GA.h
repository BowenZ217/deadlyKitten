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
        /**
         * @brief Default constructor
         * 
         */
        GA() { /* do nothing */ };

        /**
         * @brief constructor for a new GA object
         * 
         * @param g graph, with its weight information
         * @param size number of vertex
         * @param individual_num number of individuals
         * @param gen_num number of iteration rounds
         * @param mutate_prob mutation probability
         */
        GA(UndirectedFullGraph* g, int size, int individual_num, int gen_num, double mutate_prob);

        /**
         * @brief Start training and calculate the best path
         * 
         */
        void train();

        // getter
        /**
         * @brief Get the Last Result path
         * 
         * @return shortest path connect all vertex
         */
        vector<int>& getLastResult();

        /**
         * @brief Get all the best Result in each round
         * 
         * @return vector of shortest path
         */
        vector<vector<int>>& getResultList();

        /**
         * @brief Get the all best Fitness in each round
         * 
         * @return vector of Fitness
         */
        vector<long double> getFitnessList();
    private:
        // The best individuals of each generation
        Individual best_;
        // List of individuals per generation
        vector<Individual> individual_list_;
        // best solution for each generation
        vector<vector<int>> result_list_;
        // best Fitness for each generation
        vector<long double> fitness_list_;

        // number of individuals
        int individual_num_;
        // number of iteration rounds
        int gen_num_;
        // mutation probability
        double mutate_prob_;

        int size_;
        // graph, with its weight information
        UndirectedFullGraph* un_f_g_;

        // helper function
        void _clean();
        
        void mutate(vector<Individual> new_genes);

        void select();

        void sortGroup(vector<Individual>& group);

        void next_gen();

        vector<Individual> cross();
};
