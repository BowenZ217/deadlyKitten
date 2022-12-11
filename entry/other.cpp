#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "cs225/PNG.h"

#include "Airport.h"
#include "Graph.h"
#include "graphTraversal/BFS.h"
#include "TSP/TSP.h"
#include "Centrality.h"
#include "utils.h"

using namespace std;

void example1();
void example2();
void example3();
void example4();
void example5();
void example6();
void example7();


int main()
{
    example7();
    return 0;
}

/**
 * @brief function to check `fileToVector()` works
 * 
 */
void example1() {
    string file_name = "../data/airports.dat";
    auto result = fileToVector(file_name, 14);
    cout << "\"" << file_name << "\" size = " << result.size() << endl;

    cout << endl << "first line data:" << endl;
    for (string curr : result.at(0)) {
        cout << curr << " | ";
    }
    cout << endl << endl;
    cout << "Latitude = " << result[0][6] << ", Longitude = " << result[0][7] << endl;
    cout << endl;

    cout << "\n-------------------------------------------\n\n";

    std::vector<Airport> airports;
    unsigned idx = 0;

    for (int i = 0; i < 10; ++i) {
        try {
            auto& curr = result[i];
            // remove unused data
            curr.erase(curr.begin() + 8, curr.end());
            curr.erase(curr.begin() + 4, curr.begin() + 6);
            airports.push_back(Airport(idx++, curr));
        }
        catch (const std::exception& e) {
            cout << "Node " << i << " meet error : " << e.what() << endl;
        }
    }

    // euclidean distance
    long double distance_1 = calcDistance(airports[0].latitude_, airports[0].longitude_, airports[1].latitude_, airports[1].longitude_);
    // Haversine formula
    long double distance_2 = calcDistance_2(airports[0].latitude_, airports[0].longitude_, airports[1].latitude_, airports[1].longitude_);

    cout << "distance from " << airports[0].name_ << "(" << airports[0].airport_id_ << ") to " << airports[1].name_ << "(" << airports[1].airport_id_ << "):\n";
    cout << "The euclidean distance = " << distance_1 << endl;
    cout << "Haversine formula distance = " << distance_2 << endl;

    cout << "\n-------------------------------------------\n\n";
    
    cout << endl << "finish." << endl;
}

/**
 * @brief function to check the getShortestPath for one source and one destination
 * 
 * EX:
 *  source = "Goroka Airport";
 *  destination = "Gerardo Tobar López Airport";
 * 
 *  Output:
 *  Goroka Airport -> Port Moresby Jacksons International Airport -> Singapore Changi Airport 
 *                 -> King Abdulaziz International Airport -> Mohammed V International Airport 
 *                 -> Tenerife Norte Airport -> Simón Bolívar International Airport 8 -> El Dorado International Airport 
 *                 -> Gerardo Tobar López Airport -> [end]
 * 
 */
void example2() {
    string airportFileName = "../data/airports.dat";
    string routeFileName = "../data/routes.dat";
    string airlineFileName = "../data/airlines.dat";

    Graph g(airportFileName, routeFileName, airlineFileName);

    
    vector<string> stops = readInput();
    vector<string> path;

    while (stops.size() == 2) {
        cout << "\n\n-----------------------------------------------------\n\n";

        path = g.getShortestPath(stops[0], stops[1]);

        if (path.empty()) {
            cout << "can not find path between them." << endl;
        }
        else {
            cout << "find the path from \"" << stops[0] << "\" to \"" << stops[1] << "\": " << endl;
            for (const auto& name : path) {
                cout << name << " -> ";
            }
            cout << "[end]" << endl;
        }
        cout << "\n-----------------------------------------------------\n\n";

        // update for next loop
        stops = readInput();
    }
}

/**
 * @brief function to check `vectorToFile()` works
 * 
 */
