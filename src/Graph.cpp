#include "Graph.h"

Graph::Graph() {
    /* do nothing */
}

Graph::Graph(const string& airportFileName, const string& routeFileName) {
    buildAirpotsClean(airportFileName);
    buildFlightsClean(routeFileName);
    buildFloydWarshall();
}

Graph::Graph(const string& airportFileName, const string& routeFileName, const string& airlineFileName) {
    buildAirpots(airportFileName);
    buildFlights(routeFileName);
    buildFloydWarshall();
    
}

vector<string> Graph::getShortestPath(const string& source, const string& destination) {
    vector<string> path;

    // check if exist
    if (airpots_.find(source) == airpots_.end() || airpots_.find(destination) == airpots_.end()) {
        cout << "one of airport not exist." << endl;
        return path;
    }

    vector<int> path_idx = floyd_warshall_.getShortestPath(airpots_[source].index_, airpots_[destination].index_);

    // transfor from airport index to name
    for (const int& idx : path_idx) {
        path.push_back(index_to_airpot_[idx]->name_);
    }

    return path;
}

vector<string> Graph::getShortestPath(const vector<string>& airports) {
    /// @todo
    vector<string> path;

    return path;
}

Airport* Graph::getAirport(int idx) {
    return index_to_airpot_[idx];
}

Airport Graph::getAirport(std::string name) {
    return airpots_[name];
}

int Graph::getSize() {
    return size_;
}

vector<Airport*> Graph::getNeighbors(int idx) {
    vector<Airport*> neighbors;

    for (const auto& curr : flights_[idx]) {
        neighbors.push_back(index_to_airpot_[curr.first]);
    }

    return neighbors;
}

bool Graph::isConnected(int s_idx, int d_idx) {
    return flights_[s_idx].find(d_idx) != flights_[s_idx].end();
}

// helper functions
long double Graph::_calcWeight(const Flight& flight) {
    // find airports using id
    Airport* source = id_to_airpot_[flight.getSourceId()];
    Airport* destination = id_to_airpot_[flight.getDestinationId()];

    // do the calculate
    return calcDistance(source->latitude_, source->longitude_, destination->latitude_, destination->longitude_) + flight.getStops() * 50;
}

long double Graph::_calcWeight(int source_idx, int destination_idx) {
    // find airports using id
    Airport* source = index_to_airpot_[source_idx];
    Airport* destination = index_to_airpot_[destination_idx];

    // do the calculate
    return calcDistance(source->latitude_, source->longitude_, destination->latitude_, destination->longitude_);
}

/**
 * @brief helper function to initialize `airpots_`
 * 
 * @param airportFileName name of file which store information of airports
 */
void Graph::buildAirpots(const std::string& airportFileName) {
    // init
    vector<vector<string>> data = fileToVector(airportFileName, 14);
    size_ = 0;
    int i = 1;

    // insert data
    for (auto& curr_data : data) {
        try {
            // remove unused data
            curr_data.erase(curr_data.begin() + 8, curr_data.end());
            curr_data.erase(curr_data.begin() + 4, curr_data.begin() + 6);

            // check if it is repeated
            auto it = airpots_.find(curr_data[1]);
            if (it != airpots_.end()) {
                // cout << "Airport name: \"" << curr_data[1] << "\" is repeated.\n";
                curr_data[1] = curr_data[1] + " " + std::to_string(i++);
                // cout << "change it's name to \"" << curr_data[1] << "\"." << endl << endl;
            }
            // try to add this airport
            airpots_[curr_data[1]] = Airport(size_++, curr_data);
            id_to_airpot_[std::stoi(curr_data[0])] = &(airpots_[curr_data[1]]);
            index_to_airpot_.push_back(&(airpots_[curr_data[1]]));
        }
        catch (const std::exception& e) {
            // if meet error
            // cout << "Airport id : " << curr_data[0] << " meet error : " << e.what() << endl;
        }
    }
    flights_.resize(size_);
}

/**
 * @brief helper function to initialize `flights_`
 * 
 * @param airportFileName name of file which store information of routes
 */
