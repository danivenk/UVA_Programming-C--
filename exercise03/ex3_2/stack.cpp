// Dani van Enk, 11823526

// including used libraries
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

// initializes a stack of length len
void Stack::init(int len) {
	count = 0;
	s = new double[len];
	max_len = len;
}

// grows the Stack max length by delta
void Stack::grow(int delta) {

	// intializing new larger buffer
	double *s_new = new double[max_len + delta];

	// copy the data over
	for (int i = 0; i < max_len; i++) {
		*(s_new + i) = *(s + i);
	}

	// increase the max length
	max_len += delta;

	// delete the old data associated
	delete[] s;

	// point to the new data
	s = s_new;
}