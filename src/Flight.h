#pragma once

#include <stdexcept>
#include <string>
#include <vector>

using std::vector;
using std::string;

class Flight {
    public:
        // constructors

        /**
         * @brief Default constructor
         * 
         */
        Flight();

        /**
         * @brief Constructor with sorce and destination
         * 
         * @param airline_id
         * @param source_id 
         * @param destination_id 
         */
        Flight(int airline_id, int source_id, int destination_id, int stops);

        /**
         * constructor by using a vector of data
         */
        Flight(const vector<string>& data);

        // getters

        /**
         * @brief Get the airline id of current flight
         * 
         * @return Airline Id
         */
        int getAirlineID();

        /**
         * @brief Get the airline id of current flight
         * 
         * @return Airline Id
         */
        int getAirlineID() const;

        /**
         * @brief Get the Source Id of current flight
         * 
         * @return Source Id
         */
        int getSourceId();

        /**
         * @brief Get the Source Id of current flight
         * 
         * @return Source Id
         */
        int getSourceId() const;

        /**
         * @brief Get the Destination Id of current flight
         * 
         * @return Destination Id 
         */
        int getDestinationId();

        /**
         * @brief Get the Destination Id of current flight
         * 
         * @return Destination Id 
         */
        int getDestinationId() const;

        /**
         * @brief Get the stops of current flight
         * 
         * @return stops
         */
        int getStops();

        /**
         * @brief Get the stops of current flight
         * 
         * @return stops
         */
        int getStops() const;

        // setters

        /**
         * @brief Reset the stops of current flight
         *
         */
        void setStops(int stops);

        /**
         * @brief Reset the airline id of current flight
         *
         */
        void setAirlineID(int id);

    private:
        // do we need it?
        int airline_id_;
        // do we also need it?
        int source_id_;
        int destination_id_;
        int stops_;
};
