// Dani van Enk, 11823526

// include used libraries
#include <iostream>
#include <fstream>
#include <sstream>

// declare used functions
void print_help(char* argv[]);

// define main with command line arguments
int main(int argc, char* argv[]) {

    // check if at least 2 arguments are given if not return 1 and print help
    if (argc < 2) {
        print_help(argv);

        return 1;
    }

    // define valid/invalid bools
    bool char_c_valid = false;
    bool word_c_valid = false;
    bool invalid_args = false;

    // check if argc is between (2, 5) else return 1 and print help
    if (argc > 2 and argc < 5) {

        // loop over the arguments excluding the program name and filename
        for (int i=2; i < argc; i++) {
            
            // get the flag char (ptr+1 because used a dash before the flags)
            char flag = *(argv[i] + 1);

            // if c flag present set char_couter to valid
            if (flag == 'c') {
                char_c_valid = true;
            }

            // if w flag present set word_couter to valid
            if (flag == 'w') {
                word_c_valid = true;
            }

            // if an invalid flag is given return 1 and print help
            if (flag != 'c' && flag != 'w') {
                print_help(argv);

                return 1;
            }
        }
    } else {
        print_help(argv);

        return 1;
    }

    // open the file as given
    std::ifstream ifs(argv[1]);

    // check if file is opened correctly, if not return 2 and print help
    if (!ifs) {
        print_help(argv);

        return 2;
    }

    // initialize counters and buffers
    int line_c = 0;
    int word_c = 0;
    int char_c = 0;
    char bufl[1000];
    char bufw[1000];
    char bufc;

    // if char count is valid get char count from file
    if (char_c_valid) {

        // loop over file char by char
        while(ifs.get(bufc)) {
            char_c++;
        }

        // clear the file end and rewind back to start
        ifs.clear();
        ifs.seekg(0);
    }

    // read file line by line
    while (ifs.getline(bufl, 1000)) {
        
        // if word count is valid get word count in this line
        if (word_c_valid) {

            // define line buffer stream
            std::istringstream line(bufl);

            // loop over line word by word
            while (line >> bufw) {
                word_c++;
            }
        }

        line_c++;
    }

    // if char count is valid print char count
    if (char_c_valid) {
        std::cout << "Character count ";
        std::cout << char_c << std::endl;
    }

    // if word count is valid print word count
    if (word_c_valid) {
        std::cout << "Word count ";
        std::cout << word_c << std::endl;
    }

    // print line count
    std::cout << "Line count ";
    std::cout << line_c << std::endl;

    return 0;
}

// print help/usage
void print_help(char* argv[]) {

    // command usage
    std::cout << "Usage " << argv[0] << " <filename> [flags]" << std::endl;

    // flags
    std::cout << "Flags:" << std::endl;
    std::cout << "  -c\tenable character count;" << std::endl;
    std::cout << "  -w\tenable word count;" << std::endl;
}