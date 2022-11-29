#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "Airport.h"
#include "Flight.h"
#include "FloydWarshall.h"
#include "utils.h"

using std::vector;
using std::string;
using std::unordered_map;

class Graph {
    public:
        // constructors

        /**
         * @brief Default constructor
         * 
         */
        Graph();

        /**
         * constructor by files
         * 
         * @param airportFileName name of file which store information of airports
         * @param routeFileName name of file which store information of routes
         * @param airlineFileName name of file which store information of airlines
         */
        Graph(const string& airportFileName, const string& routeFileName, const string& airlineFileName);

        // getter

        /**
         * @brief Find the Shortest Path from `source` to `destination`, with no other stops
         * 
         * @param source name of source airpot
         * @param destination name of destination airpot
         * 
         * @return name of airports need to go through (in order)
         */
        vector<string> getShortestPath(const string& source, const string& destination);

        /**
         * @brief Find the Shortest Path pass through all airports
         * 
         * @param airports Name of airports to pass through
         * 
         * @return name of airports need to go through (in order)
         */
        vector<string> getShortestPath(const vector<string>& airports);

        /**
         * overload operator = so that graph can be used as input to traversal.
        */

        Airport getAirport(int idx);

        int getSize();


        void operator=(const Graph &other) {
            size_ = other.size_;
            INF = 1e8;
            airpots_ = other.airpots_;
            id_to_airpot_ = other.id_to_airpot_;
            index_to_airpot_ = other.index_to_airpot_;
            flights_ = other.flights_;
            floyd_warshall_ = other.floyd_warshall_;
            flights_ = other.flights_;
        }

    private:
        // Define infinite
        int INF = 1e8;

        // variables
        unsigned size_;

        unordered_map<string, Airport> airpots_;
        unordered_map<int, Airport*> id_to_airpot_;
        vector<Airport*> index_to_airpot_;
        vector<unordered_map<int, Flight>> flights_;

        FloydWarshall floyd_warshall_;

        // helper functions
        double _calcWeight(const Flight& flight);

        void buildAirpots(const std::string& airportFileName);
        void buildFlights(const std::string& routeFileName);
        void buildFloydWarshall();
};
