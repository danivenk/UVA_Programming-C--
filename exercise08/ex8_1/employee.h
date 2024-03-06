// Dani van Enk, 11823526

// make sure the header is included once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

// include used libraries
#include <string>
#include <iostream>

// define an Employee class which has a name and salary
class Employee {

	public:

		// constructor
		Employee(const char* name, double salary) : _name(name), _salary(salary) {};

	private:

		// define name and salary of the Employee
		std::string _name;
		double _salary;

	public:

		// accessors
		const char* name() const { return _name.c_str(); };
		double salary() const { return _salary; };

		// print functions
		/*
		 * the business card will be different because of the virtual part and of
		 * 	course if the business card function is defined in the derived class
		 */
		virtual void businessCard(std::ostream &os = std::cout) const;

		// return type string
		virtual std::string type() { return "Employee"; };
};

#endif
