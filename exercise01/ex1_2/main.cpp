// Dani van Enk, 11823526

#include <iostream>

int main() {

    // declare the character buffer
    char buffer[256];

    // get the userinput and put it in the buffer
    std::cin.getline(buffer, 256);

    // get the adress of the first character
    char* pbuffer = &buffer[0];

    // initialize the lower- & upper case, digit and other counters
    int lchar_c = 0, uchar_c = 0, dchar_c = 0, nchar_c = 0;

    // loop over the characters
    while (*pbuffer != 0) {

        // check the character and increase the correct counter
        if ('a' <= *pbuffer && *pbuffer <= 'z') {
            lchar_c++;
        } else if ('A' <= *pbuffer && *pbuffer <= 'Z') {
            uchar_c++;
        } else if ('0' <= *pbuffer && *pbuffer <= '9') {
            dchar_c++;
        } else {
            nchar_c++;
        }

        // get the next character
        pbuffer++;
    }

    // print out the result
    std::cout << "Your input contains" << std::endl;
    std::cout << "LowerCase: " << lchar_c << std::endl;
    std::cout << "UpperCase: " << uchar_c << std::endl;
    std::cout << "Digit: " << dchar_c << std::endl;
    std::cout << "Other: " << nchar_c << std::endl;

    return 0;
}