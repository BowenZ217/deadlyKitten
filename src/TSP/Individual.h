#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits.h>

#include "UndirectedFullGraph.h"

using std::vector;

class Individual {
    public:
        /**
         * @brief Default constructor
         * 
         */
        Individual() : fitness_(INT_MAX / 100) { /* do nothing */};

        /**
         * @brief Individual of first generation, init with random gene
         * 
         * @param len length of gene
         * @param g graph, contain weight information
         */
        Individual(int len, UndirectedFullGraph* g);

        /**
         * @brief Individual of rest generation, init with given gene (create in `GA`)
         * 
         * @param genes gene created by two parants
         * @param g graph, contain weight information
         */
        Individual(const vector<int>& genes, UndirectedFullGraph* g);

        // getter
        /**
         * @brief Get the Genes of current Individual
         * 
         */
        vector<int> getGenes() const;
        /**
         * @brief Get the Fitness of current Individual
         * 
         */
        long double getFitness() const;

        // setter
        /**
         * @brief reset gene of current Individual
         * 
         * @param genes new genes
         * @param g graph, contain weight information
         */
        void resetGenes(const vector<int>& genes, UndirectedFullGraph* g);
    private:
        vector<int> genes_;
        long double fitness_;
        
        // helper functions
        void evaluate_fitness(UndirectedFullGraph* g);
};
