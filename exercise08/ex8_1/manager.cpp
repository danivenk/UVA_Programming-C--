// Dani van Enk, 11823526

// include used header and library
#include "manager.h"
#include <iostream>

// print business card of manager to ostream
void Manager::businessCard(std::ostream &os) const {

    // print employee part
    Employee::businessCard(os);

    // add subordinates to the business card
    std::cout << "   Subordinates: ";

    // loop over all subordinates
    for (Employee *empl : subordinates) {

        // print name of subordinate
        std::cout << empl->name();

        // concatinate using commas
        if (empl != *(--subordinates.end())) {
            std::cout << ", ";
        }
    }

    // don't forget the linend
    std::cout << std::endl;

}