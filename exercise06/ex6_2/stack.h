// Dani van Enk, 11823526

// include used header
#include "array.h"

// make sure only once included
#ifndef STACK_H
#define STACK_H

// define a template class for a stack
template <class T>
class Stack {
public:

	// create a stack of given length
	Stack(int length) : s(Array<T>(length)) {
		count = 0;
	};

	// copy stack to this
	Stack(const Stack &other) : s(Array<T>(other.s)){

		// copy over count
		count = other.count;

		// copy over the values
		for (int i = 0; i < s.size(); i++)
		{
			s[i] = other.s[i];
		}
	};

	// destoyer!
	~Stack() {};

private:

	// define array and count position
	Array<T> s;
	int count;

public:

	// define length, full and empty methods
	int nitems() { return count; }
	bool full() { return (count == s.size() - 1); }
	bool empty() { return (count == 0); }

	// push a value into the stack if too small? Expand the stack!
	void push(T c) {

		// if small? increase the size!
		if (full())
		{
			std::cout << "Stack::push() growing stack by 10 elements" << std::endl;
			s.resize(count + 10);
		}

		// put value in it's place
		s[count++] = c;
	};

	// pop the top element off the stack
	T pop() {

		// if the stack is empty give an error
		if (empty())
		{
			std::cout << "Stack::pop() Error: stack is empty" << std::endl;
			return 0;
		}

		// pop the element out of the stack
		return s[--count];
	};

	// see the contents of the stack
	void inspect() {

		// loop over the contents and print them
		for (int i = count - 1; i >= 0; i--)
		{
			std::cout << "[" << i << "] = '" << s[i] << "'" << std::endl;
		}
	};
};

#endif
