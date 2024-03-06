// Dani van Enk, 11823526

#include <iostream>
#include <string.h>

// declare the used functions
char* join(const char* a, const char* b, bool space_sep=false);
char* joinb(const char* a, const char* b);
void print_char_array(const char* a);

int main() {

    // get pointer to the result (User needs to delete this)
    char* a = join("Alpha", "bet");
    char* b = joinb("duck", "soup");

    // print out the result of the join functions
    print_char_array(a);
    print_char_array(b);

    // delete the associated data
    delete[] a;
    delete[] b;

    return 0;
}

// joins 2 char arrays with or without a space depending on the space_sep bool
char* join(const char* a, const char* b, bool space_sep) {

    // declare the total length
    int totlength;

    // find the length of the new char array
    if (!space_sep) {
        totlength = strlen(a) + strlen(b) + 1;
    } else {
        totlength = strlen(a) + strlen(b) + 2;
    }
    
    // create char array with found length (User needs to delete this)
    char* ab = new char[totlength];

    // init array to 0
    for (int i = 0; i < totlength; i++) {
        *(ab + i) = 0;
    }

    // add char array a
    strcat(ab, a);

    // if space_sep is true add a space
    if (space_sep) {
        strcat(ab, " ");
    }

    // add char array b
    strcat(ab, b);

    return ab;
}

// create char array from a and b separated by a space
char* joinb(const char* a, const char* b) {

    // return join with space_sep=true
    return join(a, b, true);
}

// print a char array from a char array pointer
void print_char_array(const char* a) {
    
    // loop over the char array and print the letters
    for (int i = 0; i < strlen(a); i++) {
        std::cout << *(a + i);
    }

    // don't forget the line endings 
    std::cout << std::endl;
}
