#include <iostream>
#include <exception>
#include "EmployeeManager.hpp"
#include "ContractEmployee.hpp"
#include "TempWorker.hpp"
#include "Apprentice.hpp"

int main() {
    try {
        EmployeeManager *manager = new EmployeeManager();

        ContractEmployee *paul = new ContractEmployee("Paul", 28.90);
        ContractEmployee *maria = new ContractEmployee("Maria", 30.00);
        
        TempWorker *bob = new TempWorker("Bob", 26.00);
        TempWorker *anna = new TempWorker("Anna", 24.00);
        
        Apprentice *jack = new Apprentice("Jack", 17.00);
        Apprentice *jane = new Apprentice("Jane", 17.00);

        manager->add_employee(paul);
        manager->add_employee(maria);
        manager->add_employee(bob);
        manager->add_employee(anna);
        manager->add_employee(jack);
        manager->add_employee(jane);

        manager->execute_workday();
        manager->calculate_payroll();
        
        manager->execute_workday();
        manager->execute_workday();
        manager->calculate_payroll();

        manager->remove_employee(bob);
        manager->remove_employee(anna);

        bob->display_info();
        anna->display_info();
        delete bob;
        delete anna;

        manager->execute_workday();
        manager->calculate_payroll();

        manager->remove_employee(paul);
        manager->remove_employee(maria);
        manager->remove_employee(jack);
        manager->remove_employee(jane);
        paul->display_info();
        maria->display_info();
        jack->display_info();
        jane->display_info();

        delete paul;
        delete maria;
        delete jack;
        delete jane;
        delete manager;

    } catch (std::exception &err) {
        std::cerr << err.what() << std::endl;
    }
}
