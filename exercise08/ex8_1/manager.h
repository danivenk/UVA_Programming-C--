// Dani van Enk, 11823526

// make sure the header is only included once
#ifndef MANAGER_H
#define MANAGER_H

// include used library and header
#include "employee.h"
#include <set>

// define a manager who inherites from an employee
class Manager: public Employee {
    public:

        // constructor
        Manager(const char *name, double salary) : Employee(name, salary) {};

    private:

        // define a subordinates set
        /*
         * A set has been used to ensure that subordinates only has 1 instance of a
         *  certain employee, using lists or vectors this will be more difficult
         */
        std::set<Employee *> subordinates;

    public:

        // get and add to subordiantes
        /*
         * there is no problem because a if you add a manager it can be seen as an
         *  employee as it is derived from it.
         */
        void addSubordinate(Employee &empl) { subordinates.insert(&empl); };
        const std::set<Employee *> &listOfSubordinates() const { return subordinates; };

        // print business card
        void businessCard(std::ostream &os = std::cout) const;

        // return type string
        std::string type() { return "Manager"; };
};

#endif