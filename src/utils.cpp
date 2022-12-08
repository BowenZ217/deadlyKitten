#include "utils.h"

vector<vector<string>> fileToVector(const string& fileName) {
    // init
    vector<vector<string>> data;
    ifstream dataFile(fileName);
    string currLine;

    // check if meet problem with opening the file
    if (!dataFile.is_open()) {
        std::cout << "Fail to open \"" << fileName << "\". Please check the file path and name." << std::endl;
        throw std::invalid_argument("Wrong file name");
        return data;
    }

    // function to check if a char is not needed
    auto is_new_line = [](auto ch) { return (ch == '\n' || ch == '\r' || ch == '\"'); };
    
    // start to fill in data
    while (getline(dataFile, currLine)) {
        vector<string> temp;

        // start to split current line by comma
        stringstream s_stream(currLine);

        while(s_stream.good()) {
            string substr;
            // get first string delimited by comma
            getline(s_stream, substr, ',');

            // Remove newline character from string
            substr.erase(std::remove_if(substr.begin(), substr.end(), is_new_line), substr.end());

            temp.push_back(trim(substr));
        }

        data.push_back(temp);
    }

    // check if it contains at least 1 information
    if (data.size() == 0) {
        cout << "Reads 0 line from \"" << fileName << "\". Please try with another file." << endl;
        throw std::invalid_argument("Wrong file name");
    }
    return data;
}

vector<vector<string>> fileToVector(const string& fileName, unsigned size) {
    // init
    vector<vector<string>> data;
    ifstream dataFile(fileName);
    string currLine;

    // check if meet problem with opening the file
    if (!dataFile.is_open()) {
        std::cout << "Fail to open \"" << fileName << "\". Please check the file path and name." << std::endl;
        throw std::invalid_argument("Wrong file name");
        return data;
    }

    // function to check if a char is not needed
    auto is_new_line = [](auto ch) { return (ch == '\n' || ch == '\r' || ch == '\"'); };
    
    // start to fill in data
    while (getline(dataFile, currLine)) {
        vector<string> temp;

        // start to split current line by comma
        stringstream s_stream(currLine);

        while(s_stream.good()) {
            string substr;
            // get first string delimited by comma
            getline(s_stream, substr, ',');

            // Remove newline character from string
            substr.erase(std::remove_if(substr.begin(), substr.end(), is_new_line), substr.end());

            temp.push_back(trim(substr));
        }

        if (temp.size() == size) data.push_back(temp);
        else {
            // cout << "fail with id : " << temp[0] << " , name = " << temp[1] << endl;
            // cout << "maybe because there is ',' in name" << endl << endl;
        }
    }

    // check if it contains at least 1 information
    if (data.size() == 0) {
        cout << "Reads 0 line from \"" << fileName << "\". Please try with another file." << endl;
        throw std::invalid_argument("Wrong file name");
    }
    return data;
}

vector<vector<int>> fileToIntVector(const string& fileName, unsigned size) {
    // init
    vector<vector<int>> data;
    ifstream dataFile(fileName);
    string currLine;

    // check if meet problem with opening the file
    if (!dataFile.is_open())
        return data;

    // function to check if a char is not needed
    auto is_new_line = [](auto ch) { return (ch == '\n' || ch == '\r' || ch == '\"'); };
    
    // start to fill in data
    while (getline(dataFile, currLine)) {
        vector<int> temp;

        // start to split current line by comma
        stringstream s_stream(currLine);

        while(s_stream.good()) {
            string substr;
            // get first string delimited by comma
            getline(s_stream, substr, ',');

            // Remove newline character from string
            substr.erase(std::remove_if(substr.begin(), substr.end(), is_new_line), substr.end());
            substr = trim(substr);

            // if blank, it is -1
            if (substr.empty()) temp.push_back(-1);
            else temp.push_back(std::stoi(substr));
        }

        if (temp.size() == size) data.push_back(temp);

        // if one line is not match as size we need, means wrong file
        else return {};
    }

    // if not match the size we need
    if (data.size() != size) return {};

    return data;
}

void vectorToFile(const string& fileName, const vector<vector<int>>& data) {
    // init
    ofstream dataFile(fileName);
    string line;

    // write per line by `vector<int>`
    for (const auto& curr_line : data) {
        line.clear();
        for (const auto& curr : curr_line) {
            // since most value is -1, mark as blank, which could save space
            if (curr != -1) line += std::to_string(curr);
            line.push_back(',');
        }
        // remove that extra ","
        line.pop_back();
        dataFile << line << endl;
    }
}

vector<string> readInput() {
    // init
    vector<string> data;
    string curr_line;
    int idx = 1;

    // read
    do {
        cout << "airport " << idx++ << " (input `e` to stop): ";
        getline(cin, curr_line);
        curr_line = trim(curr_line);
        data.push_back(curr_line);
    } while (curr_line != "e");
    // remove that extra "e"
    data.pop_back();

    return data;
}

string trim(const string& s) {
    auto start = s.begin();
    auto end = s.end();

    // skip all space from start and end
    while (start != s.end() && std::isspace(*start)) {
        start++;
    }
    do {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));
 
    return string(start, end + 1);
}

long double calcDistance(long double latitude_1, long double longitude_1, long double latitude_2, long double longitude_2) {
    // Euclidean distance
    long double ans = pow(latitude_2 - latitude_1, 2) + pow(longitude_2 - longitude_1, 2);
    ans = sqrt(ans);

    return ans;
}

long double degreeToRadians(const long double& degree) {
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}

long double calcDistance_2(long double latitude_1, long double longitude_1, long double latitude_2, long double longitude_2) {
    // transform input from degree to radians
    latitude_1 = degreeToRadians(latitude_1);
    longitude_1 = degreeToRadians(longitude_1);
    latitude_2 = degreeToRadians(latitude_2);
    longitude_2 = degreeToRadians(longitude_2);
     
    // Haversine Formula
    long double lon_diff = longitude_2 - longitude_1;
    long double lat_diff = latitude_2 - latitude_1;

    long double ans = pow(sin(lat_diff / 2), 2) + cos(latitude_1) * cos(latitude_2) * pow(sin(lon_diff / 2), 2);
    ans = 2 * asin(sqrt(ans));

    // Radius of Earth in Kilometers
    long double R = 6371;

    // Calculate the result
    ans = ans * R;

    return ans;
}
