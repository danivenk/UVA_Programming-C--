// Dani van Enk, 11823526

#include <iostream>
#include "stack.h"

int main() {

	// init double stack of size 80
	Stack<double> s(80);

	// write values into Stack
	for (int i = 0; i < 10; i++) {
		std::cout << "pushing value " << i*i << " in stack" << std::endl;
		s.push(i*i);
	}
	std::cout << "original stack after filling" << std::endl;
	s.inspect();

	// clone stack using copy constructor
	Stack<double> sclone(s);

	// check contents of sclone after cloning
	std::cout << "cloned stack after cloning" << std::endl;
	sclone.inspect();

	// empty original stack
	while(!s.empty()) {
		s.pop();
	}

	// check contents of both stacks after emptying s
	std::cout << "original stack after emptying it" << std::endl;
	s.inspect();
	std::cout << "cloned stack after emptying the original stack" << std::endl;
	sclone.inspect();

	// refill original stack with different values
	for (int i = 0; i < 5; i++) {
		std::cout << "pushing value " << 2*i << " in stack" << std::endl;
		s.push(2*i);
	}

	// check the contents of both again after refilling
	std::cout << "original stack after refilling it" << std::endl;
	s.inspect();
	std::cout << "cloned stack after refilling the original stack" << std::endl;
	sclone.inspect();

	// create a new const char* stack
	Stack<const char*> c(80);

	// define 2 arrays with station names to fill the stacks with
	const char* tokaido[21] = {"tokyo", "shimbashi", "shinagawa", "kawasaki",
							   "yokohama", "totsuka", "ofuna", "fujisawa",
							   "tsujido", "chigasaki", "hiratsuka", "oiso",
							   "ninomiya", "kozu", "kamonomiya", "odawara",
							   "hayakawa", "nebukawa", "manazuru", "yugwara",
							   "atami"};
	const char* tohoku[23] = {"tokyo", "ueno", "oku", "akabane", "urawa",
							  "saitama shintoshin" "omiya", "toro", "higashi-omiya",
							  "hasuda", "shiraoka", "shinshiraoka", "kuki",
							  "higashi-washinomiya", "kurihashi", "koga", "nogi",
							  "mamada", "oyama", "koganei", "jichiidai",
							  "ishibashi", "suzumenomiya", "utsunomiya"};

	// write names into Stack
	for (int i = 0; i < 21; i++) {
		std::cout << "pushing value " << tokaido[i] << " in stack" << std::endl;
		c.push(tokaido[i]);
	}
	std::cout << "original stack after filling" << std::endl;
	c.inspect();

	// clone stack using copy constructor
	Stack<const char*> cclone(c);

	// check contents of sclone after cloning
	std::cout << "cloned stack after cloning" << std::endl;
	cclone.inspect();

	// empty original stack
	while (!c.empty()) {
		c.pop();
	}

	// check contents of both stacks after emptying s
	std::cout << "original stack after emptying it" << std::endl;
	c.inspect();
	std::cout << "cloned stack after emptying the original stack" << std::endl;
	cclone.inspect();

	// refill original stack with different values
	for (int i = 0; i < 23; i++) {
		std::cout << "pushing value " << tohoku[i] << " in stack" << std::endl;
		c.push(tohoku[i]);
	}

	// check the contents of both again after refilling
	std::cout << "original stack after refilling it" << std::endl;
	c.inspect();
	std::cout << "cloned stack after refilling the original stack" << std::endl;
	cclone.inspect();

	return 0;
}
