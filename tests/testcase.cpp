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

bool compareVector(const vector<string>& actual, const vector<string>& vec) {
    unsigned size_ = actual.size();
    if (actual.size() != vec.size()) return false;
    for (unsigned i = 0; i < size_; ++i) {
        if (actual.at(i) != vec.at(i)) return false;
    }

    return true;
}

void printVector(const vector<string>& vec) {
    cout << "\n\n---------------\n\n";
    for (const auto& curr : vec) {
        cout << curr << " , ";
    }
    cout << "[end]\n";
    cout << "\n\n---------------\n\n";
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

TEST_CASE("Test Shorest Path V5 E12", "[shortest-path]") {
    string airportFileName = "../test_data/V5E12_vertex.csv";
    string routeFileName = "../test_data/V5E12_edge.csv";
    string shortestPathFileName = "../test_data/V5E12_shortest_path.csv";

    // init
    vector<vector<string>> shortest_path = fileToVector(shortestPathFileName);
    cout << "shortest_path size = " << shortest_path.size() << endl;
    Graph g(airportFileName, routeFileName);
    if (g.isConnected(0, 1)) {
        cout << "exist" << endl;
    } else {
        cout << "0 -> 1 not exist" << endl;
    }
    vector<string> path;

    // checking
    for (const auto& curr_p : shortest_path) {
        // cout << "curr_p size = " << curr_p.size() << endl;
        path = g.getShortestPath(curr_p[0], curr_p[curr_p.size() - 1]);
        // cout << " start checking" << endl;
        printVector(curr_p);
        printVector(path);
        REQUIRE(compareVector(curr_p, path));
        // cout << " end checking" << endl;
    }
}

TEST_CASE("Test Shortest Path V10 E50", "[shortest-path]") {
    string airportFileName = "../test_data/V10E50_vertex.csv";
    string routeFileName = "../test_data/V10E50_edge.csv";
    string shortestPathFileName = "../test_data/V10E50_shortest_path.csv";

    // init
    vector<vector<string>> shortest_path = fileToVector(shortestPathFileName);
    Graph g(airportFileName, routeFileName);
    vector<string> path;

    for (const auto& curr_p: shortest_path) {
        path = g.getShortestPath(curr_p[0], curr_p[curr_p.size() - 1]);
        compareVector(curr_p, path);
    }
}

TEST_CASE("Test Shortest Path V15 E30", "[shortest-path]") {
    
}

TEST_CASE("Test Centrality", "[Centrality]") {
    /*
    string airportFileName = "../data/airports.dat";
    string routeFileName = "../data/routes.dat";
    string airlineFileName = "../data/airlines.dat";

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
     */
}