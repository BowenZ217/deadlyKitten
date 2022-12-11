#include "Individual.h"

Individual::Individual(int len, UndirectedFullGraph* g) {
    // create random gene
    for (int i = 0; i < len; ++i) {
        genes_.push_back(i);
    }
    random_shuffle(genes_.begin(), genes_.end());

    evaluate_fitness(g);
}

Individual::Individual(const vector<int>& genes, UndirectedFullGraph* g) {
    genes_ = genes;
    evaluate_fitness(g);
}

vector<int> Individual::getGenes() const {
    return genes_;
}

long double Individual::getFitness() const {
    return fitness_;
}

void Individual::resetGenes(const vector<int>& genes, UndirectedFullGraph* g) {
    genes_ = genes;
    evaluate_fitness(g);
}

/**
 * @brief calc current Fitness
 * 
 * @param g graph, contain weight information
 */
void Individual::evaluate_fitness(UndirectedFullGraph* g) {
    fitness_ = 0;
    int path_num = genes_.size() - 1;
    for (int i = 0; i < path_num; ++i) {
        long double weight = g->getPathWeight(genes_[i], genes_[i + 1]);
        if (weight == -1) throw std::invalid_argument("have a path not exist");
        fitness_ += weight;
    }
    fitness_ += g->getPathWeight(genes_[path_num], genes_[0]);
}