void example3() {
    vector<vector<int>> data
        = { { 0, 3, -1, 7 },
            { 8, 0, 2, -1 },
            { 5, -1, 0, 1 },
            { 2, -1, -1, 0 } };
    vectorToFile("temp.txt", data);

    cout << "\n\n-----------------------------------------------------\n\n";
    vector<vector<int>> read = fileToIntVector("path.save", 4);
    for (const auto& line : read) {
        for (const auto& c : line) {
            cout << c << " , ";
        }
        cout << "[end]\n";
    }
    cout << "\n-----------------------------------------------------\n\n";
}

void example4() {
    string airportFileName = "../data/airports.dat";
    string routeFileName = "../data/routes.dat";
    string airlineFileName = "../data/airlines.dat";

    Graph g(airportFileName, routeFileName, airlineFileName);

    BFS bfs(&g, 0);

    for (auto curr : bfs) {
        // curr is a pointer of airport
        cout << "current airport : " << curr->name_ << " , idx = " << curr->index_ << endl;
    }
}

void example5() {
    string airportFileName = "../data/airports.dat";
    string routeFileName = "../data/routes.dat";
    string airlineFileName = "../data/airlines.dat";

    Graph g(airportFileName, routeFileName, airlineFileName);
    
    Centrality centrality(&g);

    centrality.calculate_centrality();

    vector<pair<string, int>> sorted_freq;
    for (const auto& curr : centrality.frequency_) {
        sorted_freq.push_back(make_pair(curr.first, curr.second));
    }
    sort(sorted_freq.begin(), sorted_freq.end(), 
        [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

    for (int i = 0; i < 10; ++i) {
        cout << i << " : " << sorted_freq[i].first << " , " << sorted_freq[i].second << endl;
    }
}

void example6() {
    string airportFileName = "../test_data/V10E30_vertex.csv";
    string routeFileName = "../test_data/V10E30_edge.csv";

    Graph g(airportFileName, routeFileName);

    vector<string> v = {"vertex-0", "vertex-3", "vertex-5", "vertex-7"};

    TSP tsp(&g, v);
    vector<string> path = tsp.getShortestPath();

    cout << "\n\n---------------------------\n\n";
    cout << "tsp: ";
    printVector(path);
    cout << "\n---------------------------\n\n";

    double inf = INT_MAX / 100;
    vector<vector<double>> g_w = {  { inf, 1, 1000, 1000 },
                                    { 1000, inf, 1, 1000 },
                                    { 1000, 1000, inf, 1 },
                                    { 1, 1000, 1000, inf } };
    int vertex_num = 4;
    int individual_num = 60;
    int gen_num = 400;
    double mutate_prob = 0.4;

    UndirectedFullGraph g_2 = UndirectedFullGraph(g_w);

    GA ga(&g_2, vertex_num, individual_num, gen_num, mutate_prob);
    ga.train();
    // path should be 0 -> 1 -> 2 -> 3 -> 0
    // or 1 -> 2 -> 3 -> 0 -> 1
    // ... something like this
    vector<int> result_idx = ga.getLastResult();

    cout << "check GA: ";
    printVector(result_idx);
    cout << "\n---------------------------\n\n";
}

void example7() {
    string airportFileName = "../data/airports.dat";
    string routeFileName = "../data/routes.dat";
    string airlineFileName = "../data/airlines.dat";

    Graph g(airportFileName, routeFileName, airlineFileName);
    
    Centrality centrality(&g);

    centrality.calculate_centrality();

    vector<pair<string, int>> sorted_freq;
    for (const auto& curr : centrality.frequency_) {
        sorted_freq.push_back(make_pair(curr.first, curr.second));
    }
    sort(sorted_freq.begin(), sorted_freq.end(), 
        [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

    vector<string> centrality_top_10;
    for (int i = 0; i < 10; ++i) {
        centrality_top_10.push_back(sorted_freq[i].first);
        cout << i << " : " << sorted_freq[i].first << " , " << sorted_freq[i].second << endl;
    }
    cout << "\n---------------------------\n\n";

    TSP tsp(&g, centrality_top_10);
    vector<string> path = tsp.getShortestPath();

    cout << "shortest path to connect them (inorder): ";
    printVector(path);
    cout << "\n---------------------------\n\n";
}
