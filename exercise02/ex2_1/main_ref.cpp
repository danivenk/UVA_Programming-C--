// Dani van Enk, 11823526
/*
 * Between pointers and references I have no preference,
 *  references can be handy but so can pointers be...
 */

#include <iostream>

// define declaration
void order(int& a, int& b);
void sort(const int n, int array[]);
void print_array(const int n, const int array[]);

int main()
{

    // define int array and it's size
    int array[10] = {35, 70, 66, 12, 80, 42, 40, 62, 68, 57};
    int n = sizeof(array) / sizeof(int);

    // print before the sort
    std::cout << "Before ";
    print_array(n, array);

    // sort
    sort(n, array);

    // print after the sort
    std::cout << "After ";
    print_array(n, array);

    return 0;
}

// order a and b, so that a becomes the biggest and b the smallest
void order(int& a, int& b) {

    // check if a is bigger than b and swap
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
}

// sort an int array highest lowest 
void sort(const int n, int array[]) {

    // loop over the the neighbouring elements and swap if needed
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++)
        {
            order(array[j + 1], array[j]);
        }
    }
}

// print out elements of the array
void print_array(const int n, const int array[]) {

    // loop over the elements and print
    for (int i = 0; i < n; i++) {
        std::cout << array[i];
        if (i != n - 1) {
            std::cout << " ";
        }
    }

    // don't forget the linend
    std::cout << std::endl;
}