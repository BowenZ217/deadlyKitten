#pragma once

#include <string>

using std::string;


/**
 * Simple Node class containing the information of airports.
 */
struct Node {
    unsigned airport_id_;
    string name_;
    string city_;
    string country_;
    // Negative is South, positive is North.
    string latitude_;
    // Negative is West, positive is East.
    string longitude_;
    string altitude_;


    /**
     * Default constructor
     */
    Node();
    
    /**
     * Constructor
     * @param airport_ID Unique OpenFlights identifier for this airport.
     * @param name Name of airport. May or may not contain the City name.
     * @param city Main city served by airport. May be spelled differently from Name.
     * @param country Country or territory where airport is located.
     * @param latitude Decimal degrees, usually to six significant digits. Negative is South, positive is North.
     * @param longitude Decimal degrees, usually to six significant digits. Negative is West, positive is East.
     * @param altitude In feet.
     */
    Node(unsigned airport_id, string name, string city, string country, string latitude, string longitude, string altitude);

    /**
     * overload operator ==
     * @param other The other node
     * @return True for same airport, false for otherwise
     */
    bool operator==(const Node &other) const {
        return (airport_id_ == other.airport_id_ && name_ == other.name_ && city_ == other.city_ && country_ == other.country_);
    }
};