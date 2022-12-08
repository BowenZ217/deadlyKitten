#include <catch2/catch_test_macros.hpp>

#include "utils.h"
#include "Graph.h"
#include "Centrality.h"
#include "Dijkstra.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::vector;
bool compareVector(const vector<vector<string>>& actual, const vector<vector<string>>& vec, unsigned size) {
    unsigned actual_size = actual.size();

    if (actual_size != vec.size()) return false;

    for (unsigned i = 0; i < actual_size; ++i) {
        if (actual.at(i).size() != size || vec.at(i).size() != size) return false;

        for (unsigned j = 0; j < size; ++j) {
            if (actual.at(i).at(j) != vec.at(i).at(j)) return false;
        }
    }

    return true;
}

TEST_CASE("Test datToVector", "[utils]") {
    string file_name = "../tests/test_dat_to_vector.dat";

    vector<vector<string>> actual
    {
        {"freedom","guidance","tongue","cigarette","debt"},
        {"assistance","proposal","flight","highway","depth"},
        {"advice","blood","alcohol","classroom","education"},
        {"engine","throat","celebration","television","oven"}
    };

    vector<vector<string>> result = fileToVector(file_name, 5);

    REQUIRE(compareVector(actual, result, 5));
}

TEST_CASE("Test Graph Correctness") {
    // TODO: Move test cases in main to here.
}

TEST_CASE("Test Shorest Path", "five-vertices") {
}

TEST_CASE("Test Shortest Path", "ten-vertices") {

}

TEST_CASE("Test Shortest Path", "fifteen-vertices") {
    
}

TEST_CASE("Test Centrality", "small graph") {
    Graph* graph = new Graph(airportFileName, routeFileName, airlineFileName);
    Centrality centrality(graph);
    // This is a vector of expected frequency for the test graph
    // We might use networkx to calculate?
    std::vector<int> expected ={6, 4, 3, 3, 1};

    centrality.calculate_centrality();

    for (unsigned i = 0; i < expected.size(); i++) {
        // Might define public getter to get those values
        std::string airportName = centrality.graph_->getAirport(i)->name_;

        int expectedFreq = expected[i];
        // Need to define public getter to get frequency
        int actualFreq = centrality.frequency_[airportName];

        REQUIRE(actualFreq == expectedFreq);
    }
    delete graph;
}