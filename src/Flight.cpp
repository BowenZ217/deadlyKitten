#include "Flight.h"

Flight::Flight() {
    /* do nothing */
}

Flight::Flight(int airline_id, int source_id, int destination_id, int stops) {
    airline_id_ = airline_id;
    source_id_ = source_id;
    destination_id_ = destination_id;
    stops_ = stops;
}

Flight::Flight(const vector<string>& data) {
    // if received error
    if (data.size() != 4)
        throw std::invalid_argument("Wrong number of parameters");

    // if fail to transfer, will throw error
    airline_id_ = std::stoi(data[0]);
    source_id_ = std::stoi(data[1]);
    destination_id_ = std::stoi(data[2]);
    stops_ = std::stoi(data[3]);
}

int Flight::getAirlineID() {
    return airline_id_;
}

int Flight::getAirlineID() const {
    return airline_id_;
}

int Flight::getSourceId() {
    return source_id_;
}

int Flight::getSourceId() const {
    return source_id_;
}

int Flight::getDestinationId() {
    return destination_id_;
}

int Flight::getDestinationId() const {
    return destination_id_;
}

int Flight::getStops() {
    return stops_;
}

int Flight::getStops() const {
    return stops_;
}

void Flight::setStops(int stops) {
    stops_ = stops;
}

void Flight::setAirlineID(int id) {
    airline_id_ = id;
}
