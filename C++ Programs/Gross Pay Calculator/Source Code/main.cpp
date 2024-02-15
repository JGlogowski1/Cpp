//Title: ICA2 Gross Pay Problem
//Author: Joe Glogowski
//Date: October 12, 2023
//Filename: grossPay.cpp
//Purpose: ICA2 Gross Pay Problem

#include <iostream>
#include <list>
#include <string>
#include "class.h"

void userLoop(std::list<Employee>& employees);

int main() {
    std::list<Employee> employees;

    userLoop(employees);

    auto employeeIterator = employees.begin();

    while (employeeIterator != employees.end()) {
        std::cout << employeeIterator->getName() << " made $" << employeeIterator->getGrossPay() << std::endl;
        employeeIterator++;
    }
    return 0;
}

void userLoop(std::list<Employee>& employees) {
    char check;
    int employeeCounter = 1;

    do {
        Employee employee;
        std::string name;
        float hoursWorked, wage;

        std::cout << "Give me your name" << std::endl;
        std::cin >> name;
        employee.setName(name);

        std::cout << "How many hours did you work" << std::endl;
        std::cin >> hoursWorked;
        employee.setHoursWorked(hoursWorked);

        std::cout << "How much money do you make per hour" << std::endl;
        std::cin >> wage;
        employee.setWage(wage);

        employees.push_back(employee);

        std::cout << "Do you want to calculate another gross pay. y or n." << std::endl;
        std::cin >> check;

    } while (check == 'y');
}
