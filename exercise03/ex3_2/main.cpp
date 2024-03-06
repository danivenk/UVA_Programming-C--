// Dani van Enk, 11823526

// including used libraries
#include <iostream>
#include "stack.h"

int main() {

    // initialize a stack
    Stack s;

    // Write doubles into Stack and grow if full
    for (int i=0 ; i<100 ; i++) {
        std::cout << "pushing value " << i*i << " in stack" << std::endl;
        if (s.full()) {
            s.grow(1);
        }
        s.push(i*i);
    }

    // Count doubles in stack
    std::cout << s.nitems() << " value in stack" << std::endl;

    // inspect the stack
    s.inspect();

    // Read doubles back from stack
    while (!s.empty()) {
        double val = s.pop() ;
        std::cout << "popping value " << val << " from stack" << std::endl;
    }

    // inspect the stack
    s.inspect();

    return 0;
}