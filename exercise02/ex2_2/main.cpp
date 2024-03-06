//Dani van Enk, 11823526
#include <iostream>

// decalare functions
int min(int a, int b);
double min(double a, double b);
double min(int a, double b);
double min(double a, int b);
int min(int arr[], int len);

int main() {
    // create array
    int arr[7] = {9, 2, 3, 100, 1, 39, 4};

    // find the minimum for int vs int, double vs double and in an array
    std::cout << min(13, 21) << std::endl;
    std::cout << min(4.2, .69) << std::endl;
    std::cout << min(arr, sizeof(arr)/sizeof(int)) << std::endl;

    /* 
     * normally and error of ambiguous parameters but fixed by adding
     *  a (int,double) and (double, int) overloading
     */
    std::cout << min(420, .69) << std::endl;
    std::cout << min(4.20, 69) << std::endl;

    return 0;
}

// return minimum of an int vs int
int min(int a, int b) {
    return a < b ? a : b;
}

// return minimum of an double vs double
double min(double a, double b) {
    return a < b ? a : b;
}

// return minimum of an int vs double
double min(int a, double b) {
    return a < b ? a : b;
}

// return minimum of an double vs int
double min(double a, int b) {
    return a < b ? a : b;
}

// return minimum in an int array
int min(int arr[], int len) {

    // set tmp var as large int
    int tmp = 1000000;

    // loop over the array to find the minimum
    for (int i = 0; i < len; i++) {
        if (arr[i] < tmp) {
            tmp = arr[i];
        }
    }

    return tmp;
}