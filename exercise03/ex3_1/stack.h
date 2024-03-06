// Dani van Enk, 11823526

// check if already included
#ifndef STACK_H
#define STACK_H

// default stack length
const int LEN = 80;

// define a stack with its methods
class Stack {

    // state the public and private methods/parameters
    public:

        // handle construction and destruction
        Stack() { init(); }
        ~Stack() {}

        // define stack properties, as if it's full or empty and no of items
        int nitems() { return count; }
        bool full() { return (count == LEN); }
        bool empty() const { return (count == 0); }

        // define pushing into the stack, popping out and inspecting stack
        void push(double c);
        double pop();
        void inspect() const;

    private:

        // define the stack and count
        double s[LEN];
        int count;

        // define the initialization of the stack
        void init() { count = 0; }
};

#endif
