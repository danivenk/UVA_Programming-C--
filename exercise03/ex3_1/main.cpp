// Dani van Enk, 11823526

/*
 * Stack needs to be included because we use it
 */
#include <iostream>
#include "stack.h"

int main() {

    // initialize a stack
    Stack s;

    // Write doubles into Stack
    /*
     * The stack is filled untill it has 80 items and then is not filled because it is full.
     */
    for (int i=0 ; i<100 ; i++) {
        std::cout << "pushing value " << i*i << " in stack" << std::endl;
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