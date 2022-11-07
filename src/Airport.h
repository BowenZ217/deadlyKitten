#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

using std::vector;
using std::string;
using std::cout;


/**
 * Simple Node class containing the information of airports.
 */
struct Airport {
    unsigned airport_id_;
    string name_;
    string city_;
    string country_;
    // Negative is South, positive is North.
    long double latitude_;
    // Negative is West, positive is East.
    long double longitude_;
    long double altitude_;


    /**
     * Default constructor
     */
    Airport();
    
    /**
     * constructor by using a vector of data
     */
    Airport(const vector<string>& data);
    /**
     * Constructor
     * 
     * @param airport_ID Unique OpenFlights identifier for this airport.
     * @param name Name of airport. May or may not contain the City name.
     * @param city Main city served by airport. May be spelled differently from Name.
     * @param country Country or territory where airport is located.
     * @param latitude Decimal degrees, usually to six significant digits. Negative is South, positive is North.
     * @param longitude Decimal degrees, usually to six significant digits. Negative is West, positive is East.
     * @param altitude In feet.
     */
    Airport(const string& airport_id, const string& name, const string& city, const string& country, const string& latitude, const string& longitude, const string& altitude);

    /**
     * overload operator ==
     * @param other The other node
     * @return True for same airport, false for otherwise
     */
    bool operator==(const Airport &other) const {
        return (airport_id_ == other.airport_id_ && name_ == other.name_ && city_ == other.city_ && country_ == other.country_);
    }
};