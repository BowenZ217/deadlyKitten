#include "Node.h"

Node::Node() {
    /* do nothing */
}

Node::Node(const vector<string>& data) {
    // if received error
    if (data.size() != 7)
        throw std::invalid_argument("Wrong number of parameters");

    // init
    name_ = data[1];
    city_ = data[2];
    country_ = data[3];

    // if fail to transfer, will throw error
    airport_id_ = std::stoi(data[0]);
    latitude_ = std::stold(data[4]);
    longitude_ = std::stold(data[5]);
    altitude_ = std::stold(data[6]);
}

Node::Node(const string& airport_id, const string& name, const string& city, const string& country, const string& latitude, const string& longitude, const string& altitude) {
    // init
    name_ = name;
    city_ = city;
    country_ = country;

    airport_id_ = std::stoul(airport_id);
    latitude_ = std::stold(latitude);
    longitude_ = std::stold(longitude);
    altitude_ = std::stold(altitude);
}