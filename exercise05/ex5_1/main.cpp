// Dani van Enk, 11823526

// include used libraries
#include <iostream>
#include <fstream>

int main() {

    // open the datafile and define a number
    std::ifstream ifs("data1.txt");
    int number = 1;

    // check if the file is opened correctly else return 1
    if (!ifs) {
        return 1;
    }

    // print out what the program does
    std::cout << "Stop reading when a 0 is read." << std::endl;

    // get a number and check if it is 0, if not print it out
    while (ifs >> number && number != 0) {
        std::cout << number << " has been read!" << std::endl;
    }

    return 0;
}