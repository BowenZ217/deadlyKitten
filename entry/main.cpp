#include <iostream>
#include <string>
#include "cs225/PNG.h"

#include "Node.h"
#include "utils.h"

using namespace std;

int main()
{
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

    std::vector<Node> nodes;

    for (int i = 0; i < 10; ++i) {
        try {
            auto& curr = result[i];
            // remove unused data
            curr.erase(curr.begin() + 9, curr.end());
            curr.erase(curr.begin() + 4, curr.begin() + 6);
            nodes.push_back(Node(curr));
        }
        catch (const std::exception& e) {
            cout << "Node " << i << " meet error : " << e.what() << endl;
        }
    }

    // euclidean distance
    long double distance_1 = calcDistance(nodes[0].latitude_, nodes[0].longitude_, nodes[1].latitude_, nodes[1].longitude_);
    // Haversine formula
    long double distance_2 = calcDistance_2(nodes[0].latitude_, nodes[0].longitude_, nodes[1].latitude_, nodes[1].longitude_);

    cout << "distance from " << nodes[0].name_ << "(" << nodes[0].airport_id_ << ") to " << nodes[1].name_ << "(" << nodes[1].airport_id_ << "):\n";
    cout << "The euclidean distance = " << distance_1 << endl;
    cout << "Haversine formula distance = " << distance_2 << endl;

    cout << "\n-------------------------------------------\n\n";
    
    cout << endl << "finish." << endl;
    return 0;
}