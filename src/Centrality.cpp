#include "Centrality.h"

Centrality::Centrality() {}

Centrality::Centrality(Graph* graph) {
    graph_ = graph;
    int graph_size = graph_->getSize();

    // Initialize the hashmap
    for (int i = 0; i < graph_size; i++) {
        Airport* airport = graph_->getAirport(i);
        frequency_[airport->name_] = 0;
    }

    combinations_ = generate_combination();
}

std::vector<std::vector<int>> Centrality::generate_combination() {
    std::vector<std::vector<int>> combinations;
    for (int i = 0; i < graph_->getSize() - 1; i++) {
        for (int j = i + 1; j < graph_->getSize(); j++) {
            std::vector<int> temp;
            temp.push_back(i);
            temp.push_back(j);
            combinations.push_back(temp);
        }
    }

    return combinations;
}

void Centrality::calculate_centrality() {
    for (auto const &comb: combinations_) {
        std::string const source = graph_->getAirport(comb[0])->name_;
        std::string const destination = graph_->getAirport(comb[1])->name_;
        // Find the shortest path.
        vector<std::string> shortestPath = graph_->getShortestPath(source, destination);

        // For each airport appears in the shortest path, update its frequency in the hash map.
        for (auto const &name: shortestPath) {
            frequency_[name]++;
        }
    }
}