#include <iostream>
#include <string>
#include "temp.h"
#include "cs225/PNG.h"

using namespace std;

int main()
{
    // Write your own main here
    cout << "----------  From main.cpp  ----------" << endl;
    Foo<std::string> test;
    test.foo("main");
    cout << "-------------------------------------" << endl;

    return 0;
}