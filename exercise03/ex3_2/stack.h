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
        /*
         * It's for a user to be able to set the size of the stack as this
         *  ables them to create a bigger stack when they already know they
         *  need it. Making sure less allocations need to be done.
         */
        Stack(int len = LEN) { init(len); }
        ~Stack() { delete[] s; }

        // define stack properties, as if it's full or empty and no of items
        int nitems() { return count; }
        bool full() { return (count == max_len); }
        bool empty() const { return (count == 0); }

        // define pushing into the stack, popping out, inspecting and growing stack
        void push(double c);
        double pop();
        void inspect() const;
        void grow(int delta);

    private:

        // define the stack and count
        double* s;
        int count;
        int max_len;

        // define the initialization of the stack
        void init(int len);
};

#endif
