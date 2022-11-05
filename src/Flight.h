#pragma once

#include <string>

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
         * @param source_id 
         * @param destination_id 
         */
        Flight(int source_id, int destination_id);

        Flight(int airline_id, int source_id, int destination_id);
        Flight(int airline_id, std::string name, int source_id, int destination_id);

        // getters

        /**
         * @brief Get the Source Id of current flight
         * 
         * @return Source Id
         */
        int getSourceId();

        /**
         * @brief Get the Destination Id of current flight
         * 
         * @return Destination Id 
         */
        int getDestinationId();

        /**
         * @brief Get the name of current flight
         * 
         * @return flight name
         */
        std::string getName();

        // setters
    private:
        // do we need it?
        int airline_id_;
        std::string name_;
        int source_id_;
        int destination_id_;
};