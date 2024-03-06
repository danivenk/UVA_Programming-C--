// Dani van Enk, 11823526

// used libaries and headers
#include "array.h"
#include <iostream>

// define used functions
template <class T>
void test_array(T val1, T val2, T val3);

int main() {

    // test arrays of doubles, ints and const char*s
    test_array<double>(0.1, 0.2, 0.4);
    test_array<int>(1, 2, 4);
    test_array<const char*>("Tokyo", "Osaka", "Kyoto");

    return 0;
}

// test a T array of size 3
template <class T>
void test_array(T val1, T val2, T val3) {

    // print commercing statement
    std::cout << "Commercing array test" << std::endl; 

    // initialize an array of size 3
    Array<T> test(3);

    // give 3 values to the array of size 3
    test[0] = val1;
    test[1] = val3;
    test[2] = val2;

    // make a copy of the array
    Array<T> tset = test;

    // change the values including an out of bound index
    test[1] = val2;
    test[2] = val3;
    test[3] = val1;

    // print the contents of the test array
    std::cout << "test" << std::endl;
    for (int i = 0; i < test.size(); i++)
    {
        std::cout << test[i] << std::endl;
    }

    // print the contents of the copied array
    std::cout << "tset" << std::endl;
    for (int i = 0; i < test.size(); i++)
    {
        std::cout << tset[i] << std::endl;
    }
}