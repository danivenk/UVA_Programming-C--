// Dani van Enk, 11823526

// used header
#include "array.h"

int main() {

    // declare an array of size 3
    int size = 3;
    Array a(size);

    // add some values to the array
    for (int i = 0; i < a.size(); i++) {
        a[i] = i;
    }

    // read out of bounds values
    for (int i = 0; i < a.size() + 1; i++) {

        /* 
         * when an out of bound is accessed it throws and ArrayOOB error and
         *  prints out what is wrong to the user
         */
        try {
            std::cout << "Read " << a[i] << " from the a array" << std::endl;
        } catch (Array::ArrayOutOfBounds error) {
            std::cout << error << ". The max index was " << a.size() - 1;
            std::cout << " but tried to access index " << error.index() << std::endl;
        }
    }

    return 0;
}