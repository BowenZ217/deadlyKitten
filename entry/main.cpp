#include <iostream>
#include <string>
#include "cs225/PNG.h"
#include "utils.h"

using namespace std;

int main()
{
    string file_name = "../tests/test_dat_to_vector.dat";
    auto result = datToVector(file_name, 5);
    for (const auto& curr_vec : result) {
        for (const auto& curr_str : curr_vec) {
            cout << curr_str << " ";
        }
        cout << endl;
    }
    
    cout << endl << "finish." << endl;
    return 0;
}