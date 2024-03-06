// Dani van Enk, 11823526

// include used header
#include "employee.h"

// print out the business card to the defined ostream
void Employee::businessCard(std::ostream &os) const {
    os << "   +------------------+  " << std::endl
       << "   | ACME Corporation |  " << std::endl
       << "   +------------------+  " << std::endl
       << "   " << name() << std::endl;
}