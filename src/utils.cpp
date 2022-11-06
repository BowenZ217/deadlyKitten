#include "utils.h"

using std::stringstream;
using std::cout;
using std::endl;

vector<vector<string>> datToVector(const string& fileName, unsigned size) {
    // init
    vector<vector<string>> data;
    ifstream dataFile(fileName);
    string currLine;

    // check if meet problem with opening the file
    if (!dataFile.is_open()) {
        std::cout << "Fail to open \"" << fileName << "\". Please check the file path and name." << std::endl;
        assert(dataFile.is_open());
        return data;
    }

    // function to check if a char is new line character
    auto is_new_line = [](auto ch) { return (ch == '\n' || ch == '\r'); };
    
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
    }

    // check if it contains at least 1 information
    if (data.size() == 0) {
        cout << "Reads 0 line from \"" << fileName << "\". Please try with another file." << endl;
        assert(data.size() != 0);
    }
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