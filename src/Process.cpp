#include "Process.h"

void process(const string& inputFileName, const string& outputFileName) {
    string output;
    string interval = "\n----------------------------------------\n\n";

    // init
    unordered_map<string, string> data = fileToMap(inputFileName);
    Graph g(data["airport file name"], data["route file name"], data["airline file name"]);

    cout << "init finish" << endl;

    // do process in step
    if (data["shortest path (Floyd Warshall) state"] == "true") {
        processFW(output, g, data["shortest path (Floyd Warshall) source"], data["shortest path (Floyd Warshall) destination"]);
        output += interval;
    }
    cout << "shortest path (Floyd Warshall) finish" << endl;
    if (data["shortest path (Dijkstra) state"] == "true") {
        processDij(output, g, data["shortest path (Dijkstra) source"], data["shortest path (Dijkstra) destination"]);
        output += interval;
    }
    cout << "shortest path (Dijkstra) finish" << endl;
    if (data["centrality state"] == "true") {
        processCent(output, g, data["centrality(nmber of top)"], data["shortest path connect top centrality"]);
        output += interval;
    }
    cout << "centrality finish" << endl;
    if (data["TSP state"] == "true") {
        processTSP(output, g, data["vertex"]);
        output += interval;
    }
    cout << "TSP finish" << endl;

    writeData(outputFileName, output);
}

void processFW(string& data, Graph& g, const string& source, const string& destination) {
    string info = "shortest path (Floyd Warshall) from \"" + source + "\" to \"" + destination + "\":\n";
    try {
        vector<string> path = g.getShortestPath(source, destination);
        for (const auto& v : path) {
            info += v + " -> ";
        }
        info += "[end]\n";
        data += info;
    }
    catch (std::exception& e) {
        data += "fail to process shortest path (Floyd Warshall)\n";
    }
}

void processDij(string& data, Graph& g, const string& source, const string& destination) {
    string info = "shortest path (Dijkstra) from \"" + source + "\" to \"" + destination + "\":\n";
    try {
        vector<string> path = g.getDjikstrasShortestPath(source, destination);
        for (const auto& v : path) {
            info += v + " -> ";
        }
        info += "[end]\n";
        data += info;
    }
    catch (std::exception& e) {
        data += "fail to process shortest path (Dijkstra)\n";
    }
}

void processCent(string& data, Graph& g, const string& num_of_top, const string& calc_shortest) {
    string info;
    try {
        int num_top = std::stoi(num_of_top);
        
        Centrality centrality(&g);

        centrality.calculate_centrality();

        vector<pair<string, int>> sorted_freq;
        for (const auto& curr : centrality.frequency_) {
            sorted_freq.push_back(make_pair(curr.first, curr.second));
        }
        sort(sorted_freq.begin(), sorted_freq.end(), 
            [](const auto& a, const auto& b) {
                return a.second > b.second;
            });

        vector<string> centrality_top;
        for (int i = 0; i < num_top; ++i) {
            centrality_top.push_back(sorted_freq[i].first);
            info += std::to_string(i) + " : " + sorted_freq[i].first + " , it's centrality : " + std::to_string(sorted_freq[i].second) + "\n";
        }

        TSP tsp(&g, centrality_top);
        vector<string> path = tsp.getShortestPath();

        info += "\nshortest path to connect them (inorder): \n";
        for (const auto& v : path) {
            info += v + " -> ";
        }
        info += "[end]\n";

        data += info;
    }
    catch (std::exception& e) {
        data += "fail to process Centrality\n";
    }
}

void processTSP(string& data, Graph& g, const string& vertexes) {
    string info;
    try {
        vector<string> vertex = stringToVector(vertexes);

        TSP tsp(&g, vertex);
        vector<string> path = tsp.getShortestPath();

        info += "Travelling Salesman Problem\nshortest path to connect these vertexes (inorder): \n";
        for (const auto& v : path) {
            info += v + " -> ";
        }
        info += "[end]\n";

        data += info;
    }
    catch (std::exception& e) {
        data += "fail to process Travelling salesman problem\n";
    }
}
