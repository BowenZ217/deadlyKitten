#include <iostream>
#include <string>
#include "Process.h"

using namespace std;

int main()
{
    string inputFileName = "../input.txt";
    string outputFileName = "../output.txt";

    process(inputFileName, outputFileName);
    return 0;
}
