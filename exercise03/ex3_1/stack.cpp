// Dani van Enk, 11823526

/*
 * Stack needs to be included because we use it
 */
#include <iostream>
#include "stack.h"

// adds item to the stack
void Stack::push(double c) {

	// check if full and give error
	if (full()) {
		std::cout << "Stack::push() Error: stack is full" << std::endl;
		return;
	}

	// push item to stack
	s[count++] = c;
}

// remove item from stack and return it
double Stack::pop() {

	// check if empty and give error
	if (empty()) {
		std::cout << "Stack::pop() Error: stack is empty" << std::endl;
		return 0;
	}

	// remove and return from stack
	return s[--count];
}

// return contents of stack
void Stack::inspect() const{
	// check empty and tell if empty
	if (empty()) {
		std::cout << "No items in the stack, please add push items to inspect" << std::endl;
	}

	// print out contents
	for (int i = count - 1; i >= 0; i--) {
		std::cout << "position " << count - i << " with a value of " << s[i] << std::endl;
	}
}