// Dani van Enk, 11823526

// include used libraries
#include <iostream>
#include <fstream>
#include <string>
#include <map>

// run main with commandline arguments
int main(int argc, const char* argv[]) {

    // make sure a filename has been given
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <filename>"
            << std::endl;

        return 1;
    }

    // printing opening statement
    std::cout << "Opening " << argv[1] << std::endl;

    // open the file and define a word string and <string, int> map
    std::ifstream ifs(argv[1]);
    std::string word;
    std::map<std::string, int> myMap;

    // make sure the file is opened correctly
    if (!ifs) {
        std::cout << "Something went wrong, file " << argv[1]
            << " doesn't exist or is corrupted";

        return 2;
    }

    // read word for word
    while(ifs >> word) {

        // get the beginning of the word
        std::string::iterator it = word.begin();

        // loop over the characters in the word
        while (it != word.end()) {

            // remove any interpunction
            if (ispunct(*it)) {
                word.erase(it);
            } else {
                it++;
            }
        }

        // add word to count map
        if (!word.empty()) {
            std::cout << word << std::endl;
            myMap[word] += 1;
        }
    }

    // print readword - result separation
    std::cout << "--------------------" << std::endl;

    // print result header
    std::cout << "Word - Count" << std::endl;

    // get beginning of the map
    std::map<std::string, int>::iterator it = myMap.begin();

    // print out the results from the map
    while (it != myMap.end()) {
        std::cout << it->first << " " << it->second << std::endl;

        it++;
    }

    return 0;
}