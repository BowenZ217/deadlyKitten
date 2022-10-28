#include <iostream>
#include <string>
#include "temp.h"

using namespace std;

int main()
{
    // Write your own main here
    cout << "----------  From other.cpp  ----------" << endl;
    Foo<std::string> test;
    test.foo("other");
    cout << "--------------------------------------" << endl;

    return 0;
}