void Graph::buildFlights(const std::string& routeFileName) {
    // init
    vector<vector<string>> data = fileToVector(routeFileName, 9);

    // insert data
    for (auto& curr_data : data) {
        try {
            // remove unused data
            curr_data.erase(curr_data.begin() + 8, curr_data.end());
            curr_data.erase(curr_data.begin() + 6, curr_data.begin() + 7);
            curr_data.erase(curr_data.begin() + 4, curr_data.begin() + 5);
            curr_data.erase(curr_data.begin() + 2, curr_data.begin() + 3);
            curr_data.erase(curr_data.begin(), curr_data.begin() + 1);

            // try to add this airport
            auto source = id_to_airpot_.find(std::stoi(curr_data[1]));
            auto destination = id_to_airpot_.find(std::stoi(curr_data[2]));

            // check if airport not exist
            if (source == id_to_airpot_.end() || destination == id_to_airpot_.end()) {
                // cout << "sourse id = " << curr_data[1] << " to destination id = " << curr_data[2] << " can not exist." << endl;
                continue;
            }

            // also check if it is repeated
            auto it = flights_[source->second->index_].find(destination->second->index_);
            if (it != flights_[source->second->index_].end()) {
                // if is, compare with prev one, take the one with smaller stops
                int curr_stops = std::stoi(curr_data[3]);
                if (it->second.getStops() > curr_stops) {
                    it->second.setStops(curr_stops);
                    it->second.setAirlineID(std::stoi(curr_data[0]));
                }
                continue;
            }

            flights_[source->second->index_][destination->second->index_] = Flight(curr_data);
        }
        catch (const std::exception& e) {
            // if meet error
            // cout << "Airport id : " << curr_data[0] << " meet error : " << e.what() << endl;
        }
    }
}

/**
 * @brief helper function to initialize `airpots_` with cleaned data
 * 
 * @param airportFileName name of file which store information of airports
 */
void Graph::buildAirpotsClean(const std::string& airportFileName) {
    // init
    vector<vector<string>> data = fileToVector(airportFileName, 6);
    size_ = 0;
    int i = 1;

    // insert data
    for (auto& curr_data : data) {
        try {
            // check if it is repeated
            auto it = airpots_.find(curr_data[1]);
            if (it != airpots_.end()) {
                // cout << "Airport name: \"" << curr_data[1] << "\" is repeated.\n";
                curr_data[1] = curr_data[1] + " " + std::to_string(i++);
                // cout << "change it's name to \"" << curr_data[1] << "\"." << endl << endl;
            }
            // try to add this airport
            airpots_[curr_data[1]] = Airport(size_++, curr_data);
            id_to_airpot_[std::stoi(curr_data[0])] = &(airpots_[curr_data[1]]);
            index_to_airpot_.push_back(&(airpots_[curr_data[1]]));
        }
        catch (const std::exception& e) {
            // if meet error
            // cout << "Airport id : " << curr_data[0] << " meet error : " << e.what() << endl;
        }
    }
    flights_.resize(size_);
}

/**
 * @brief helper function to initialize `flights_` with cleaned data
 * 
 * @param airportFileName name of file which store information of routes
 */
void Graph::buildFlightsClean(const std::string& routeFileName) {
    // init
    vector<vector<string>> data = fileToVector(routeFileName, 4);

    // insert data
    for (auto& curr_data : data) {
        try {
            // try to add this airport
            auto source = id_to_airpot_.find(std::stoi(curr_data[1]));
            auto destination = id_to_airpot_.find(std::stoi(curr_data[2]));

            // check if airport not exist
            if (source == id_to_airpot_.end() || destination == id_to_airpot_.end()) {
                // cout << "sourse id = " << curr_data[1] << " to destination id = " << curr_data[2] << " can not exist." << endl;
                continue;
            }

            // also check if it is repeated
            auto it = flights_[source->second->index_].find(destination->second->index_);
            if (it != flights_[source->second->index_].end()) {
                // if is, compare with prev one, take the one with smaller stops
                int curr_stops = std::stoi(curr_data[3]);
                if (it->second.getStops() > curr_stops) {
                    it->second.setStops(curr_stops);
                    it->second.setAirlineID(std::stoi(curr_data[0]));
                }
                continue;
            }

            else flights_[source->second->index_][destination->second->index_] = Flight(curr_data);
        }
        catch (const std::exception& e) {
            // if meet error
            // cout << "Airport id : " << curr_data[0] << " meet error : " << e.what() << endl;
        }
    }
}

/**
 * @brief helper function to build the `floyd_warshall_`, for find shortest path between two airpots
 * 
 */
void Graph::buildFloydWarshall() {
    // init
    vector<vector<double>> weight = vector<vector<double>>(size_, vector<double>(size_, INF));

    // calc the weight
    for (size_t source_id = 0; source_id < size_; ++source_id) {
        for (const auto& curr_p : flights_[source_id]) {
            weight[source_id][curr_p.first] = _calcWeight(curr_p.second);
        }
    }

    // and setup
    floyd_warshall_ = FloydWarshall(size_, weight);
    
}

/*void Graph::buildDijkstra(){
    vector<vector<double>> weight = vector<vector<double>>(size_, vector<double>(size_, INF));
    int source = 0;
    // calc the weight
    for (size_t source_id = 0; source_id < size_; ++source_id) {
        for (const auto& curr_p : flights_[source_id]) {
            weight[source_id][curr_p.first] = _calcWeight(curr_p.second);
        }
        //store source index
        //source.push_back((int)source_id);
    }
    // and setup
    dijkstra = Dijkstra(size_, weight,source);
}*/