#include <iostream>
#include <string>
#include "TSP/UndirectedFullGraph.h"

using namespace std;

int main()
{
    string airportFileName = "../test_data/V10E30_vertex.csv";
    string routeFileName = "../test_data/V10E30_edge.csv";

    Graph g(airportFileName, routeFileName);

    vector<string> v = {"vertex-0", "vertex-3", "vertex-5", "vertex-7"};

    UndirectedFullGraph unFullGraph(&g, v);

    unFullGraph.printWeight();

    return 0;
}