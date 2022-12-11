#include "GA.h"

GA::GA(UndirectedFullGraph* g, int size, int individual_num, int gen_num, double mutate_prob) {
    un_f_g_ = g;
    size_ = size;
    individual_num_ = individual_num;
    gen_num_ = gen_num;
    mutate_prob_ = mutate_prob;
}

/**
 * @brief Two indexes were randomly selected to exchange genes between parents
 *      (create two new Individuals)
 * 
 * @return new Individuals created
 */
vector<Individual> GA::cross() {
    vector<Individual> new_genes;

    random_shuffle(individual_list_.begin(), individual_list_.end());
    unordered_map<int, int> gene_1_match;
    unordered_map<int, int> gene_2_match;

    for (int i = 0; i < individual_num_ - 1; i += 2) {
        // calc the two index of region to cross between two parents
        int idx_1 = rand() % (size_ / 2);
        int step = rand() % (size_ / 2);
        if (idx_1 + step >= size_) continue;

        // genes of parents
        vector<int> genes1 = individual_list_[i].getGenes();
        vector<int> genes2 = individual_list_[i + 1].getGenes();
        gene_1_match.clear();
        gene_2_match.clear();
        for (int i = 0; i < size_; ++i) {
            gene_1_match[genes1[i]] = i;
            gene_2_match[genes2[i]] = i;
        }

        // take cross
        for (int idx = idx_1; idx < idx_1 + step; ++idx) {
            int value1 = genes1[idx];
            int value2 = genes2[idx];
            int pos1 = gene_1_match[value2];
            int pos2 = gene_2_match[value1];

            // swap
            genes1[idx] = genes1[pos1];
            genes1[pos1] = value1;
            genes2[idx] = genes2[pos2];
            genes2[pos2] = value2;

            gene_1_match[value1] = pos1;
            gene_1_match[value2] = idx;
            gene_2_match[value1] = idx;
            gene_2_match[value2] = pos2;
        }

        // finish, push it to `new_genes` for next step
        new_genes.push_back(Individual(genes1, un_f_g_));
        new_genes.push_back(Individual(genes2, un_f_g_));
    }

    return new_genes;
}

/**
 * @brief If the mutation condition is satisfied, 
 *      two indexes are randomly selected and the sequence 
 *      of the current gene between the two indexes is reversed
 * 
 * @param new_genes Genes waiting to undergo mutation
 */
void GA::mutate(vector<Individual> new_genes) {
    // for each new genes, there is a possibility of mutation
    for (Individual& individual : new_genes) {
        double r = (double) rand() / (RAND_MAX);
        // if mutation happen
        if (r < mutate_prob_) {
            // calc the two index of region
            int idx_1 = rand() % (size_ / 2);
            int step = rand() % (size_ / 2);
            if (idx_1 + step >= size_) continue;

            // Flip the order between two indexes
            vector<int> old = individual.getGenes();
            std::reverse(old.begin() + idx_1, old.begin() + idx_1 + step);
            individual.resetGenes(old, un_f_g_);
        }
        // put this new individual to `individual_list_`
        individual_list_.push_back(individual);
    }
}

/**
 * @brief Tournament Algorithm to slect
 * 
 */
void GA::select() {
    srand(time(NULL));
    // number of groups
    int group_num = 10;
    // number of people in each group
    int group_size = 10;
    // Winners per group
    int group_winner = individual_num_ / group_num;
    // results
    vector<Individual> winners;

    for (int i = 0; i < group_num; ++i) {
        vector<Individual> group;
        for (int j = 0; j < group_num; ++j) {
            // make a group randomly
            int player_idx = rand() % individual_list_.size();
            group.push_back(individual_list_[player_idx]);
        }
        sortGroup(group);
        // and pick the winner from each group
        for (int idx = 0; idx < group_winner; ++idx)
            winners.push_back(group[idx]);
    }
    individual_list_ = winners;
}

/**
 * @brief sort the vector from best fitness to low
 * 
 * @param group vector need to sort
 */
void GA::sortGroup(vector<Individual>& group) {
    std::sort(group.begin(), group.end(),
        [](const auto& a, const auto& b) {
            return a.getFitness() < b.getFitness();
        });
}

/**
 * @brief start to creat next generation, and update the best one
 * 
 */
void GA::next_gen() {
    // cross, then mutate
    mutate(cross());
    select();

    // and find the best in current generation
    for (const Individual& individual : individual_list_) {
        if (individual.getFitness() < best_.getFitness()) 
            best_ = individual;
    }
}

void GA::train() {
    _clean();

    // Initial population
    for (int i = 0; i < individual_num_; ++i)
        individual_list_.push_back(Individual(size_, un_f_g_));

    // Start of evolution
    for (int i = 0; i < gen_num_; ++i) {
        next_gen();
        result_list_.push_back(best_.getGenes());
        fitness_list_.push_back(best_.getFitness());
    }
}

// getter
vector<int>& GA::getLastResult() {
    return result_list_[result_list_.size() - 1];
}

vector<vector<int>>& GA::getResultList() {
    return result_list_;
}

vector<long double> GA::getFitnessList() {
    return fitness_list_;
}

/**
 * @brief reset all data
 * 
 */
void GA::_clean() {
    individual_list_.clear();
    result_list_.clear();
    fitness_list_.clear();
}
