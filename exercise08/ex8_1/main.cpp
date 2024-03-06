// Dani van Enk, 11823526

// include used library and headers
#include <iostream>
#include "employee.h"
#include "manager.h"

int main() {
    
    // define employee salary
    double salary = 1200;

    // define list of employee names
    const char* names[8] = {"Bart", "Gary", "Monica", "Jules", "Harmen", "Judith",
                            "Linda", "Erbert"};

    // create an employee pointer set
    std::set<Employee*> empls;

    // loop over the names and create an employee with basic salary
    for (const char* name: names) {
        Employee* empl = new Employee(name, salary);

        // add employee to set of employees
        empls.insert(empl);
    }

    // create a manager with 1.1 times basic salary
    Manager man("Hugh", salary * 1.1);
    Manager man1("Peter", salary * 1.2);

    // add the previous employees to the subordinate set of the manager
    for (Employee* empl : empls) {
        man.addSubordinate(*empl);
    }

    // add manager to set of employees
    empls.insert(&man);
    empls.insert(&man1);

    // create manager with 2 times basic salary
    Manager supp("Richard", salary * 2);

    // add previous manager to subordinate set of new manager
    supp.addSubordinate(man);
    supp.addSubordinate(man1);

    // add new manager to set of employees
    empls.insert(&supp);

    // loop over all employees and print their business card with salary
    for (Employee *empl : empls) {

        empl->businessCard();
        std::cout << "   $" << empl->salary() << std::endl;
    }

    // delete the dynamically allocated employees
    for (Employee *empl : empls) {
        if (empl->type() == "Employee") {
            delete empl;
        }
    }

    return 0;
}