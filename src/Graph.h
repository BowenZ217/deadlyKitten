#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "Airport.h"
#include "Flight.h"
#include "FloydWarshall.h"
#include "utils.h"
#include "Djikstras.h"

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
         * @brief Get Airport using index
         * 
         * @param idx index of airport
         * @return Airport 
         */
        Airport* getAirport(int idx);

        /**
         * @brief Get the size of graph
         * 
         * @return number of nodes 
         */
        int getSize();

        /**
         * @brief Get the Neighbors of airport
         * 
         * @param idx index of that airport
         * @return neighbors
         */
        vector<Airport*> getNeighbors(int idx);
        
        // helper functions
        /**
         * @brief Calculate the weights between two airpots
         *
         * @param flight current flight
         *
         * @return weight of current flight
         */
        long double _calcWeight(const Flight& flight);

        /**
         * @brief Calculate the weights between two airpots using index
         *
         * @param source index of source
         * @param destination index of destination
         *
         * @return weight
         */
        long double _calcWeight(int source_idx, int destination_idx);

        /**
         * @brief overload operator = so that graph can be used as input to traversal.
         */
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
        Djikstras djikstras;

        void buildAirpots(const std::string& airportFileName);
        void buildFlights(const std::string& routeFileName);
        void buildFloydWarshall();
        void buildDjikstras();
};
