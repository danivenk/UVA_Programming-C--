// Dani van Enk, 11823526
#include <iostream>
#include <string.h>

// define declarations
void order(const char*& a, const char*& b);
void sort(int n, const char* charray[]);
void print_charray(int n, const char* charray[]);

int main() {

    // define a const char array and find it's size
    /*
     * It needs to be a const char* because the pointer to the value must stay the same.
     */
    const char* charray[10] = {"Tokyo", "Kanda", "Akihabara", "Okachimachi",
                               "Ueno", "Uguisudani", "Nippori",
                               "Nishi-Nippori", "Tabata", "Komagome"};
    int n = sizeof(charray)/sizeof(const char*);

    // print before the sort
    std::cout << "Before ";
    print_charray(n, charray);

    // sort
    sort(n, charray);

    // print after the sort
    std::cout << "After ";
    print_charray(n, charray);

    return 0;
}

// order the strings by their lexical order
/*
 * Yes you need the references, to change the order in the charray
 */
void order(const char*& a, const char*& b) {

    // compare the strings and if needed swap
    /* you need to compare the letters of the strings for the whole string
     *  to see if it's lexical order. The pointer only points to the
     *  first character in the string.
     */
    if (strcmp(a, b) < 0) {
        const char* tmp = a;
        a = b;
        b = tmp;
    }
}

// sort the strings in the charray by lexical order
void sort(int n, const char* charray[]) {

    // loop over the charray and order the neighbouring elements
    for (char i = 0; i < n - 1; i++) {
        for (char j = 0; j < n - i - 1; j++)
        {
            order(charray[j + 1], charray[j]);
        }
    }
}

// print the strings in the charray
void print_charray(int n, const char* charray[]) {

    // loop over the array and print the elements
    for (char i = 0; i < n; i++) {
        std::cout << charray[i];
        std::cout << " ";
    }

    // don't forget the linend
    std::cout << std::endl;
}