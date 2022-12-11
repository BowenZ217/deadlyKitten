#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits.h>

#include "UndirectedFullGraph.h"

using std::vector;

class Individual {
    public:
        Individual() : fitness_(INT_MAX / 100) { /* do nothing */};
        Individual(int len, UndirectedFullGraph* g);
        Individual(const vector<int>& genes, UndirectedFullGraph* g);

        // getter
        vector<int> getGenes() const;
        long double getFitness() const;

        // setter
        void evaluate_fitness(UndirectedFullGraph* g);

        void resetGenes(const vector<int>& genes, UndirectedFullGraph* g);
    private:
        vector<int> genes_;
        long double fitness_;
};
